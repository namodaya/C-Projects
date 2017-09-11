// TaskManager.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TaskManager.h"
#include "FileHandler.h"

TaskManager::TaskManager()
{
}

TaskManager::~TaskManager()
{
}

void
TaskManager::addTask( std::wstring str )
{
	taskObj.setTaskName( str );
	fileObj.writeFile( taskObj.getTaskName() );
	std::wcout << "added Task: " << taskObj.getTaskName() << std::endl;
}

void
TaskManager::showTasks()
{
	std::vector< std::wstring > taskList = fileObj.readFile();
	int count = 0;
	std::wstring tmpTask = L"";
	for( int i = 0; i < taskList.size(); i++ )
	{
		std::wcout << i + 1 << L". " << taskList[i] << std::endl;
	}
}

void
TaskManager::finishTask( int taskNumber )
{
	fileObj.completeTask( taskNumber );
}
