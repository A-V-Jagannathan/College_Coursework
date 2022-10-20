#include<iostream>
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
		LL(int x, LL* add){
			data=x;
			link=add;
		}
};
class Stack{
	public:
		LL* first,*curradr;
		int top;
		Stack(){
			first=NULL;
			top=-1;
		}
		bool Push(int x){
			if(top==-1){
				first=new LL(x);
				curradr=first;
			}
			else{
				curradr->link=new LL(x);
				curradr=curradr->link;
			}	
			top++;
			return true;
		}
		bool Stackcount(int* count){
			*count=top+1;
			return true;
		}
		bool Stackempty(){
			if(top==-1){
				return true;
			}
			else{
				return false;
			}
		}
		bool Pop(int* popped){
			if(top==-1){
				cout<<"StackUnderflow!"<<endl;
				return false;
			}
			else if(top==0){
				*popped=first->data;
				delete(first);
				first=NULL;
				top--;
				return true;
			}
			else{
				*popped=curradr->data;
				LL* badd=first;
				while(badd->link!=curradr){
					badd=badd->link;
				}
				badd->link=NULL;
				delete(curradr);
				curradr=badd;
				top--;
				return true;
			}
		}
		bool Stacktop(int* topdata){
			if(top==-1){
				cout<<"StackUnderflow!"<<endl;
				return false;
			}
			else{
				*topdata=curradr->data;
				return true;
			}
		}
		bool DestroyStack(){
			while(top!=-1){			
				Pop(new int);
			}
			delete(first);
			cout<<"Stack Destroyed."<<endl;
			return true;
		}
};
class Queue{
	public:
		LL* first,*curradr;
		int front;
		Queue(){
			first=NULL;
			front=-1;
		}
		bool Enqueue(int x){
			if(front==-1){
				first=new LL(x);
				curradr=first;
			}
			else{
				curradr->link=new LL(x);
				curradr=curradr->link;
			}	
			front++;
			return true;
		}
		bool Queuecount(int* count){
			*count=front+1;
			return true;
		}
		bool Queueempty(){
			if(front==-1){
				return true;
			}
			else{
				return false;
			}
		}
		bool Dequeue(int* popped){
			if(front==-1){
				cout<<"StackUnderflow!"<<endl;
				return false;
			}
			else{
				*popped=first->data;
				LL* addr=first->link;
				delete(first);
				first=addr;
				front--;
				return true;
			}
		}
		bool Queuefront(int* frontdata){
			if(front==-1){
				cout<<"StackUnderflow!"<<endl;
				return false;
			}
			else{
				*frontdata=first->data;
				return true;
			}
		}
		bool Queuerear(int* reardata){
			if(front==-1){
				cout<<"StackUnderflow!"<<endl;
				return false;
			}
			else{
				*reardata=curradr->data;
				return true;
			}
		}
		bool DestroyQueue(){
			while(front!=-1){			
				Dequeue(new int);
			}
			delete(first);
			cout<<"Queue Destroyed."<<endl;
			return true;
		}
};
int main(){
	Stack st;
	Queue q;
	int choice,in,out;
	bool success;
	cout<<"Stack Operations\nMenu:\n1)Push\n2)Pop\n3)Stacktop\n4)StackCount\n5)Destroy\n6)Any other integer to quit..\nEnter Choice: ";
	cin>>choice;
	while(choice>0 && choice<6){
		switch(choice){
			case 1:
				cout<<"Enter integer to push: ";
				cin>>in;
				success=st.Push(in);
				break;
			case 2:
				success=st.Pop(&out);
				if(success){
					cout<<"Popped data is: "<<out<<endl;
				}
				break;
			case 3:
				success=st.Stacktop(&out);
				if(success){
					cout<<"Stacktop data is: "<<out<<endl;
				}
				break;
			case 4:
				success=st.Stackcount(&out);
				if(success){
					cout<<"count is: "<<out<<endl;;
				}
				break;
			case 5:
				success=st.DestroyStack();
				break;
		}
		if(success){
			cout<<"Operation Successful."<<endl;
		}
		cout<<"Enter choice: ";
		cin>>choice;
	}
	cout<<"\n\nQueue Operations\nMenu:\n1)Enqueue\n2)Dequeue\n3)Queuefront\n4)Queuerear\n5)QueueCount\n6)Destroy\n7)Any other integer to quit..\nEnter Choice: ";
	cin>>choice;
	while(choice>0 && choice<7){
		switch(choice){
			case 1:
				cout<<"Enter integer to queue: ";
				cin>>in;
				success=q.Enqueue(in);
				break;
			case 2:
				success=q.Dequeue(&out);
				if(success){
					cout<<"Dequeued data is: "<<out<<endl;
				}
				break;
			case 3:
				success=q.Queuefront(&out);
				if(success){
					cout<<"Front data is: "<<out<<endl;
				}
				break;
			case 4:
				success=q.Queuerear(&out);
				if(success){
					cout<<"Rear data is: "<<out<<endl;
				}
				break;
			case 5:
				success=q.Queuecount(&out);
				if(success){
					cout<<"Queuecount is: "<<out<<endl;
				}
				break;
			case 6:
				success=q.DestroyQueue();
				break;
		}
		if(success){
			cout<<"Operation Successful."<<endl;
		}
		cout<<"Enter choice: ";
		cin>>choice;
	}
}
