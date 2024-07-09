#ifndef PROCESS_MANAGEMENT_HPP
#define PROCESS_MANAGEMENT_HPP

#include "Task.hpp"
#include <queue>
#include <memory>
using namespace std;

// header file for process management, where the function will be declared

class ProcessManagement {
	public:
		ProcessManagement();
		bool submitToQueue(unique_ptr<Task> task);
		void executeTask();
	
	private:
		queue<unique_ptr<Task>> taskQueue;
	 
};

#endif