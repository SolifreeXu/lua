#include "stdafx.h"

#include "Timer.h"

Timer::Timer(const std::function<void()> &callback, \
	const int timeInterval, const int accuracy)
{
	// ʹ�ñ�׼���placement new���ڹ��캯���У��ڶ��ε����Լ��Ĺ��캯����\
	�������Ѿ�����õ��ڴ���ִ�У������Ƿ����µ��ڴ�
	new (this)Timer(accuracy);
	setTimer(callback, timeInterval);
}

bool Timer::setTimer(const std::function<void()> &callback, const int timeInterval)
{
	if (!bClosed)
		return false;
	bClosed = false;
	this->timeInterval = timeInterval;
	this->callback = callback;
	thread = std::thread(&Timer::execute, this);
	return !(bClosed = false);
}

void Timer::killTimer()
{
	bClosed = true;
	thread.join();
}

void Timer::execute()
{
	while (!bClosed)
	{
		auto begin = std::chrono::steady_clock::now();
		while (std::chrono::steady_clock::now() - begin < std::chrono::milliseconds(timeInterval))
			std::this_thread::sleep_for(std::chrono::milliseconds(accuracy));
		if (!bClosed)
			callback();
	}
}