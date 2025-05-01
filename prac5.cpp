#include<iostream>
#include<string.h>
using namespace std;

struct node{
	char data;
	node*left;
	node*right;
};

class stk{
	public:
		int top;
		node*exp[30];
		
		stk(){
			top=-1;
		}
		
		int isempty(){
			if(top==-1){
				return 1;
			}
			else{
				return 0;
			}
		}
		
		void pushdata(node*p){
			top=top+1;
			exp[top]=p;
		}
		node*popdata(){
			return exp[top--];
			
		}
};

class tree{
	public:
		node*top;
		
		void exptree(char exp[]){
			node*t1;
			node*t2;
			stk ob;
			int l=strlen(exp);
			for(int i=l-1;i>=0;i--){
				top=new node;
				top->left=NULL;
				top->right=NULL;
				if(isalpha(exp[i])){
					top->data=exp[i];
					ob.pushdata(top);
				}
				else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='/'||exp[i]=='*'){
					t1=ob.popdata();
					t2=ob.popdata();
					top->data=exp[i];
					top->left=t1;
					top->right=t2;
					ob.pushdata(top);
				}
			}
			top=ob.popdata();
		}
		
		void postorder(){
			node*t=top;
			stk s1,s2;
			s1.pushdata(t);
			while(!s1.isempty()){
				t=s1.popdata();
				s2.pushdata(t);
				if(t->left!=NULL){
					s1.pushdata(t->left);
				}
				if(t->right!=NULL){
					s1.pushdata(t->right);
				}	
			}
			while (!s2.isempty())
			{
				top = s2.popdata();
				cout << top->data;
			}
			cout<<endl;
		}
};

int main(){
	tree obj;
	char exp[20];
	cin>>exp;
	obj.exptree(exp);
	obj.postorder();
	return 0;
}
