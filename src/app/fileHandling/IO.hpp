#ifndef IO_HPP
#define IO_HPP

#include <fstream> 
#include <string>
#include <iostream>
using namespace std;

class IO {
	public:
		IO(const string& file_path); // pasing the file path by reference
		~IO(); // distructor 
		fstream getFileStream(); // return the value stored in file_stream // getter

	private:
		fstream file_stream; // this is the setter, stores the file stream while reading
};

#endif