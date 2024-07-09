#include <iostream> 
#include <string>
#include <fstream>
#include "IO.hpp"
#include <sstream> 

/*
? Here we will read the values in the '.env' file 
*/

class ReadEnv {
	public:
		string getEnv() {
			string env_path = ".env";
			IO io(env_path);
			fstream f_stream = io.getFileStream();

			stringstream buffer;
			buffer << f_stream.rdbuf();
			string data = buffer.str();
			return data;
		} 
};