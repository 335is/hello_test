#include <iostream>

#include "cmdargs.h"

using namespace std;

Arguments CommandArgs::Parse(std::vector<std::string> args)
{
	Arguments arguments;

	for (auto& it : args)
	{
		// trim any leading or trailing whitespace
		auto s = trim(it);

		// skip if empty
		if (s.empty())
		{
			continue;
		}

		// skip if entire argument is only dashes
		auto p = s.find_first_not_of('-');
		if (p == std::string::npos)
		{
			continue;
		}

		// trim leading dashes
		s.erase(0, std::min(p, s.size() - 1));

		// extract key,value
		auto argument = ExtractArgument(s);
		arguments.push_back(argument);
	}

	return arguments;
}

Argument CommandArgs::ExtractArgument(std::string arg)
{
	// split key from value, if any
	std::string key;
	std::string value;
	std::string equals("=");
	auto pos = arg.find(equals);
	if (pos == std::string::npos)
	{
		key = arg;
	}
	else
	{
		key = arg.substr(0, pos);
		value = arg.substr(pos + equals.length());
	}

	Argument argument = { key, value };

	return argument;
}

const char* whitespace = " \t\n\r\f\v";

// trim from left
std::string& CommandArgs::ltrim(std::string& s)
{
	s.erase(0, s.find_first_not_of(whitespace));
	return s;
}

// trim from right
std::string& CommandArgs::rtrim(std::string& s)
{
	s.erase(s.find_last_not_of(whitespace) + 1);
	return s;
}

// trim from left & right
std::string& CommandArgs::trim(std::string& s)
{
	return ltrim(rtrim(s));
}