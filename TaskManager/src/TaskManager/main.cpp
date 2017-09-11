#include "stdafx.h"
#include "TaskManager.h"

void
ProcessOptions( int argc, _TCHAR* argv[] )
{
	using std::wstring;

	const wstring option( argv[1] );
	TaskManager taskManager = TaskManager();

	if ( option.compare( L"Insert") == 0 )
	{

		if( argc != 3 )
		{
			std::cout << "wrong task define" << std::endl;
		}
		else
		{
			taskManager.addTask( argv[2] );
		}

	}
	else if( option.compare( L"Display") == 0 )
	{
		if( argc != 2 )
		{
			std::cout << "wrong input" << std::endl;
		}
		else
		{
			taskManager.showTasks();
		}
	}
	else if( option.compare( L"Complete") == 0 )
	{
		if( argc != 2 )
		{
			std::cout << "wrong input" << std::endl;
		}
		else
		{
			taskManager.showTasks();
			int taskNumber;

			while( !( std::cin >> taskNumber ) )
			{
				std::cout << "Bad value!\n";
				std::cin.clear();
				std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n');
			}
			taskManager.finishTask( taskNumber );
		}
	}
	else
	{
		std::wcout << "Wrong argument" << std::endl;
	}
}

int _tmain( int argc, _TCHAR* argv[] )
{

	if( argc == 1 )
	{
		//showUsage();
		std::cout << "error" << std::endl;
		return 1;
	}

	try
	{
		ProcessOptions( argc, argv );
	}
	catch( const std::exception& e )
	{
		return 1;
	}
}