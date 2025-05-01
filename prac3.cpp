#include<iostream>
#include<string>
using namespace std;

class node{
	public:
		int flag;
		string name;
		node*down;
		node*next;
		
		node(string N){
			flag=0;
			name=N;
			down=NULL;
			next=NULL;
		}
};

class gll{
	public:
		
		bool search(node*&h,node*&p,string n){
			bool fl=false;
			p=h->down;
			while(p!=NULL){
				if(p->name==n){
					fl=true;
					return fl;
				}
				p=p->next;
			}
		}
		
		void cbook(node*&head){
			if(head==NULL){
				string name;
				cout<<"enter name of the book";
				cin>>name;
				node*newnode= new node(name);
				head=newnode;
			}
			else{
				cout<<"book exists"<<endl;
			}
		}
		
		void chapter(node*&head){
			if(head==NULL){
				cout<<"book doesnot exists"<<endl;
			}
			else{
				string name;
				cout<<"enter name of the chapter";
				cin>>name;
				
				if(head->flag==0){
					node*newnode= new node(name);
					head->down=newnode;
					head->flag=1;
				}
				
				else{
					node*p=head->down;
					while(p->next!=NULL){
						p=p->next;
					}
					node*newnode= new node(name);
					p->next=newnode;				
				}
			}
		}
		
		void section(node*&head){
			if(head==NULL){
				cout<<"book doesnot exists"<<endl;
			}
			else{
				if(head->flag==0){
					cout<<"no chapter added yet";
				}
				else{
					node*temp;
					string chapter;
					cout<<"enter the chapter to add the section:";
					cin>>chapter;
					
					bool flag=search(head,temp,chapter);
						if(flag){
							string name;
							cout<<"enter name of the section:";
							cin>>name;
							
							if(temp->flag==0){
								node*newnode=new node(name);
								temp->down=newnode;
								temp->flag=1;
							}
							else{
								node*t1=temp->down;
								while(t1->next!=NULL){
									t1=t1->next;
								}
								node*newnode= new node(name);
								t1->next=newnode;
							}
						}
						else{
							cout<<"chapter not found";
						}
					
					
				}
			}
		}
		
		void subs(node*&head){
			node*temp;
			string name,chapter,sec;
			if(head==NULL){
				cout<<"book doesnot exists"<<endl;
			}
			else{
				if(head->flag==0){
					cout<<"no chapter added yet";
				}
				else{
					
					cout<<"enter chapter name to add the sub section:";
					cin>>chapter;
					bool f1=search(head,temp,chapter);
					if(f1){
						if(temp->flag==0){
							cout<<"no section added in the chaptr yet";
						}
						else{
							node*t1;
							cout<<"enter section to add subsection:";
							cin>>sec;
							bool f2=search(temp,t1,sec);
							if(f2){
								cout<<"enter subsection name:";
								cin>>name;
								
								if(t1->flag==0){
									node*newnode= new node(name);
									t1->down=newnode;
									t1->flag=1;
								}
								
								else{
									node*t2=t1->down;
									while(t2->next!=NULL){
										t2=t2->next;
									}
									node*newnode= new node(name);
									t2->next=newnode;
								}
							}
							
							else{
								cout<<"section not found";
							}
						}
					}
				}
			}
		}
		
	void display(node*& head) {
		if (head == NULL) {
    		cout << "Book not added" << endl;
    		return;
		}
		cout << "Book: " << head->name << endl;
		if (head->flag == 1) {
    		node* chapter = head->down;
    		while (chapter != NULL) {
        		cout << "  Chapter: " << chapter->name << endl;
        		if (chapter->flag == 1) {
            		node* section = chapter->down;
            		while (section != NULL) {
                		cout << "    Section: " << section->name << endl;
                		if (section->flag == 1) {
                    		node* subsection = section->down;
                   			while (subsection != NULL) {
                        		cout << "      Subsection: " << subsection->name << endl;
                        		subsection = subsection->next;
                    		}
                		}
                		section = section->next;
            		}
        		}
        		chapter = chapter->next;
    		}
		} 
		else {
    		cout << "  No chapters added yet." << endl;
		}
	}			
};

int main(){
	node* head = NULL;
    gll ob;
    int ch;
    do{
    	cout<<"_"<<endl;
    	cout<<"1:add book"<<endl;
    	cout<<"2:add chapter"<<endl;
    	cout<<"3:add section"<<endl;
    	cout<<"4:add subsection"<<endl;
    	cout<<"5:display"<<endl;
    	cout<<"6:exit"<<endl;
    	cout<<"_"<<endl;
    	cout<<"enter choice:"<<endl;
    	cin>>ch;
    	cout<<"_"<<endl;
    	
    	switch(ch){
    		case 1:
    			ob.cbook(head);
    			break;
    		
    		case 2:
    			ob.chapter(head);
    			break;
    		case 3:
    			ob.section(head);
    			break;
    		case 4:
    			ob.subs(head);
    			break;
    		case 5:
    			ob.display(head);
    	}
    }while(ch<6);
	
	return 0;
}