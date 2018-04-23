#pragma once

class Time
{
private:
	long long totalSeconds;
	long long hours;
	int minutes;
	int seconds;
public:
	Time();
	Time(const long long &seconds);
	Time(const long long &hours, const int &minutes, const int &seconds);
	bool setTime(const long long &seconds);
	long long getTime()const
	{
		return totalSeconds;
	}
	bool setHours(const long long &hours);
	long long getHours()const
	{
		return hours;
	}
	bool setMinutes(const int &minutes);
	int getMinutes()const
	{
		return minutes;
	}
	bool setSeconds(const int &seconds);
	int getSeconds()const
	{
		return seconds;
	}
	Time operator+(const Time &time);
	Time operator-(const Time &time);
	bool operator>(const Time &time);
	bool operator>=(const Time &time);
	bool operator<(const Time &time);
	bool operator<=(const Time &time);
	bool operator==(const Time &time);
};