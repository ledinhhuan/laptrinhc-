#include<iostream>
using namespace std;
class RGB{
	private:
		int red;
		int green;
		int blue;
	public:
		int getRed();
		void setRed(int);
};

int RGB::getRed(){
	return red;
}
void RGB::setRed(int r){
	if(r < 0 || r > 255){
		cout<<"gia tri phai tu 0..255";
		red = 0;
	}else
		red = r;
}

int main(){
	RGB color1;
	color1.setRed(250);
	cout<<color1.getRed();
}
