#include<iostream>
#include<string.h>
using namespace std;

class matrix{
	
	public:
		
		int search(string city, string c[],int n){
			for(int i=0;i<n;i++){
				if(c[i]==city){
					return i;
				}
			}
			return -1;
		}
		
		void dist(string arr[],int n,int a[10][10]){
			
			string c1,c2;
			cout<<"enter source city:";
			cin>>c1;
			cout<<"enter destination city:";
			cin>>c2;
			int i1=search(c1,arr,n);
			int i2=search(c2,arr,n);
			if(i1==99999||i2==99999){
				cout<<"city not found";
			}
			else{
				int d;
				cout<<"enter distance between "<<c1<<"and "<<c2<<":";
				cin>>d;
				a[i1][i2]=d;
				a[i2][i1]=d;
			}
			
		}
		
		void display(int arr[][10],int n,string a[]){
			for(int i=0;i<n;i++){
				cout<<"\t"<<a[i];
			}
			cout<<endl<<"\t"<<"---------------------------------"<<endl;
			for(int i=0;i<n;i++){
				cout<<"      "<<a[i]<<"|"<<"  ";
				for(int j=0;j<n;j++){
					cout<<arr[i][j]<<"\t";
				}
				cout<<endl;
			}
		}
		
		void minimum(int arr[][10], int n, string c[]) {
		    int p = 0, q = 0, min, total = 0;
		    int v[10] = {0};  
		    v[0] = 1; 

		    for (int count = 0; count < n - 1; count++) {
			min = 99999;  
			
			for (int i = 0; i < n; i++) {
			    if (v[i] == 1) {  
				for (int j = 0; j < n; j++) {
				    if (v[j] == 0 && arr[i][j] < min) {  
				        min = arr[i][j]; 
				        p = i;  
				        q = j;  
				    }
				}
			    }
			}
			v[p]=1;
			v[q] = 1;
			total += min;
			cout<<"min distances:"<<c[p]<<c[q]<<"-"<<min<<endl;  
		    }
			
		    cout << "Total weight of MST: " << total << endl;
}

		
};

int main(){
	int n,ch;
	string c;
	string city[10];int a[10][10];
	matrix ob;
	do{
		cout<<" \n 1:enter cities \n 2:enter distance \n 3:display adjucency metrix \n 4:find mst \n"<<endl;
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"enter number of cities:";
				cin>>n;
				for(int i=0;i<n;i++){
					cout<<"enter name of city:";
					cin>>c;
					city[i]=c;
					for(int j=0;j<n;j++){
						a[i][j]=99999;
					}
				}
				break;
			case 2:
				ob.dist(city, n,a);
				break;
			case 3:
				ob.display(a,n,city);
				break;
			case 4:
				ob.minimum(a,n,city);
		}
	}while(ch<=4);
	return 0;
}

