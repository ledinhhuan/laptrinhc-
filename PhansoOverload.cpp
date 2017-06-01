#include<iostream>
using namespace std;
class Phanso{
	private:
		int tuso;
		int mauso;
	public:
		Phanso(void);//ham dung mac dinh
		~Phanso(void); //ham huy
		Phanso(int, int); // ham dung tham so
		Phanso(const Phanso &); //ham dung sao chep
		//phanso +-*/ Phanso
		Phanso operator +(Phanso);
		Phanso operator -(Phanso);
		Phanso operator *(Phanso);
		Phanso operator /(Phanso);
		//so sanh phan so >, <, >=, == voi phan so
		bool operator >(Phanso);
		bool operator <(Phanso);
		bool operator >=(Phanso);
		bool operator ==(Phanso);
		
		friend istream& operator >> (istream &, Phanso &);
		friend ostream& operator << (ostream &, Phanso);	
};

Phanso::Phanso(void){
	tuso = 0;
	mauso = 1;
}
Phanso::~Phanso(){
}
Phanso::Phanso(int ts, int ms) {
	tuso = ts;
	mauso = ms;
}
Phanso::Phanso(const Phanso &ps) {
	tuso = ps.tuso;
	mauso = ps.mauso;
}

istream& operator >>(istream &is, Phanso &ps) {
	cout << "Nhap vao tu so: ";
	is >> ps.tuso;
	do {
		cout << "Nhap vao mau so: ";
		is >> ps.mauso;
		if (ps.mauso == 0)
			cout << "\nMau so khong hop le, xin nhap lai.";
	} while (ps.mauso == 0);
	return is;
}
ostream& operator <<(ostream &os, Phanso ps) {
	os << ps.tuso << "/" << ps.mauso << endl;;
	return os;
}

Phanso Phanso::operator+(Phanso ps) {
	Phanso Tong;
	Tong.tuso = tuso * ps.mauso + mauso * ps.tuso;
	Tong.mauso = mauso * ps.mauso;
	return Tong;
}
Phanso Phanso::operator-(Phanso ps) {
	Phanso Hieu;
	Hieu.tuso = tuso * ps.mauso - mauso * ps.tuso;
	Hieu.mauso = mauso * ps.mauso;
	return Hieu;
}
Phanso Phanso::operator*(Phanso ps) {
	Phanso Tich;
	Tich.tuso = tuso  * ps.tuso;
	Tich.mauso = mauso * ps.mauso;
	return Tich;
}
Phanso Phanso::operator/(Phanso ps) {
	/*Phanso Thuong;
	Thuong.tuso = tuso  * ps.mauso;
	Thuong.mauso = mauso * ps.tuso;
	return Thuong;
	*/

	Phanso NghichDao(ps.mauso, ps.tuso);
	return *this*NghichDao;
	
}

bool Phanso::operator>(Phanso ps) {
	/*cach 1: 
	/*if ((float)tuso / mauso > (float)ps.tuso / ps.mauso)
		return true;
	return false;

	cach 2:
	return (float)tuso / mauso > (float)ps.tuso / ps.mauso ? true : false;*/

	return (float)tuso / mauso > (float)ps.tuso / ps.mauso;

}
bool Phanso::operator<(Phanso ps) {
	return (float)tuso / mauso < (float)ps.tuso / ps.mauso;
}
bool Phanso::operator>=(Phanso ps) {
	return (float)tuso / mauso >= (float)ps.tuso / ps.mauso;
}
bool Phanso::operator==(Phanso ps) {
	return (float)tuso / mauso == (float)ps.tuso / ps.mauso;
}

int main(){
	Phanso ps1, ps2;
	cout << "---Nhap ps1--- "<<endl;
	cin >> ps1;
	cout << ps1;

	cout << "---Nhap ps2--- "<<endl;
	cin >> ps2;
	cout << ps2;

	cout << "\nps1 + ps2 = " << ps1 + ps2;
	cout << "\nps1 - ps2 = " << ps1 - ps2;
	cout << "\nps1 * ps2 = " << ps1 * ps2;
	cout << "\nps1 / ps2 = " << ps1 / ps2;
	
	if (ps1 > ps2)
		cout << "\nps1 > ps2 "<<endl;
	else if (ps1 < ps2)
		cout << "\nps1 < ps2"<<endl;
	else
		cout << "\nps1 = ps2"<<endl;
}
