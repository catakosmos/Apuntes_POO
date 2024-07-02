#include "Clock.h"

Clock::Clock(int pHour, int pMinute, int pSecond) {
	hour = pHour;
	minute = pMinute;
	second = pSecond;
}

void Clock::setHour(int pHour) {
	hour = pHour;
}

void Clock::setMinute(int pMinute) {
	minute = pMinute;
}

void Clock::setSecond(int pSecond) {
	second = pSecond;
}

void Clock::tick()
{
	if (second < 59) {
		second++;
	}
	else if (minute < 59)
	{
		minute++;
		second = 0;
	}
	else if (hour < 23)
	{
		hour++;
		minute = 0;
		second = 0;
	}
	else 
    {
		hour = 0;
		minute = 0;
		second = 0;
	}
	
}
void Clock::showTime() {
	cout << endl << hour << " " << minute <<" " << second << endl <<endl;
}
