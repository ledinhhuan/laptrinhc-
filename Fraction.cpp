#include<iostream>
using namespace std;
template <class T>

class Phanso{
	private:
		T tu;
		T mau;
	public:
		Phanso(){
		}
		Phanso(const Phanso &ps){
			tu = ps.tu;
			mau = ps.mau;
		}
		T getTu(){
			return tu;
		}
		T getMau(){
			return mau;
		}
		void setTu(T tuso){
			tu = tuso;
		}
		void setMau(T mauso){
			mau = mauso;
		}
		friend istream& operator >>(istream &is, Phanso &ps) {
			cout << "Nhap vao tu so: ";
			is >> ps.tu;
			do {
				cout << "Nhap vao mau so: ";
				is >> ps.mau;
				if (ps.mau == 0)
					cout << "\nMau so khong hop le, xin nhap lai.";
			} while (ps.mau == 0);
			return is;
		}
		friend ostream& operator <<(ostream &os, Phanso ps) {
			os << ps.tu << "/" << ps.mau << endl;;
			return os;
		}
};
template <class T>
class PhansoKT : public Phanso<T>{
	public:
		void setMau(T mauso){
			if(mauso == 0){
				cout<<"Mau so phai khac 0 ";
				exit(1);
			}else{
				Phanso<T>::setMau(mauso);
			}
		}
		friend PhansoKT operator +(PhansoKT P1, PhansoKT P2){
			PhansoKT Tong;
			Tong.setTu(P1.getTu() * P2.getMau() + P1.getMau() * P2.getTu());
			Tong.setMau(P1.getMau() * P2.getMau());
			return Tong;
		}
		friend PhansoKT operator -(PhansoKT P1, PhansoKT P2){
			PhansoKT Hieu;
			Hieu.setTu(P1.getTu() * P2.getMau() - P1.getMau() * P2.getTu());
			Hieu.setMau(P1.getMau() * P2.getMau());
			return Hieu;
		}
		friend PhansoKT operator *(PhansoKT P1, PhansoKT P2){
			PhansoKT Tich;
			Tich.setTu(P1.getTu() * P2.getTu());
			Tich.setMau(P1.getMau() * P2.getMau());
			return Tich;
		}
		friend PhansoKT operator /(PhansoKT P1, PhansoKT P2){
			 PhansoKT Thuong;
			Thuong.setTu(P1.getTu() * P2.getMau());
			Thuong.setMau(P1.getMau() * P2.getTu());
			return Thuong;
		}
		
};
int main(){
	PhansoKT<int> p1;
	cout<<"Nhap p1: "; cin>>p1;
	cout<<p1;
	
	PhansoKT<int> p2;
	cout<<"Nhap p2: "; cin>>p2;
	cout<<p2;
	
	cout<<"Tong: "<<p1+p2<<endl;
	cout<<"Hieu: "<<p1-p2<<endl;
}



