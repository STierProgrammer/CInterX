#ifndef CINTER_LOGGER_H
#define CINTER_LOGGER_H

#include <iostream>
#include <fstream>
#include <sstream>

enum LogLevel {
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	CRITICAL
};

class Logger {
public:
	Logger(const std::string& filename);

	~Logger();

	void log(LogLevel level, const std::string& message);
private:
	std::ofstream logFile;

	std::string levelToString(LogLevel level);
};

#endif // !CINTER_LOGGER_H