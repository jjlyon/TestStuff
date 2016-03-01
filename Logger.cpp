// LogStuff.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <sstream>
#include <string>
#include <ctime>

class Logger
{
public:
	Logger() = delete;
	virtual ~Logger() = delete;

	static void Logger::logMessageWithStandardString(std::string msg)
	{
		std::clog << msg << std::endl;
	}

	static void Logger::logMessageWithStringReference(const std::string &msg)
	{
		std::clog << msg << std::endl;
	}

	static std::stringstream& write()
	{
		return logStream;
	}

	static void logMessageWithStringstream()
	{
		std::clog << logStream.str() << std::endl;
		logStream.str(std::string());
	}

	static void logMessageWithMoveString(std::string &&msg)
	{
		std::clog << msg << std::endl;
	}

private:
	static std::stringstream logStream;

};

std::stringstream Logger::logStream;

int main()
{
	std::clock_t t;

	t = std::clock();
	for (int i = 0; i < 10000; i++)
	{
		std::string msg = "message" + std::to_string(1);
		Logger::logMessageWithStandardString(msg);
	}
	t = std::clock() - t;
	std::cout << "Logging with logMessageWithStandardString took: " << t << std::endl;

	t = std::clock();
	for (int i = 0; i < 10000; i++)
	{
		std::string msg = "message" + std::to_string(1);
		Logger::logMessageWithStringReference(msg);
	}
	t = std::clock() - t;
	std::cout << "Logging with logMessageWithStringReference took: " << t << std::endl;

	t = std::clock();
	for (int i = 0; i < 10000; i++)
	{
		Logger::write() << "Message" << 1;
		Logger::logMessageWithStringstream();
	}
	t = std::clock() - t;

	std::cout << "Logging with logMessageWithStringstream took: " << t << std::endl;

	t = std::clock();
	for (int i = 0; i < 10000; i++)
	{
		Logger::logMessageWithMoveString("Message" + std::to_string(1));
	}
	t = std::clock() - t;

	std::cout << "Logging with logMessageWithMoveString took: " << t << std::endl;

	system("pause");

	return 0;
}

