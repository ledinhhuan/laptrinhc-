#include<iostream>
#include<string>
using namespace std;
const float LUONGCOBAN = 100;
const float NGAYCONG = 100;
class Nhanvien{
	private:
		string hoTen;
		int CMND;
		
	public:
		Nhanvien(string ht, int cm){
			hoTen = ht;
			CMND = cm;
		}
		string getHoTen(){
			return hoTen;
		}
		int getCMND(){
			return CMND;
		}
		void setHoTen(string ht){
			hoTen = ht;
		}
		void setCMND(int cm){
			CMND = cm;
		}
		virtual void inThongTin(){
			cout<<hoTen<<" "<<CMND<<" ";
		}
		float tinhLuong();
		
};
class NhanvienHC: public Nhanvien{
	private:
		float bacLuong;
	public:
		NhanvienHC(string ht, int cm, float bl) : Nhanvien(ht,cm){
			bacLuong = bl;
		}
		float getBacLuong(){
			return bacLuong;
		}
		void setBacLuong(float bl){
			bacLuong = bl;
		}
		float tinhLuong(){
			return bacLuong * LUONGCOBAN;
		}
		void inThongTin() {
			Nhanvien::inThongTin();
			cout<<bacLuong<<endl;
			cout<<tinhLuong()<<endl;
		}
		void nhapThongTin(){
			
		}
};

class NhanvienCN : public Nhanvien{
	private:
		int soNgayCong;
	public:
		NhanvienCN(string ht, int cm, int snc) : Nhanvien(ht,cm){
			//Nhanvien::Nhanvien(ht,cm);
			soNgayCong = snc;
		}
		int getSoNgayCong(){
			return soNgayCong;
		}
		void setSoNgayCong(int snc){
			soNgayCong = snc;
		}
		float tinhLuong(){
			return soNgayCong * NGAYCONG;
		}
		void inThongTin(){
			Nhanvien::inThongTin();
			cout<<soNgayCong<<endl;
			cout<<tinhLuong()<<endl;
		}
};
int main(){
	NhanvienHC nvhc("Le Dinh Huan", 123456, 3.99);
	nvhc.inThongTin();
	
	NhanvienCN nvcn("le van a",234567, 15);
	nvcn.inThongTin();
	return 0;
}






