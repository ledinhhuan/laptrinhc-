#include<iostream>
using namespace std;
class Date{
private:
	int day;
	int month;
	int year;
public:
	Date(void);
	~Date(void);
	Date(int,int,int);
	Date(const Date &);
	Date operator -(Date);
	
	friend istream& operator >>(istream &, Date &);
	friend ostream& operator <<(ostream &, Date &);
	
	bool operator >(Date);
	bool operator <(Date);
	bool operator ==(Date);
};

Date::Date(void){
	day = 1;
	month = 1;
	year = 1000;
}
Date::~Date(void){
}
Date::Date(int d, int m, int y){
	day = d;
	month = m;
	year = y;
}
Date::Date(const Date &d){
	day = d.day;
	month = d.month;
	year = d.year;
}
istream& operator >>(istream &is, Date &d){
	cout<<"Enter day: "; is>>d.day
	cout<<"Enter month: "; is>>d.month;
	cout<<"Enter year: "; is>>d.year;
	return is;
}
ostream& operator <<(ostream &os, Date &d){
	cout<<d.day<<" - "<<d.month<<" - "<<d.year<<endl;
	return os;
}
