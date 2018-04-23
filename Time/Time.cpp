#include "Time.h"

#include <iostream>
#include <ctime>

Time::Time()
{
	time_t time = std::time(NULL);
	struct tm *localTime = std::localtime(&time);
	hours = localTime->tm_hour;
	minutes = localTime->tm_min;
	seconds = localTime->tm_sec;
	totalSeconds = hours * 3600 + minutes * 60 + seconds;
}

Time::Time(const long long &seconds)
{
	if (!setTime(seconds))
		new(this)Time();
}

Time::Time(const long long &hours, const int &minutes, const int &seconds)
{
	if (hours < 0
		&& (minutes < 0 || minutes >= 60)
		&& (seconds < 0 || seconds >= 60))
		new(this)Time();
	else
	{
		this->hours = hours;
		this->minutes = minutes;
		this->seconds = seconds;
		this->totalSeconds = this->hours * 3600 + this->minutes * 60 + this->seconds;
	}
}

bool Time::setTime(const long long &seconds)
{
	if (seconds < 0)
		return false;
	this->totalSeconds = seconds;
	this->hours = this->totalSeconds / 3600;
	this->minutes = this->totalSeconds / 60 % 60;
	this->seconds = this->totalSeconds % 60;
	return true;
}

bool Time::setHours(const long long &hours)
{
	if (hours < 0)
		return false;
	this->totalSeconds += (this->hours - hours) * 3600;
	this->hours = hours;
	return true;
}

bool Time::setMinutes(const int &minutes)
{
	if (minutes < 0 || minutes >= 60)
		return false;
	this->totalSeconds += (this->minutes - minutes) * 60;
	this->minutes = minutes;
	return true;
}

bool Time::setSeconds(const int &seconds)
{
	if (seconds < 0 || seconds >= 60)
		return false;
	this->totalSeconds += (this->seconds - seconds);
	this->seconds = seconds;
	return true;
}

Time Time::operator+(const Time &time)
{
	return Time(this->getTime() + time.getTime());
}

Time Time::operator-(const Time &time)
{
	return Time(this->getTime() - time.getTime());
}

bool Time::operator>(const Time &time)
{
	return this->getTime() > time.getTime();
}

bool Time::operator>=(const Time &time)
{
	return this->getTime() >= time.getTime();
}

bool Time::operator<(const Time &time)
{
	return this->getTime() < time.getTime();
}

bool Time::operator<=(const Time &time)
{
	return this->getTime() <= time.getTime();
}

bool Time::operator==(const Time &time)
{
	return this->getTime() == time.getTime();
}