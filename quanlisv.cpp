#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Nguoi{
	private:
		string ten;
		int namSinh;
	public:
		Nguoi(){
		}
		Nguoi(string t, int ns){
			ten = t;
			namSinh = ns;
		}
		string getTen(){
			return ten;
		}
		int getNamSinh(){
			return namSinh;
		}
		void setTen(string t){
			ten = t;
		}
		void setNamSinh(int ns){
			namSinh = ns;
		}
		
};
class Sinhvien : public Nguoi{
	private:
		float diemToan;
		float diemLy;
		float diemHoa;
	public:
		Sinhvien(){
		}
		Sinhvien(string t, int ns,float dt,float dl,float dh) : Nguoi(string t, int ns){
			diemToan = dt;
			diemLy = dl;
			diemHoa = dh;
		}
		float getDiemToan(){
			return diemToan;
		}
		float getDiemLy(){
			return diemLy;
		}
		float getDiemHoa(){
			return diemHoa;
		}
		void setDiemToan(float dt){
			diemToan = dt;
		}
		void setDiemLy(float dl){
			diemLy = dl;
		}
		coid setDiemHoa(float dh){
			diemHoa = dh;
		}
		float tinhDiemTB(){
			return (diemToan + diemLy + diemHoa) / 3.0;
		}
};
class LopSinhHoat{
	private:
		string tenLop;
		vector<Sinhvien> danhSach;
	public:
		LopSinhHoat(){
		}
		LopSinhHoat(string tl, vector<Sinhvien> ds){
			tenLop = tl;
			danhSach = ds;
		}
		string getTenLop(){
			return tenLop;
		}
		vector<Sinhvien> getDanhSach(){
			return danhSach;
		}
		void setTenLop(string tl){
			tenLop = tl;
		}
		void setDanhSach(vector<Sinhvien> ds){
			danhSach = ds;
		}
		
};
