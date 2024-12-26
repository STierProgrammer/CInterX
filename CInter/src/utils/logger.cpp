#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <ctime>

enum LogLevel {
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	CRITICAL
};

class Logger {
public:
	Logger(const std::string& filename)
	{
		logFile.open(filename, std::ios::app);

		if (!logFile.is_open()) {
			std::cerr << "Error opening log file!" << std::endl;
		}
	}

	~Logger() {
		logFile.close();
	}

	void log(LogLevel level, const std::string& message)
	{

		std::ostringstream logEntry;

		logEntry << "[" << levelToString(level) << "] " << ": " << message << std::endl;

		std::cout << logEntry.str();

		if (logFile.is_open()) {
			logFile << logEntry.str();
			logFile.flush();
		}
	}

private:
	std::ofstream logFile;

	std::string levelToString(LogLevel level) {
		switch (level) {
		case DEBUG:
			return "DEBUG";
		case INFO:
			return "INFO";
		case WARNING:
			return "WARNING";
		case ERROR:
			return "ERROR";
		case CRITICAL:
			return "CRITICAL";
		default:
			return "UNKNOWN";
		}
	}
};