#pragma once

#include <string>
#include <vector>

struct Argument
{
	std::string key;
	std::string value;
};

typedef std::vector<Argument> Arguments;

// Parses the command line into a usable list
// valid syntax
//	-h
//	-help
//	-s=something
//	--option=another
//	--------fish=salmon
class CommandArgs
{
public:
	Arguments Parse(std::vector<std::string> args);
private:
	Argument ExtractArgument(std::string arg);
	std::string& ltrim(std::string& s);
	std::string& rtrim(std::string& s);
	std::string& trim(std::string& s);
};
