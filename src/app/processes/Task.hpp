#ifndef TASK_HPP
#define TASK_HPP 

#include <string>
#include <iostream>
#include "../fileHandling/IO.hpp"
#include <sstream>

/* 
? Type of action to be performed on the file 
*/
enum class Action {
	ENCRYPT,
	DECRYPT
};

// this task will be pushed in the queue to be performed one by one
struct Task {
	string filePath;
	fstream f_stream;
	Action action;

	// initialise the construtor and store values
	Task (fstream &&stream, Action act, string filePath): f_stream(move(stream)), action(act), filePath(filePath){}

	// serialise 
	// ! create a stringstream with file path and action to be performed
	string toString() {
		ostringstream oss;
		oss<<filePath<<","<<(action==Action::ENCRYPT ? "ENCRYPT" : "DECRYPT");

		return oss.str();
	}

	// deserialise 
	/*
	? we will extract the file path and action from the output string stream
	! throw error if cannot open the file or deserialisation is not possible 
	*/
	static Task fromString(const string& taskData) {
		istringstream iss(taskData);

		string filePath;
		string actionStr;

		if (getline(iss, filePath, ',') && getline(iss, actionStr)) {
			Action action = (actionStr=="ENCRYPT" ? Action::ENCRYPT : Action::DECRYPT);
			IO io(filePath);
			fstream f_stream = move(io.getFileStream());

			if (f_stream.is_open()) {
				return Task(move(f_stream), action, filePath);
			} else {
				throw runtime_error("Failed to open file: "+ filePath);
			}
		} else throw runtime_error("Invalid task data format");
	}
};

#endif