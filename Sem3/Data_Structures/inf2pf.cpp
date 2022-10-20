#include<iostream>
#include<string>
using namespace std;
class LL{
	public:
		char data;
		LL* link;
		LL(){
			data=0;
			link=NULL;
		}
		LL(char x){
			data=x;
			link=NULL;
		}
		LL(char x, LL* add){
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
		bool Push(char x){
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
		bool Stackempty(){
			if(top==-1){
				return true;
			}
			else{
				return false;
			}
		}
		bool Pop(char* popped){
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
		char Stacktop(){
			if(top==-1){
				cout<<"StackUnderflow!"<<endl;
				return '0';
			}
			else{
				return curradr->data;
			}
		}
};	
int priority(char a){
	if(a=='^'){
		return 3;
	}
	else if(a=='*' || a=='/'){
		return 2;
	}
	else if(a=='+' || a=='-'){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	Stack st;
	string s,newstring;
	char x;
	cout<<"Enter expression: ";
	cin>>s;
	int len=s.length(),i;

	for(i=0;i<len;i++){
		if(s[i]=='('){
			st.Push(s[i]);
		}
		else if(s[i]==')'){
			st.Pop(&x);
			while(x!='('){
				newstring= newstring+x;
				st.Pop(&x);
			}
		}
		else if(s[i]=='+' ||s[i]=='-' ||s[i]=='*' ||s[i]=='/' ||s[i]=='^' ){
			while(!(st.Stackempty()) && priority(s[i])<=priority(st.Stacktop())){
				st.Pop(&x);
				newstring= newstring+x;
			}
			st.Push(s[i]);
		}
		else{
			newstring= newstring+s[i];
		}
	}
	while(!(st.Stackempty())){
		st.	Pop(&x);
		newstring= newstring+x;
	}
	cout<<"PostFix is: "<<newstring<<endl;
}
