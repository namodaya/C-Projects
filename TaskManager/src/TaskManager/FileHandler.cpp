#include "stdafx.h"
#include "FileHandler.h"

FileHandler::FileHandler()
{
}

FileHandler::~FileHandler()
{
}

void
FileHandler::writeFile( std::wstring taskName )
{
	std::wofstream taskFile;
	taskFile.open( TASKFILE, std::ios_base::app );

	taskFile << taskName << "\n";
}

std::vector< std::wstring >
FileHandler::readFile()
{
	std::wifstream taskFile;
	std::vector< std::wstring > tasks;
	taskFile.open( TASKFILE, std::ios::binary );

    std::wstring value;
	while ( taskFile.good() )
	{
		getline ( taskFile, value );
		if(value.empty())
			break;
		tasks.push_back( value );
	}

	return tasks;
}

void
FileHandler::completeTask( int taskNumber )
{
	std::wifstream taskFile;
	taskFile.open( TASKFILE );
	int i = 1;
	std::wstring line;

    std::wofstream tempFile;
    tempFile.open( "tempFile.txt" );

	while ( std::getline( taskFile, line))
	{
		if( i != taskNumber )
		{
			tempFile << line << L"\n";
		}
		i++;
	}
	tempFile.close();
    taskFile.close();
	remove( TASKFILE );
	rename( "tempFile.txt", TASKFILE );
}