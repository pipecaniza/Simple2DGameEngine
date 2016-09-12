#pragma once
#include <string>

class Log
{
public:
	static void WriteConsoleLog(std::string lineLog);

private:
	Log() {};
	~Log() {};
};

