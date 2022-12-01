#include<iostream>
using namespace std;
class arc;

//Graph Vertex
class vertex{
public:
	int data;
	vertex * nextver;
	bool proc,inq,ins,intr;
	arc* firstarc;
	vertex(int x){
		data=x;
		proc=false;
		inq=false;
		ins=false;
		intr=false;
		nextver=NULL;
		firstarc=NULL;
	}
};

//Graph edge or arc
class arc{
public:
	int weight;
	vertex* data;
	arc* nextarc;
	arc(vertex* vert,int w){
		data=vert;
		weight=w;
		nextarc=NULL;
	}
};

//Main graph structure and creator
class graphhead{
public:
	int count;
	vertex* firstver;
	graphhead(vertex* first){
		firstver=first;
		count=1;
	}

	//Adding a vertex
	bool addVertex(int data){
		vertex* ptr=firstver;
		while(ptr->nextver!=NULL){
			ptr=ptr->nextver;
		}
		ptr->nextver=new vertex(data);
		count++;
		return true;

	}

	//Creating connection between 2 veritces
	bool addEdge(int a,int b,int w){
		vertex* ptr1=firstver,*ptr2=firstver;
		while(ptr1!=NULL && ptr1->data!=a){
			ptr1=ptr1->nextver;
		}
		while(ptr2!=NULL && ptr2->data!=b){
			ptr2=ptr2->nextver;
		}
		if(ptr1==NULL || ptr2==NULL){
			return false;
		}
		arc* p1=ptr1->firstarc,*p2=ptr2->firstarc;
		if(p1==NULL){
			ptr1->firstarc=new arc(ptr2,w);
		}
		else{
			while(p1->nextarc!=NULL){
				p1=p1->nextarc;
			}
			p1->nextarc=new arc(ptr2,w);
		}
		if(p2==NULL){
			ptr2->firstarc=new arc(ptr1,w);
		}
		else{
			while(p2->nextarc!=NULL){
				p2=p2->nextarc;
			}
			p2->nextarc=new arc(ptr1,w);
		}
		return true;
	}

	//Adjacency List display
	void displayall(){
		vertex * ptr=firstver;
		arc* p;
		while(ptr!=NULL){
			cout<<ptr->data<<"---";
			p=ptr->firstarc;
			while(p!=NULL){
				cout<<"["<<p->data->data<<" w:"<<p->weight<<"]  ";
				p=p->nextarc;
			}
			cout<<endl;
			ptr=ptr->nextver;
		}
	}
};




                     //Stack and Queue for bft and dft
class ll{
public:
	vertex* data;
	ll* link;
	ll(vertex* v){
		data=v;
		link=NULL;
	}
	ll(vertex* v,ll* li){
		data=v;
		link=li;
	}
};
class stack{
public:
	ll* first,*last;
	int count;
	stack(){
		first=last=NULL;
		count=0;
	}
	void push(vertex* v){
		v->ins=true;
		if(count==0){
			first=new ll(v);
			last=first;
			count++;
		}
		else {
			last=new ll(v,last);
			count++;
		}
	}
	void pop(){
		if(count==1){
			count=0;
			first=last=NULL;
		}
		else{
			vertex* v=last->data;
			last=last->link;
			count--;
		}
	}
};
class queue{
public:
	ll *first,*last;
	int count;
	queue(){
		first=last=NULL;
		count=0;
	}
	void enqueue(vertex* v){
		v->inq=true;
		if(count==0){
			first=new ll(v);
			last=first;
		}
		else if(count==1){
			first->link=new ll(v);
			last=last->link;
		}
		else{
			last->link=new ll(v);
			last=last->link;
		}
		count++;
	}
	vertex* dequeue(){
		if(count==0){
	        cout<<"empty"<<endl;
		}
		else if(count==1){
			vertex* ptr=first->data;
			ptr->inq=false;
			count=0;
			first=last=NULL;
			return ptr;
		}
		else{
		    ll* ptr=first;
		    first=first->link;
		    count--;
		    return ptr->data;
		}
	}
};


		// BreadthFirstTraversal and DepthFirstTraversal display of graph
