#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Person{
	protected:
		string hoTen;
		int tuoi;
	public:
		Person(){
			
		}
		Person(string hoTen, int tuoi){
			this->hoTen = hoTen;
			this->tuoi = tuoi;
		}
		string getHoTen(){
			return hoTen;
		}
		int getTuoi(){
			return tuoi;
		}
		void setHoTen(string hoTen){
			this->hoTen = hoTen;
		}
		void setTuoi(int tuoi){
			this->tuoi = tuoi;
		}
};
class Student : public Person{
	private:
		float toan, ly, hoa;
	public:
		Student(){
			
		}
		Student(string hoTen, int tuoi, float toan, float ly, float hoa) : Person(hoTen, tuoi){
			this->toan = toan;
			this->ly = ly;
			this->hoa = hoa;
		}
		float getToan(){
			return toan;
		}
		float getLy(){
			return ly;
		}
		float getHoa(){
			return hoa;
		}
		
		void setToan(float toan){
			this->toan = toan;
		}
		void setLy(float ly){
			this->ly = ly;
		}
		void setHoa(float hoa){
			this->hoa = hoa;
		}
		
		float tinhDiemTB(){
			float DiemTB = (toan + ly + hoa) / 3.0;
			return DiemTB;
		}
};

class Teacher : public Person{
	private:
		vector<Student> danhSach;
		Person P;
	public:
		Teacher(){
			
		}
		Teacher(string hoTen, int tuoi , vector<Student> ds) : Person(hoTen, tuoi){
			danhSach = ds;
		}
		vector<Student> getDanhSach(){
			return danhSach;
		}
		void setDanhSach(vector<Student> ds){
			danhSach = ds;
		}
		Student diemCaoNhat(){
			Student s = danhSach[0];

			for(int i = 1; i < danhSach.size(); i++){
				if(s.tinhDiemTB() < danhSach[i].tinhDiemTB())
					s = danhSach[i];
			}
			return s;
		}	
};
int main(){
	int n;
	cout<<"\nNhap so sinh vien: "; cin>>n;
	vector<Student> danhSach;
	for(int i = 0; i < n; i++){
		string hoTen;
		int tuoi;
		float toan, ly, hoa;
		cout<<"\nNhap sinh vien thu "<<i+1<<endl;
		cin.ignore();
		cout<<"\nNhap ten sinh vien: "; getline(cin,hoTen);
		cout<<"\nNhap tuoi: "; cin>>tuoi;
		cout<<"\nNhap diem toan: "; cin>>toan;
		cout<<"\nNhap diem ly: "; cin>>ly;
		cout<<"\nNhap diem hoa: "; cin>>hoa;
		danhSach.push_back(Student(hoTen, tuoi,toan,ly,hoa));
		cout<<"\nDiem trung binh: "<<danhSach[i].tinhDiemTB();
	}
	
	string hoTen;
	int tuoi;
	cin.ignore();
	cout<<"\nNhap ten giao vien: "; getline(cin,hoTen);
	cout<<"\nNhap tuoi: "; cin>>tuoi;
	
	Teacher tc = Teacher(hoTen,tuoi,danhSach);
	cout<<"\nSinh vien co diem trung binh cao nhat: "<<endl;
	cout<<"Ten: "<<tc.diemCaoNhat().getHoTen()<<"\nTuoi: "<<tc.diemCaoNhat().getTuoi()<<endl;
	
}
