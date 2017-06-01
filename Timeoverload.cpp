#include<iostream>
using namespace std;
class Time{
	private:
		int hh;
		int mm;
		int ss;
	public:
		Time(void);
		~Time(void);
		Time(int,int,int);
		Time(const Time&);
		
		friend istream& operator >>(istream &, Time &);
		friend ostream& operator <<(ostream &, Time );
		
		Time operator +(Time);
		Time operator -(Time);
		
		bool operator >(Time);
		bool operator <(Time);
		bool operator ==(Time);
};
Time::Time(void){
	hh = 0; 
	mm = 0;
	ss = 0;
}
Time::~Time(void){
	
}
Time::Time(int h, int m, int s){
	hh = (h>=0 && h<24) ? h : 0;
    mm = (m>=0 && m<60) ? m : 0;
    ss = (s>=0 && s<60) ? s : 0;
}
Time::Time(const Time &t){
	hh = t.hh;
	mm = t.mm;
	ss = t.ss;
}

istream& operator >>(istream &is, Time &t){
	cout<<"Enter hour: : "; is>>t.hh;
	cout<<"Enter minute: "; is>>t.mm;
	cout<<"Enter second: "; is>>t.ss;
	return is;
}
ostream& operator <<(ostream &os, Time t){
	os<<t.hh<<" : "<<t.mm<<" : "<<t.mm<<endl;
	return os;
}

Time Time::operator +(Time t1){
Time t;  
 	int a,b;  
 	a = ss + t1.ss;  
 	t.ss = a%60;  
 	b = (a/60) + mm + t1.mm;  
 	t.mm = b % 60;  
 	t.hh = (b/60) + hh + t1.hh;  
 	t.hh = t.hh % 12;  
 	return t; 
}
Time Time::operator -(Time t1){
	Time t;
	int a, b, s;
	a = t.hh * 3600 + t.mm * 60 + t.ss;
	b = t1.hh * 3600 + t1.mm * 60 + t1.ss;
	s = b - a;
	t.ss = s % 3600 % 60;
	t.mm = s % 3600 / 60;
	t.hh = s / 3600;
	
	
	return t;
}

bool Time::operator ==(Time t){
	return (hh == t.hh && mm == t.mm && ss == t.mm);
}
bool Time::operator <(Time t){
	return (hh < t.hh && mm < t.mm && ss < t.mm);
}
bool Time::operator >(Time t){
	return (hh > t.hh && mm > t.mm && ss > t.mm);
}

int main(){
	Time t1, t2;
	cout<<"-----Time t1-----"<<endl;
	cin>>t1;
	cout<<t1<<endl;
	cout<<"-----Time t2-----"<<endl;
	cin>>t2;
	cout<<t2<<endl;
	
	cout<<"\nt1 + t2 = "<<t1 + t2<<endl;
	cout<<"\nt1 - t2 = "<<t1 - t2<<endl;
	if(t1 > t2)
		cout<<"\nt1 > t2"<<endl;
	else if(t1 < t2)
		cout<<"\nt1 < t2"<<endl;
	else
		cout<<"\nt1 = t2"<<endl;
	return 0;
	
}

