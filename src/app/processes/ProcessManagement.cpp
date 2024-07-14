#include "ProcessManagement.hpp" 
#include <iostream>
#include <cstring>
// #include <sys/file.h>
#include "../encryptDecrypt/Cryption.hpp"



ProcessManagement::ProcessManagement(){}

bool ProcessManagement::submitToQueue(unique_ptr<Task> task) {
	taskQueue.push(move(task));
}


void ProcessManagement::executeTask() {
	while(!taskQueue.empty()) {
		unique_ptr<Task> taskToExecute = move(taskQueue.front());
		taskQueue.pop();

		cout << "Executing task: " << taskToExecute->toString() << "\n";
		executeCryption(taskToExecute->toString());
	}
}