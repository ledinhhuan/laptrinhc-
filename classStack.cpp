#include<iostream>
#include<vector>

using namespace std;

class Person{
	private:
		string ten;
		int tuoi;
	public:
		Person(string _ten, int _tuoi){
			ten = _ten;
			tuoi = _tuoi;
		}
		void setTen(string _ten){
			ten = _ten;
		}
		void setTuoi(int _tuoi){
			tuoi = _tuoi;
		}
		string getTen(){
			return ten;
		}
		int getTuoi(){
			return tuoi;
		}
		void inPerson(){
			cout<<"Ten: "<<ten<<endl;
			cout<<"Tuoi: "<<tuoi<<endl;
		}
};

template <class T>
class Stack{
	private:
		vector<T> list;
		int maxSize;
	public:
		void setList(vector<T> _list){
			list = _list;
		}
		
		void setMaxSize(int _maxSize){
			maxSize = _maxSize;
		}
		
		vector<T> getList(){
			return list;
		}
		
		int getMaxSize(){
			return maxSize;
		}
		void push(T var){
			list.push_back(var);
		}
		T pop(){
			T p = list.back(); //T p = list.front();
			list.pop_back();	// list.erase(0);
			return p;
		}
};
template <class T>
class checkStack : public Stack<T>{
	public:
		void push(T var){
			if(Stack<T>::getMaxSize() == Stack<T>::getList().size()){
				cout<<"Stack da day, khong the them"<<endl;
				exit(1);
			}else{
				Stack<T>::push(var);
			}
			
		}
		T pop(){
			if(Stack<T>::getList().size() == 0){
				cout<<"Stack rong"<<endl;
				exit(1);
			}else{
				return Stack<T>::pop();
			}
			
		}
};

int main(){
	Person p1 = Person("Alice",5);
	Person p2 = Person("Johny",3);
	p1.inPerson();
	p2.inPerson();
	
	checkStack<Person> stack;
	vector<Person> list;
	stack.setList(list);
	stack.setMaxSize(2);
	
	stack.push(p1);
	stack.push(p2);
//	stack.push(p1);

	stack.pop().inPerson();
}
