#include <iostream>
#include <string>

class Logger {
public:
	enum class LoggingLevel {
		DEBUG, INFO, WARNING, ERROR, CRITICAL
	};

	virtual void debug(const std::string &msg) = 0;
	virtual void info(const std::string &msg) = 0;
	virtual void warning(const std::string &msg) = 0;
	virtual void error(const std::string &msg) = 0;
	virtual void critical(const std::string &msg) = 0;

	virtual void configLevel(LoggingLevel newlevel) = 0;
	virtual void configFormat(const std::string &newformat) = 0;
	virtual void configFormat(std::string &&newformat) = 0;

	virtual ~Logger() {}
};


// Where to print logs 
// In which format to print
//
// Which logging levels to print
// std::string and c-string
// Events

class ConsoleLogger : public Logger{
private:
	std::string format;
	LoggingLevel level;
public:
	void debug(const std::string &msg) override {
		std::cout << "Debug: " << msg << '\n';
	}

	void info(const std::string &msg) override {
		std::cout << "Info: " << msg << '\n';	
	}

	void warning(const std::string &msg) override {
		std::cout << "Warning: " << msg << '\n';	
	}
	
	void error(const std::string &msg) override {
		std::cout << "Error: " << msg << '\n';
	}

	void critical(const std::string &msg) override {
		std::cout << "Critical: " << msg << '\n';
	}
	
	void configLevel(LoggingLevel newlevel) override {
		level = newlevel;
	}

	void configFormat(const std::string &newformat) {
		format = newformat;
		std::cout << "Config lvalue\n";
	}

	void configFormat(std::string &&newformat) {
		format = newformat;
		std::cout << "Config rvalue\n";
	}

	~ConsoleLogger() {}
};

