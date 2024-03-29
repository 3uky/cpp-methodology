# pragma once

#include <string>
#include <chrono>
#include <format>
#include <iostream>

#pragma warning(disable : 4996)

using namespace std;

namespace network
{

class WinsockLogger
{
public:
	static void Log(std::string message)
	{
		cout << std::format("{} (time {})\n", message, GetCurrentTimestamp());
	}

private:
	static std::string GetCurrentTimestamp()
	{
		using namespace std::chrono;
		using clock = system_clock;

		const auto current_time_point{ clock::now() };
		const auto current_time{ clock::to_time_t(current_time_point) };
		const auto current_localtime{ *std::localtime(&current_time) };
		const auto current_time_since_epoch{ current_time_point.time_since_epoch() };
		const auto current_milliseconds{ duration_cast<milliseconds> (current_time_since_epoch).count() % 1000 };

		std::ostringstream stream;
		stream << std::put_time(&current_localtime, "%T") << "." << std::setw(3) << std::setfill('0') << current_milliseconds;
		return stream.str();
	}
};

}
