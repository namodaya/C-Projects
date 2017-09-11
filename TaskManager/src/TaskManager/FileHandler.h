#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include "stdafx.h"

class FileHandler
{
public:
	FileHandler();
	~FileHandler();
	void writeFile( std::wstring taskName );
	std::vector< std::wstring > readFile();
	void completeTask( int taskNumber );

private:
	std::wifstream taskFile;

};

#endif