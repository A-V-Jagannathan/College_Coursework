#include<bits/stdc++.h>
using namespace std;
class LL{
	public:
		int data;
		LL* link;
		LL(){
			data=0;
			link=NULL;
		}
		LL(int x){
			data=x;
			link=NULL;	
		}
		
		LL(LL* add,int x){
			data=x;
			link=add;
		}
};
class HT{
	public:
		LL** arr;
		int max;
		HT(LL** arradd,int maxele){
			arr=arradd;
			max=maxele;
		}
		bool Insert(int data){
			int ind=data%max;
			if(*(arr+ind)==NULL){
				LL* first= new LL(data);
				*(arr+ind)=first;
			}
			else{
				LL* first=*(arr+ind),*before;
				while(first!=NULL){
					before=first;
					first=first->link;
				}
				before->link=new LL(first,data);
			}
			return true;
		}
		bool Delete(int data){
			int ind=data%max;
			LL* first=*(arr+ind),*before=NULL;
			while(first!=NULL && first->data!=data){
				before=first;
				first=first->link;
			}
			if(first==NULL){
				return false;
			}
			else{
				if(before==NULL){
					*(arr+ind)=first->link;
				}
				else{
					before->link=first->link;
				}
				return true;
			}
		}
		bool Search(int data,LL** index){
			int ind=data%max;
			LL* first=*(arr+ind);
			while(first!=NULL && first->data!=data){
				first=first->link;
			}
			if(first==NULL){
				return false;
			}
			else{
				*index=first;
				return true;
			}
		}
		bool display(){
			cout<<"Index\t\t"<<"Data"<<endl;
			for(int i=0;i<max;i++){
				LL* first= *(arr+i);
				cout<<i<<"\t\t";
				while(first!=NULL){
					cout<<first->data<<" ";
					first=first->link;
				}
				cout<<endl;
			}
			return true;
		}
};
int main(){
	int n,data;
	bool success;
	cout<<"Enter size: ";
	cin>>n;
	LL** arr= new LL*[n];
	for(int i=0;i<n;i++){
		*(arr+i)=NULL;
	}
	HT hashmap(arr,n);
	cout<<"Menu\n1)Insert\n2)Delete\n3)Search\n4)Display\n5)5 and any other integers=> Stop."<<endl;
	int choice;
	cout<<"Enter choice: ";
	cin>>choice;
	while(choice>=1 && choice<5){
		switch(choice){
			case 1:
				cout<<"Enter element to insert: ";
				
				cin>>data;
				success=hashmap.Insert(data);
				break;
			case 2:
				cout<<"Enter element to delete: ";
				
				cin>>data;
				success=hashmap.Delete(data);
				break;
			case 3:
				cout<<"Enter element to search: ";
				
				cin>>data;
				LL * index;
				success=hashmap.Search(data,&index);
				if(success){
					cout<<"Element found at index "<<data%n<<" at address: "<<index<<endl;
				}
				break;
			case 4:
				success=hashmap.display();
				break;
		}
		if(success){
			cout<<"Operation Success"<<endl;
		}
		else{
			cout<<"Operation failed."<<endl;
		}
		cout<<"Enter choice: ";
		cin>>choice;
	}
	
}
