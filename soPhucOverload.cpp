#include<iostream>
using namespace std;
class Sophuc{
private:
	float phanThuc;
	float phanAo;
public:
	Sophuc();
	~Sophuc();
	Sophuc(float,float);
	Sophuc(const Sophuc &);
	
	Sophuc operator +(Sophuc);
	Sophuc operator -(Sophuc);
	Sophuc operator *(Sophuc);
	Sophuc operator /(Sophuc);
	
	friend istream& operator>>(istream &, Sophuc &);
	friend ostream& operator<<(ostream &, Sophuc );
	
};

Sophuc::Sophuc(){
	phanThuc = 0; 
	phanAo = 0;
}
Sophuc::~Sophuc(){
	
}
Sophuc::Sophuc(float t, float a){
	phanThuc = t;
	phanAo = a;
}
Sophuc::Sophuc(const Sophuc &sp){
	phanThuc = sp.phanThuc;
	phanAo = sp.phanAo;
}

istream& operator>>(istream &is, Sophuc &sp){
	cout<<"Nhap phan thuc: "; 
	is>>sp.phanThuc;
	cout<<"Nhap phan ao: ";
	is>>sp.phanAo;
	return is;
}
ostream& operator<<(ostream &os, Sophuc sp){
	cout<<sp.phanThuc<<" + "<<"("<<sp.phanAo<<")i "<<endl;
}
Sophuc Sophuc::operator +(Sophuc sp){
	Sophuc Tong;
	Tong.phanThuc = phanThuc + sp.phanThuc;
	Tong.phanAo = phanAo + sp.phanAo;
	return Tong;
}
Sophuc Sophuc::operator -(Sophuc sp){
	Sophuc Hieu;
	Hieu.phanThuc = phanThuc - sp.phanThuc;
	Hieu.phanAo = phanAo - sp.phanAo;
	return Hieu;
}
Sophuc Sophuc::operator*(Sophuc sp){
	Sophuc Tich;
	Tich.phanThuc = phanThuc*sp.phanThuc - phanAo*sp.phanAo;
	Tich.phanAo = phanThuc*sp.phanAo + phanAo*sp.phanThuc;
	return Tich;
}
Sophuc Sophuc::operator/(Sophuc sp){
	Sophuc Thuong;
	Thuong.phanThuc = ( phanThuc*sp.phanThuc + phanAo*sp.phanAo) / (sp.phanThuc * sp.phanThuc + sp.phanAo*sp.phanAo);
	Thuong.phanAo = (sp.phanThuc*phanAo - sp.phanAo*phanThuc) / (sp.phanThuc*sp.phanThuc + sp.phanAo*sp.phanAo);
	return Thuong;
}
int main(){
	Sophuc sp1, sp2;
	cout<<"-----Nhap sp1-----"<<endl;
	cin>>sp1;
	cout<<sp1;
	cout<<"-----Nhap sp2-----"<<endl;
	cin>>sp2;
	cout<<sp2;
	
	cout<<"\nsp1 + sp2 = "<<sp1 + sp2<<endl;
	cout<<"\nsp1 - sp2 = "<<sp1 - sp2<<endl;
	cout<<"\nsp1 * sp2 = "<<sp1 * sp2<<endl;
	cout<<"\nsp1 / sp2 = "<<sp1 / sp2<<endl;
	return 0;
}
