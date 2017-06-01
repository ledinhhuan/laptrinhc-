#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Person{
	private:
		string name;
		int age;
	public:
		Person(){
			
		}
		Person(string name, int age){
			this->name = name;
			this->age = age;
		}
		string getName(){
			return name;
		}
		int getAge(){
			return age;
		}
		void setName(string n){
			name = n;
		}
		void setAge(int a){
			age = a;
		}
};

class Employee : public Person{
	private:
		float luongCB;
		float luongTT;
		float phuCap;
	public:
		Employee() : Person(){
		}
		Employee(string name, int age, float lcb, float ltt, float pc) : Person(name, age){
			luongCB = lcb;
			luongTT = ltt;
			phuCap = pc;
		}
		float getLuongCB(){
			return luongCB;
		}
		float getLuongTT(){
			return luongTT;
		}
		float getPhuCap(){
			return phuCap;
		}
		
		void setLuongCB(float lcb){
			luongCB = lcb;
		}
		void setLuongTT(float ltt){
			luongTT = ltt;
		}
		void setPhuCap(float pc){
			phuCap = pc;
		}
		float thuNhap(){
			return luongCB + luongTT + phuCap;
		}
};

class Manager : public Person{
	private:
		vector<Employee> danhSach;
	public:
		Manager(){
			
		}
	Manager(string name,int age, vector<Employee> s):Person(name,age){
		danhSach = s;
	}
		vector<Employee> getDanhSach(){
			return danhSach;
		}
		void setDanhSach(vector<Employee> ds){
			danhSach = ds;
		}
		Employee thuNhapCaoNhat(){
			Employee e;
			float Max = 0;
			for(int i = 0; i < danhSach.size(); i++){
				if(Max < danhSach[i].thuNhap()){
					e = danhSach[i];
					Max = e.thuNhap();
				}		
			}
			return e;
		}
		
};
int main(){
	int n;
	cout<<"\nNhap so nhan vien: "; cin>>n;
	vector<Employee> danhSach;
	for(int i = 0; i < n; i++){
		string name;
		int age;
		float luongCB, luongTT,phuCap;
		cout<<"\nNhan vien thu "<<i+1<<endl;
		cin.ignore();
		cout<<"\nNhap ten: "; getline(cin,name);
		cout<<"\nNhap tuoi: "; cin>>age;
		cout<<"\nNhap luong CB: "; cin>>luongCB;
		cout<<"\nNhap luong TT: "; cin>>luongTT;
		cout<<"\nPhu cap: "; cin>>phuCap;
		danhSach.push_back(Employee(name,age,luongCB,luongTT,phuCap));
		cout<<"\nThu nhap: "<<danhSach[i].thuNhap();
	}
	
	
	string name;
		int age;
		cin.ignore();
		cout<<"\nNhap ten quan li: "; getline(cin,name);
		cout<<"\nNhap tuoi: "; cin>>age;
		Manager ql = Manager(name,age,danhSach);
		cout<<"Nhan vien co luong cao nhat:\n";
	cout<<"Ten: "<<ql.thuNhapCaoNhat().getName()<<endl<<"Tuoi: "<<ql.thuNhapCaoNhat().getAge()<<endl<<"Muc luong la: "<<ql.thuNhapCaoNhat().thuNhap();
	return 0;	
}

