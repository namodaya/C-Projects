#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "Task.h"
#include "FileHandler.h"

class TaskManager
{
public:
	TaskManager();
	~TaskManager();
	void addTask( std::wstring str );
	void showTasks();
	void finishTask( int taskNumber );

private:
	Task taskObj;
	FileHandler fileObj;

};

#endif