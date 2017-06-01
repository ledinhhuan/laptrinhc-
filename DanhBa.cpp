#include<iostream>
#include<vector>
using namespace std;
class Nguoi{
private:
	string HoTen;
	int NamSinh;
	string SoDienThoai;
	string Email;
public:
	Nguoi();
	string getHoTen();
	void setHoTen(string);
	
	int getNamSinh();
	void setNamSinh(int);
	
	string getSoDienThoai();
	void setSoDienThoai(string);
	
	string getEmail();
	void setEmail(string);	
};
class DanhBa{
private:
	int SoNguoi;
	vector<Nguoi> DanhSach;
public:
	
};
