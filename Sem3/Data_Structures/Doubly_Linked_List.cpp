#include<iostream>
using namespace std;
class DLL{
	public:
		int data;
		DLL* flink,*blink;
		DLL(){
			data=0;
			flink=NULL;
			blink=NULL;
		}
		DLL(int x){
			data=x;
			flink=NULL;
			blink=NULL;
		}
		DLL(DLL * pre,int x){
			data=x;
			blink=pre;
			flink=NULL;
		}
		DLL(DLL* pre,DLL* post,int x){
			data=x;
			blink=pre;
			flink=post;
		}
		void Create(DLL** first,int data){
			*first=new DLL(data);
		}
		void Create(DLL** first){
			*first=new DLL();
		}
		bool search(DLL* first,int x,DLL** ppre,DLL**ploc){
			DLL* ptr=first,*p=NULL;
			while(ptr!=NULL){
				if(ptr->data>=x){
					*ploc=ptr;
					*ppre=p;
					if(ptr->data==x){
						return true;
					}
					else{
						return false;
					}
				}
				else{
					p=ptr;
					ptr=ptr->flink;
				}
			}
			*ploc=ptr;
			*ppre=p;
		}
		bool emptyDLL(DLL* first){
			if(first==NULL){
				return true;
			}
			else{
				return true;
			}
		}
		bool countDLL(DLL* first,int* count){
			int c=0;
			while(first!=NULL){
				c++;
				first=first->flink;
			}
			*count=c;
		}
		bool headDisplay(DLL* first){
			while(first!=NULL){
				cout<<first->data<<" ";
				first=first->flink;
			}
			cout<<endl;
			return true;
		}
		bool rearDisplay(DLL* first){
			DLL* ptr;
			while(first!=NULL){
				ptr=first;
				first=first->flink;
			}
			while(ptr!=NULL){
				cout<<ptr->data<<" ";
				ptr=ptr->blink;
			}
			cout<<endl;
			return true;
		}
		bool insert(DLL** first,int x){
			DLL* ppre,*ploc;
			search(*first,x,&ppre,&ploc);
			if(*first==NULL){
				Create(first,x);
				return true;
			}
			else if(ppre!=NULL && ploc!=NULL){
				ppre->flink=new DLL(ppre,ploc,x);
				ploc->blink=ppre->flink;
				return true;
			}
			else if(ppre==NULL){
				*first=new DLL(NULL,ploc,x);
				ploc->blink=*first;
				return true;
			}
			else{
				ppre->flink=new DLL(ppre,NULL,x);
				return true;
			}
		}
		bool Delete(DLL** first,int x){
			DLL* ppre,*ploc;
			bool s=search(*first,x,&ppre,&ploc);
			if(s){
				if(ppre!=NULL && ploc!=NULL && ploc->flink!=NULL){ //middle
					ppre->flink=ploc->flink;
					ppre->flink->blink=ppre;
					delete(ploc);
					return true;
				}
				else if(ppre==NULL && ploc->flink!=NULL){ //first without any
					*first=ploc->flink;
					ploc->flink->blink=NULL;
					delete(ploc);
					return true;
				}	
				else if(ppre==NULL && ploc->flink==NULL){ //first with ele
					*first=NULL;
					delete(ploc);
					return true;
				}
				else{ //last 
					ppre->flink=NULL;
					delete(ploc);
					return true;
				}
			}
			else{
				return false;
			}
		}
		bool headSearch(DLL* first,int x,int* pos){
			int i=0;
			while(first!=NULL && first->data<x){
				i++;
				first=first->flink;
			}
			if(first!=NULL && first->data==x){
				*pos=i;
				return true;
			}
			else{
				return false;
			}
		}
		bool tailSearch(DLL* first,int x,int* pos){
			int c=0,i;
			DLL* ptr;
			while(ptr!=NULL){
				ptr=ptr->flink;
				c++;
			}
			if(headSearch(first,x,&i)){
				*pos=c-i;
			}
			return headSearch(first,x,&i);
		}
		bool destroyDLL(DLL** first){
			DLL *ptr=*first,*p;
			while(ptr!=NULL){
				p=ptr->flink;
				delete(ptr);
				ptr=p;
			}
			return true;
		}
};
int main(){
	int choice, datain,dataout;
	bool success;
	DLL * first,*dll,*next,*before,*addr;
	cout<<"Enter First Element: ";	
	cin>>datain;
	dll->Create(&first,datain);
	cout<<"Doubly Linked List\nMenu:\n1)Insert \n2)Delete\n3)HeadSearch\n4)TailSearch\n5)Count\n6)HeadDisplay\n7)TailDisplay\n8)DestroyList\nAnything else to quit.\nEnter Your choice: ";
	cin>>choice;
	while(choice>0 && choice<9){
		switch(choice){
			case 1:
				cout<<"Enter data: ";
				cin>>datain;
				success=dll->insert(&first,datain);
				break;
			case 2:
				cout<<"Enter Element to delete: ";
				cin>>datain;
				success=dll->Delete(&first,datain);
				break;
			case 3:
				cout<<"Enter Element to Search: ";
				cin>>datain;
				success=dll->headSearch(first,datain,&dataout);
				if(success){
					cout<<"Element found at "<<dataout<<" indexes from first "<<endl;
				}
				break;
			case 4:
				cout<<"Enter Element to Search: ";
				cin>>datain;
				success=dll->tailSearch(first,datain,&dataout);
				if(success){
					cout<<"Element found at "<<dataout<<" indexes from last "<<endl;
				}
				break;
			case 5:
				success=dll->countDLL(first,&dataout);
				if(success){
					cout<<"Number of elements in list is: "<<dataout<<endl;
				}
				break;
			case 6:
				success=dll->headDisplay(first);
				break;
			case 7:
				success=dll->rearDisplay(first);
				break;
			case 8:
				success=dll->destroyDLL(&first);
				cout<<"List Destroyed"<<endl;
				return 0;
				break;
		}
		if(success){
			cout<<"Operation Successful"<<endl;
		}
		else{
			cout<<"Operation Failed"<<endl;
		}
		cout<<"Enter choice: ";
		cin>>choice;
	}
}
