#include <iostream>
using namespace std;
class phanso{
	private:
	 	int tuso;
	 	int mauso;
	public:
		phanso(int t, int m){
			tuso = t;
			mauso = m;
		}
		int getTuSo(){
			return tuso;
		}
		void setTuSo(int t){
			tuso = t;
		}
		int getMauSo(){
			return mauso;
		}
		void getMauSo(int m){
			mauso = m;
		}
	void output();
	phanso cong(phanso);
	 	
};
void phanso::output(){
	cout<<tuso<<"/"<<mauso<<endl;
}
phanso phanso::cong(phanso ps){
	phanso xkq;
	kq.tu = tu * ps.mau + mau * ps.tu;
	kq.mau = mau * ps.mau;
	return kq; 
}
int main(){
	phanso ps1;
	ps1.tu = 5;
	ps1.mau =7;
	ps1.output();
	phanso ps2;
	ps2.tu = 4;
	ps2.mau = 3;
	ps2.output() ;
	phanso tong = ps1.cong(ps2);
	tong.output();
}
