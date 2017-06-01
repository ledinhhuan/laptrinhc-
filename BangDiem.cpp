#include<iostream>
#include<vector>

using namespace std;

class Diem{
	private:
		string monhoc;
		float diemso;
		int tinchi;
	public:
		Diem(){
		};
		Diem(string mh, float ds, int tc):monhoc(mh),diemso(ds),tinchi(tc){
			
		};
		
		void inDiem(){
			cout<<"Mon hoc: "<<monhoc<<endl;
			cout<<"Diem so: "<<diemso<<endl;
			cout<<"So tin chi: "<<tinchi<<endl;
		}
};

class BangDiem{
	private:
		int n;
		vector<Diem> bang;
	public:
		void nhapDiem(){
			cout<<"Nhap so mon hoc: ";
			cin>>n;
			for(int i = 0; i < n; i++){
				string monhoc;
				float diemso;
				int tinchi;
				cout<<"Mon hoc so "<<i<<endl;
				cout<<"Ten mon hoc: "; getline(cin,monhoc);
				cin.ignore(256,'\n') ;
				cout<<"Diem so: ";cin>>diemso;
				cout<<"Tin chi: ";cin>>tinchi;
				bang.push_back(Diem(monhoc,diemso,tinchi));
				
			}
		}
		void inBangDiem(){
			for(int i = 0; i < n; i++){
				cout<<"Mon hoc so "<<i<<endl;
				bang[i].inDiem();
			}
		}
};

int main(){
//	Diem diem1;
//	Diem diem("Toan roi rac",5.5,2);
//	diem1.inDiem();
	BangDiem bd;
	bd.nhapDiem();
	bd.inBangDiem();
	return 0;
}
