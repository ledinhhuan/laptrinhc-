#include<iostream>
#include<string>
using namespace std;
class Circle{
private:
	double radius;
	string color;
public:
	//contructor with default values for data members
	Circle(double r = 1.0, string c = "red"){
		radius = r;
		color = c;
	}
	double getRadius(){
		return radius;
	}
	string getColor(){
		return color;
	}
	double getArea(){
		return radius*radius*3.1416;
	}
};
int main(){
	Circle c1(1.2,"blue");
	cout<<"radius: "<<c1.getRadius()<<" Area: "<<c1.getArea()<<" color: "<<c1.getColor()<<endl;
}
