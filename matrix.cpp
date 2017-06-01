#include<iostream>
#define MAX 30
using namespace std;
class Matrix{
private:
	int n;
	int A[MAX][MAX];
public:
	Matrix();
	void Nhap();
	int getN();
	void setN(int);
	int getA(int,int);
	void setA(int,int,int);
	int Cong(Matrix);
	void Tru(Matrix);
	void Nhan(Matrix);
	void Xuat();
	
};
Matrix::Matrix(){
	n = 2;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			A[i][j] = 0;
		}
	}
}
int Matrix::getA(int i, int j){
	return A[i][j]; 
}
void Matrix::setA(int i, int j, int value){
	
}
void Matrix::Nhap(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout<<"a["<<i<<"]["<<j<<"] = ";
			cin>>A[i][j];
		}
	}
}
void Matrix::Xuat(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout<<A[i][j]<<" ";
		}
		cout<<"\n";
	}	
}
int Matrix::getN(){
	return n;
}
void Matrix::setN(int N){
	n = N;
}
int Matrix::Cong(Matrix M){
	Matrix  result;
	if(M.getN() != n){
		cout<<"\nKhong the cong hai ma tran cho nhau.";
	}
		
	else{
		result.setN(n);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				int value = A[i][j] + M.getA(i,j);
				result.setA(i,j,value);
			}
		}
	}
	return result;
}
int main(){
	Matrix m1, m2, m3;
	m1.setN(2);
	m1.Nhap();
	m1.Xuat();
	
	m2.setN(2);
	m2.Nhap();
	m2.Xuat();
	
	m3 = m1.Cong(m2);
	m3.Xuat();
	return 0;
}

