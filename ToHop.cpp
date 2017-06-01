#include<iostream>
using namespace std;

long long Fact(long long n){
	if(n == 0)
		return 1;
	else
		return n * Fact(n-1);
}
int main(){
	long long n, k, CHKL, TH;
	cout<<"Nhap k = "; cin>>k;
	cout<<"Nhap n = "; cin>>n;
	CHKL = Fact(n) / Fact(n-k);
	cout<<CHKL<<endl;
	TH = Fact(n)/(Fact(k) * Fact(n-k));
	cout<<TH<<endl;
	return 0;
	
	
}
