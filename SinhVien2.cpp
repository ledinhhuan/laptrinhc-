#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Person {
private:
	string hoTen;
	int tuoi;
public:

	string getHoTen() {
		return hoTen;
	}
	int getTuoi() {
		return tuoi;
	}
	void setHoTen(string ht) {
		hoTen = ht;
	}
	void setTuoi(int t) {
		tuoi = t;
	}
	void nhapThongTin() {
		fflush(stdin);
		cout << "Nhap ten: "; getline(cin, hoTen);
		
		cout << "Nhap tuoi: "; cin >> tuoi;
	}
	void inThongTin() {
		cout << hoTen << " " << tuoi;
	}
};

class Student : public Person {
private:
	float toan, ly, hoa;
public:

	float getToan() {
		return toan;
	}
	float getLy() {
		return ly;
	}
	float getHoa() {
		return hoa;
	}

	void setToan(float t) {
		toan = t;
	}
	void setLy(float l) {
		ly = l;
	}
	void setHoa(float h) {
		hoa = h;
	}
	void nhapThongTin() {
		Person::nhapThongTin();
		cout << "Nhap diem toan: "; cin >> toan;
		cout << "Nhap diem ly: "; cin >> ly;
		cout << "Nhap diem hoa: "; cin >> hoa;
	}
	void inThongTin() {
		Person::inThongTin();
		cout << " " << toan << " " << ly << " " << hoa;
	}
};
class Teacher : public Person {
private:
	vector<Student> S;
public:

	vector<Student> getS() {
		return S;
	}
	void setS(vector<Student> s) {
		S = s;
	}
};

int main(){
	//fflush(stdin);
	Student st1;
	st1.nhapThongTin();
	st1.inThongTin();
	cout << endl;
	Student st2;
	st2.nhapThongTin();
	st2.inThongTin();
	return 0;
}
