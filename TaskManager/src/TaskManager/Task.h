#ifndef TASK_H
#define TASK_H

#include "stdafx.h"

class Task
{
public:
	Task();
	~Task();
	void setTaskName( std::wstring name );
	std::wstring getTaskName();

private:
	std::wstring taskName;

};

#endif