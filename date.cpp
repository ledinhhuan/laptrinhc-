#include<iostream>
using namespace std;
class Date{
private:
	int day;
	int month;
	int year;
	int daysIn(int);
public:
	Date();
	int getDay();
	void setDay(int);
	int getMonth();
	void setMonth(int);
	int getYear();
	void setYear(int);
	void normalize();
	void advance(int , int, int);
	void print();
};
Date::Date(){
	day = 1;
	month = 1;
	year = 2000;
}
int Date::getDay(){
	return day;
}
void Date::setDay(int d){
	year = d;
}
int Date::getMonth(){
	return month;
}
void Date::setMonth(int m){
	month = m;
}
int Date::getYear(){
	return year;
}
void Date::setYear(int y){
	year = y;
}
int Date::daysIn(int m){
	int Months[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	return Months[m];
}
void Date::normalize(){
	if(day < 1)  day = 1;
	if(day > daysIn(month)) day = daysIn(month);
	if(month < 1) month = 1;
	if(month > 12) month = 12;
	if(year < 1) year = 2000;
}
void Date::print(){
	cout<<"Ngay "<<day<<" / "<<month<<" / "<<year<<endl;
}
void Date::advance(int d, int m, int y){
	day += d;
	while(day > daysIn(month) ){
		day = day - daysIn(month);
		month++;
		if(month > 12){
			year++;
			month -= 12;
		}	
	}
	month += m;
	while(month > 12){
		year++;
		month -= 12;
	}
	year += y;
}
int main(){
	Date date1;
	date1.print();
	
	Date date2;
	date2.setDay(1);
	date2.setMonth(5);
	date2.setYear(2016);
	date2.print();
	date2.normalize();
	date2.advance(365,0,0);
	date2.print();
	return 0;
}
