#include<iostream>
#include<string>
#include<vector>
using namespace std;
class NhanVien{
	protected:
		string ten;
		int namSinh;
		long long bacLuong;
	public:
		NhanVien(string t, int ns, long long bl){
			ten = t;
			namSinh = ns;
			bacLuong = bl;
		}
		string getTen(){
			return ten;
		}
		int getNamSinh(){
			return namSinh;
		}
		long long getBacLuong(){
			return bacLuong;
		}
		void setTen(string ten){
			this->ten = ten;
		}
		void setNamSinh(int namSinh){
			this->namSinh = namSinh;
		}
		void setBacLuong(long long bacLuong){
			this->bacLuong = bacLuong;
		}
		long long tinhLuong(){
			return bacLuong * 200;
		}
		void inThongTin(){
			cout<<"Ten: "<<ten<<endl;
			cout<<"Nam sinh: "<<namSinh<<endl;
			cout<<"Bac luong: "<<bacLuong<<endl;
		}
};

class QuanLy : public NhanVien{
	private:
		string chucVu;
		float heSoPC;
	public:
		QuanLy(string t, int ns, long long bl, string cv,float pc) 
			: NhanVien(t,ns,bl){
				chucVu = cv;
				heSoPC = pc;
			}
			string getChucVu(){
				return chucVu;
			}
			float getHeSoPC(){
				return heSoPC;
			}
			void setChucVu(string cv){
				chucVu = cv;
			}
			void setHeSoPC(float pc){
				heSoPC = pc;
			}
			long long tinhLuong(){
				return (bacLuong + heSoPC) * 200;
			}
			void inThongTin(){
				NhanVien::inThongTin();
				cout<<"Chuc vu: "<<chucVu<<endl;
				cout<<"He so phu cap: "<<heSoPC<<endl;
			}
};

class Phong{
	private:
		string tenPhong;
		vector<QuanLy> dsQuanLy;
		vector<NhanVien> dsNhanVien;
	public:
		Phong(string tp, vector<QuanLy> dsql,vector<NhanVien> dsnv){
			tenPhong = tp;
			dsQuanLy = dsql;
			dsNhanVien = dsnv;
		}
		string getTenPhong(){
			return tenPhong;
		}
		vector<QuanLy> getDanhSachQuanLy(){
			return dsQuanLy;
		}
		vector<NhanVien> getDanhSachNhanVien(){
			return dsNhanVien;
		}
		void setTenPhong(string tp){
			tenPhong = tp;
		}
		void setDanhSachQuanLy(vector<QuanLy> dsql){
			dsQuanLy = dsql;
		}
		void setDanhSachNhanVien(vector<NhanVien> dsnv){
			dsNhanVien = dsnv;
		}
		void inThongTin(){
			for(int i = 0; i < dsQuanLy.size(); i++){
				dsQuanLy[i].inThongTin();
			}
			for(int i = 0; i < dsNhanVien.size();i++){
				dsNhanVien[i].inThongTin();
			}
		}
		NhanVien tinhLuongCaoNhat(){
			NhanVien nv = dsNhanVien[0];
			for(int i = 0; i < dsNhanVien.size();i++){
				if(nv.tinhLuong() < dsNhanVien[i].tinhLuong())
					nv = dsNhanVien[i];
			}
			//cout<<"Nhan vien co luong cao nhat: "<<nv.tinhLuong()<<endl;
			return nv;
		}
};
int main(){
	vector<QuanLy> danhSachQL;
	QuanLy ql1 = QuanLy("tuan",1998,4,"ql1",10000);
	danhSachQL.push_back(ql1);
	ql1.inThongTin();
	QuanLy ql2 = QuanLy("van",1997,5,"ql2",20000);
	danhSachQL.push_back(ql2);
	ql2.inThongTin();
	
	cout<<"-------------------------------------"<<endl;
	vector<NhanVien> danhSachNV;
	NhanVien nv1 = NhanVien("anh",1998,8);
	danhSachNV.push_back(nv1);
	NhanVien nv2 = NhanVien("nam",2000,6);
	danhSachNV.push_back(nv2);
	NhanVien nv3 = NhanVien("canh",2000,10);
	danhSachNV.push_back(nv3);
	NhanVien nv4 = NhanVien("tu",1997,20);
	Phong p1 = Phong("Phong 1",danhSachQL,danhSachNV);
	cout<<"Luong nhan vien cao nhat: "<<endl;
	cout<<"Ten: "<<p1.tinhLuongCaoNhat().getTen()<<endl;
	cout<<"Luong: "<<p1.tinhLuongCaoNhat().tinhLuong()<<endl;
	
	
	
}
