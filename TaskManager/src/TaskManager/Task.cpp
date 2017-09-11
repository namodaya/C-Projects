#include "stdafx.h"
#include "Task.h"

Task::Task()
{
}

Task::~Task()
{
}

void
Task::setTaskName( std::wstring name )
{
	taskName = name;
}

std::wstring
Task::getTaskName()
{
	return taskName;
}