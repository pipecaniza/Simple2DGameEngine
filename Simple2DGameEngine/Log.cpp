#include "Log.h"
#include <iostream>


void Log::WriteConsoleLog(std::string lineLog)
{
	std::cout << "LogSystem: " << lineLog << '\n';
}
