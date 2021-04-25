#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iomanip>


struct Zegar{
	int hour;
	int minute;
	int second;
	
	Zegar(int hour, int minute, int second);
	std::string toString(std::string);
	void next_hour();
	void next_minute();
	void next_second();
    std::string time_of_day();
};

Zegar::Zegar(int h, int min, int sec){
		hour = h;
		minute = min;
		second = sec;
}

auto main() -> int{
	
	auto zegar = Zegar(23, 59, 59);
	std::cout << zegar.toString(zegar.time_of_day());

	zegar.next_second();
    
    for (auto i = 0; i < 10; i++){
        zegar.next_hour();
    }
	
	std::cout << zegar.toString(zegar.time_of_day());
	return 0;
}

std::string Zegar::toString(std:: string time_of_day){

	std::ostringstream out;
	
    out << std::setw(2) << std::setfill('0') << hour << ":";
	out << std::setw(2) << std::setfill('0') << minute << ":";
	out << std::setw(2) << std::setfill('0') << second << " " << time_of_day << "\n";
	
	return out.str();
}

void Zegar::next_hour(){
		hour++;
		if(hour == 24){
			hour = 0;
		}
}

void Zegar::next_minute(){
	minute++;
	if(minute == 60){
			minute = 0;
			next_hour();
	}
}

void Zegar::next_second(){
	second++;
	if(second == 60){
		second = 0;
		next_minute();
	}
			
}

std::string Zegar::time_of_day(){
	if(hour >= 21 || hour < 5)
		return "noc";
	else if(hour >= 5 && hour < 12)
		return "rano";
	else if(hour >= 12 && hour < 18)
		return "dzien";
	else
		return "wieczor";
}