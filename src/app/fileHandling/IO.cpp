#include <iostream>
#include "IO.hpp"
#include <fstream>
using namespace std;

/*
! Implementing the constructor of the IO.hpp file 
? The method and attributes are declared in the IO.hpp and are defined here
*/

IO::IO(const string &file_path) {
	// open the file, read the file and store it in file_stream
	file_stream.open(file_path, ios::in | ios::out | ios::binary);

	// !  if there is some problem in opening file, raise issue on console  
	if (!file_stream.is_open()) {
		cout << "Cannot open file: " << file_path << "\n";
	}
}

// implement the getter function, by moving the ownership of the file
fstream IO::getFileStream() {
	return move(file_stream);
}

// implement the distructor of the class, to close the file opened, 
IO::~IO() {
	if (file_stream.is_open()) {
		file_stream.close();
	}
}