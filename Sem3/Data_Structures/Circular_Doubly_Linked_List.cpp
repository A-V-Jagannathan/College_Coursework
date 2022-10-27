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
		DLL(DLL* pre,DLL* post,int x){
			data=x;
			blink=pre;
			flink=post;
		}
		void Create(DLL** first,int data){
			*first=new DLL(data);
			(*first)->blink=*first;
			(*first)->flink=*first;
		}
		int countDLL(DLL* first){
			int c=0;
			DLL* ptr=first;
			while(ptr!=NULL && (ptr!=first ||c==0)){
				c++;
				ptr=ptr->flink;
			}
			return c;
		}
		bool search(DLL* first,int x,DLL** ppre,DLL**ploc,int* count){
			DLL* ptr=first,*p=NULL;
			int c=0,len=countDLL(first);
			while(c<len){
				*count=c;
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
				c++;
			}
			*ploc=ptr;
			*ppre=p;	
		}
		bool emptyDLL(DLL* first){
			if(first==NULL){
				return true;
			}
			else{
				return false;
			}
		}
		bool headDisplay(DLL* first){
			int c=0,len=countDLL(first);
			if(emptyDLL(first)){
				return false;
			}
			while(c<len){
				cout<<first->data<<" ";
				first=first->flink;
				c++;
			}
			cout<<endl;
			return true;
		}
		bool rearDisplay(DLL* first){
			int c=0,len=countDLL(first);
			if(emptyDLL(first)){
				return false;
			}
			while(c<len){
				first=first->blink;
				cout<<first->data<<" ";
				c++;
			}
			cout<<endl;
			return true;
		}
		bool insert(DLL** first,int x){
			DLL* ppre,*ploc,*ptr=*first,*ptr2;
			search(*first,x,&ppre,&ploc,new int);
			if(*first==NULL){
				Create(first,x);
			}
			else if(ptr==ploc){
				if(x>ptr->data){
					ptr2=new DLL(ptr->blink,ptr,x);
					ptr->blink->flink=ptr2;
					ptr->blink=ptr2;
				}
				else{
					*first=new DLL(ptr->blink,ptr,x);
					ptr->blink->flink=*first;
					ptr->blink=*first;
				}
			}
			else{
				ppre->flink=new DLL(ppre,ploc,x);
				ploc->blink=ppre->flink;
			}
			return true;
		}
		bool Delete(DLL** first,int x){
			DLL* ppre,*ploc,*ptr=*first;
			bool s=search(*first,x,&ppre,&ploc,new int);
			if(s){
				if(ploc==ptr){
					*first=ptr->flink;
					ptr->flink->blink=ptr->blink;
					ptr->blink->flink=ptr->flink;
					delete(ptr);
				}
				else{
					ppre->flink=ploc->flink;
					ploc->flink->blink=ppre;
					delete(ploc);
				}
			}
			else{
				return false;
			}
		}
		bool headSearch(DLL* first,int x,int* pos){
			int c=0;
			DLL* ppre,*ploc;
			bool s=search(first,x,&ppre,&ploc,&c);
			if(s){
				*pos=c;
			}
			return s;
		}
		bool tailSearch(DLL* first,int x,int* pos){
			bool s=headSearch(first,x,pos);
			*pos=countDLL(first)-(*pos)-1;
			return s;
		}
		bool destroyDLL(DLL* first){
			int c=0,len=countDLL(first);
			DLL *ptr=first,*p;
			while(c<len){
				p=ptr->flink;
				delete(ptr);
				ptr=p;
				c++;
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
	cout<<"Circular Doubly Linked List\nMenu:\n1)Insert \n2)Delete\n3)HeadSearch\n4)TailSearch\n5)Count\n6)HeadDisplay\n7)TailDisplay\n8)DestroyList\nAnything else to quit.\nEnter Your choice: ";
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
				success=true;
				cout<<"Number of elements in list is: "<<dll->countDLL(first)<<endl;
				break;
			case 6:
				success=dll->headDisplay(first);
				break;
			case 7:
				success=dll->rearDisplay(first);
				break;
			case 8:
				success=dll->destroyDLL(first);
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
