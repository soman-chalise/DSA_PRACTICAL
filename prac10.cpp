#include <iostream>
#include<vector>
using namespace std;

class Heap{
	private:
		int n,marks,parent,current,temp;
	public:
		
		void inp(vector<int>&arr){
					cout<<"enter number of students:";
					cin>>n;
					for(int i=0;i<n;i++){
						cout<<"enter marks of the student "<<(i+1)<<":";
						cin>>marks;
						arr.push_back(marks);
					}
		}
		
		void disp(vector<int>&arr){
			n=arr.size();
			for(int i=0;i<n;i++){
				cout<<arr[i]<<"   ";
			}
		}
		
		void maxheap(vector<int>&arr,int i){
			current=i;
			parent=(i-1)/2;
			while(i>=0 && arr[parent]<arr[current]){
				swap(arr[current],arr[parent]);
				current=parent;
				parent=(current-1)/2;
			}
		}
		
		void minheap(vector<int>&arr,int i){
			current=i;
			parent=(i-1)/2;
			while(i>=0 && arr[parent]>arr[current]){
				swap(arr[current],arr[parent]);
				current=parent;
				parent=(current-1)/2;
			}
		}
};

int main(){
	vector<int>Hp;
	Heap heap;
	heap.inp(Hp);
	cout<<"marks of the students:";
	heap.disp(Hp);
	for(int i=0;i<Hp.size();i++){
		heap.maxheap(Hp,i);
	}
	cout<<"\n \n max heap:";
	heap.disp(Hp);
	cout<<"max marks:"<<Hp[0];
	for(int i=0;i<Hp.size();i++){
		heap.minheap(Hp,i);
	}
	
	cout<<"\n \n min heap";
	heap.disp(Hp);
	cout<<"min marks:"<<Hp[0];
	return 0;
}
