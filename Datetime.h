#ifndef DATETIME_H
#define DATETIME_H

#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

class datetime{
	private:
		int day, month, year;
		int hour, minute;
	public:
		datetime();
		datetime(int, int, int, int, int);
		
		void load_from_file(ifstream &);
		void save_to_file(ofstream &);
		
		int get_day();
		int get_month();
		int get_year();
		int get_hour();
		int get_minute();
		
		void set_time(int, int, int, int, int);
		
		void time_now();
		time_t convert_time();
		bool check_time();
		void show_datetime();
};

datetime::datetime() : day(0), month(0), year(0), hour(0), minute(0){}

datetime::datetime(int day, int month, int year, int hour, int minute) :
	day(day), month(month), year(year), hour(hour), minute(minute){}


void datetime::load_from_file(ifstream &file){
	file >> day;
    file.ignore(1, '/');
    file >> month;
    file.ignore(1, '/');
    file >> year;
    file.ignore(1, ' ');
    file >> hour;
    file.ignore(1, ':');
    file >> minute;
    file.ignore(1, '|');
}

void datetime::save_to_file(ofstream &file){
	file << day << "/"
		 << month << "/"
		 << year << " "
		 << hour << ":"
		 << minute << "|";
}


int datetime::get_day(){
	return day;
}

int datetime::get_month(){
	return month;
}

int datetime::get_year(){
	return year;
}

int datetime::get_hour(){
	return hour;
}

int datetime::get_minute(){
	return minute;
}


void datetime::set_time(int day, int month, int year, int hour, int minute){
	this->day = day;
	this->month =month;
	this->year = year;
	this->hour = hour;
	this->minute = minute;
}


void datetime::time_now(){
	time_t now = time(0);
    tm* ltm = localtime(&now);

    day = ltm->tm_mday;    
    month = 1 + ltm->tm_mon;    
    year = 1900 + ltm->tm_year;    
    hour = ltm->tm_hour;        
    minute = ltm->tm_min;
}

time_t datetime::convert_time(){
	tm timeStruct = {0};

    timeStruct.tm_year = year - 1900; 
    timeStruct.tm_mon = month - 1;  
    timeStruct.tm_mday = day;   
    timeStruct.tm_hour = hour; 
    timeStruct.tm_min = minute;       
    timeStruct.tm_sec = 0;     

    return mktime(&timeStruct);
}

bool datetime::check_time(){
	tm timeStruct = {0};

    timeStruct.tm_year = year - 1900; 
    timeStruct.tm_mon = month - 1;   
    timeStruct.tm_mday = day;    
    timeStruct.tm_hour = hour;     
    timeStruct.tm_min = minute;  
    timeStruct.tm_sec = 0;           
    time_t dt = mktime(&timeStruct);
    if (dt == -1) 
        return false;
    if (timeStruct.tm_mday != day || timeStruct.tm_mon != month - 1 || (timeStruct.tm_year != year - 1900))
        return false;
    return true;
}

void datetime::show_datetime(){
	cout << setw(2) << day << "/" 
		 << setw(2) << month << "/" 
		 << year << " "
		 << setw(2) << hour << ":" 
		 << setw(2) << minute << "   ";
}

#endif //DATETIME_H