void bfs(graphhead g){
	queue q;
	int count=g.count,i=0;
	vertex* fp=g.firstver;
	while(fp!=NULL){
		fp->proc=false;
		fp=fp->nextver;
	}
	fp=g.firstver;
	q.enqueue(fp);
	while(i<count){
		vertex* v=q.dequeue();
		arc* a=v->firstarc;
		while(a!=NULL){
			if((a->data)->inq==false && (a->data)->proc==false){
				q.enqueue(a->data);
			}
			a=a->nextarc;
		}
		
		cout<<v->data<<" ";
		v->proc=true;
		i++;
	}
}

void dfs(graphhead g){
	vertex* v=g.firstver;
	int count=g.count,i=0;
	vertex* fp=g.firstver;
	while(fp!=NULL){
		fp->proc=false;
		fp=fp->nextver;
	}
	stack s;
	s.push(v);

	while(i<count){
		v=(s.last)->data;
		v->ins=false;
		s.pop();
		v->proc=true;
		arc * a=v->firstarc;
		while(a!=NULL){
			vertex* temp=a->data;
			if(temp->ins==false && temp->proc==false){
				s.push(temp);
			}
			a=a->nextarc;
		}
		cout<<v->data<<" ";
		i++;
	}
	cout<<endl;
}



						//Minimum weight spanning tree
class mwst{
public:
	vertex * firstver;
	int c;
//MWST creation from a graph g using prim's algorithm
	void MWST(graphhead g){
		vertex* vtravsr;
		vertex* source;
		vertex* dest;
		int minw=9999;
		int src,dst;
		vtravsr=g.firstver;
		vtravsr->intr=true;
		firstver=new vertex(vtravsr->data);
		int i=1,count=g.count;
		while(i<count){
			minw=9999;
			vtravsr=g.firstver;
			while(vtravsr!=NULL ){
			if(vtravsr->intr==true){
				arc* edg=vtravsr->firstarc;
				while(edg!=NULL ){
					if(edg->weight<minw && (edg->data)->intr==false){
						dest=edg->data;
						vertex*ptr=firstver;
						while((ptr->data)!=(vtravsr->data)){
							ptr=ptr->nextver;
						}
						source=ptr;
						minw=edg->weight;
					}
					edg=edg->nextarc;
				}
			}
				vtravsr=vtravsr->nextver;
			}

			
			arc* a=source->firstarc,*apre=NULL;
			vertex* v=firstver;
			while(a!=NULL && a->nextarc!=NULL){
				a=a->nextarc;
			}
			while(v->nextver!=NULL){
				v=v->nextver;
			}
			v->nextver=new vertex(dest->data);
			v=v->nextver;
			v->firstarc=new arc(source,minw);
			if(source->firstarc==NULL){
				source->firstarc=new arc(v,minw);
				dest->intr=true;
			}
			else{
				a->nextarc=new arc(v,minw);
				dest->intr=true;
			}
			i++;
		}
		c=count;
	}
//Display function
	void displayall(){
		vertex * ptr=firstver;
		arc* p;
		while(ptr!=NULL){
			cout<<ptr->data<<"---";
			p=ptr->firstarc;
			while(p!=NULL){
				cout<<"["<<p->data->data<<" w:"<<p->weight<<"]  ";
				p=p->nextarc;
			}
			cout<<endl;
			ptr=ptr->nextver;
		}
	}
};
//driver code
int main(){
	graphhead g= graphhead(new vertex(1));
	g.addVertex(2);
	g.addVertex(3);
	g.addVertex(4);
	g.addVertex(5);
	g.addVertex(6);
	g.addVertex(7);
	g.addEdge(1,2,1);
	g.addEdge(1,3,3);
	g.addEdge(1,4,2);
	g.addEdge(2,3,5);
	g.addEdge(2,5,7);
	g.addEdge(3,5,3);
	g.addEdge(3,6,2);
	g.addEdge(3,4,1);
	g.addEdge(4,6,5);
	g.addEdge(5,7,9);
	g.addEdge(6,7,2);
	cout<<"\t\tAdjacency List representation"<<endl;
	g.displayall();
	cout<<endl;
	cout<<"DFS of graph is: ";
	dfs(g);
	cout<<"BFS of graph is: ";
	bfs(g);
	mwst m=mwst();
	cout<<endl<<endl<<"\t\tMWST of the graph"<<endl;
	m.MWST(g);
	m.displayall();
}
//end