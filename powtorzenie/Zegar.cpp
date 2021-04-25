#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

struct Zegar{
	int hour;
	int minute;
	int second;
	
	Zegar(int hour, int minute, int second);
	std::string toString();
	void next_hour();
	void next_minute();
	void next_second();
};

Zegar::Zegar(int h, int min, int sec){
		hour = h;
		minute = min;
		second = sec;
}

auto main() -> int{

	auto zegar = Zegar(23, 59, 59);
	std::cout << zegar.toString();
	std::cout << "\n";
	
	zegar.next_second();
	
	std::cout<<zegar.toString();
	std::cout<<"\n";
	
	return 0;
}

std::string Zegar::toString(){

	std::ostringstream out;
	
    out << std::setw(2) << std::setfill('0') << hour << ":";
	out << std::setw(2) << std::setfill('0') << minute << ":";
	out << std::setw(2) << std::setfill('0') << second;
	
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