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
class Queue{
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
			 T p = list.front();
			list.erase(list.begin());
			return p;
		}
};
template <class T>
class checkQueue : public Queue<T>{
	public:
		void push(T var){
			if(Queue<T>::getMaxSize() == Queue<T>::getList().size()){
				cout<<"Queue da day, khong the them"<<endl;
				exit(1);
			}else{
				Queue<T>::push(var);
			}
			
		}
		T pop(){
			if(Queue<T>::getList().size() == 0){
				cout<<"Queue rong"<<endl;
				exit(1);
			}else{
				return Queue<T>::pop();
			}
			
		}
};

int main(){
	Person p1 = Person("Alice",5);
	Person p2 = Person("Johny",3);
	p1.inPerson();
	p2.inPerson();
	
	checkQueue<Person> Queue;
	vector<Person> list;
	Queue.setList(list);
	Queue.setMaxSize(2);
	
	Queue.push(p1);
	Queue.push(p2);
//	stack.push(p1);

	Queue.pop().inPerson();
}
