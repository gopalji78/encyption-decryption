#include <iostream>
#include "Cryption.hpp"
using namespace std;

// takes the number of arguments and then the argument in the form of array 
// execute the cryption directly 
int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr<< "Usage: ./cryption <task_data" << "\n";
        return 1;
    }
    executeCryption(argv[1]);
    return 0;
}