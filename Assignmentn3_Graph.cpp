#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
class adjlist
{
	int nv,ne,m,n;
	node *adj[20];
public:
	adjlist()
   {
		for(int i=0;i<20;i++)
	       adj[i]=NULL;
   }
	void create()
	{
		cout<<"\n Enter the number of vertices:";
		cin>>nv;
		cout<<"\n Enter number of edges:";
		cin>>ne;
		for(int i=1;i<=ne;i++)
		{
			cout<<"\n Enter m and n";
			cin>>m>>n;
			addedge(m,n);
			addedge(n,m);
		}
	 }
	void addedge(int m,int n)
	{
	  node *nn,*cn;
	  nn=new node;
	  nn->data=n;
	  nn->next=NULL;
	  if(adj[m]==NULL)
		  adj[m]=nn;
	  else
	  {
		  cn=adj[m];
		  for(cn=adj[m];cn->next!=NULL;cn=cn->next);

			  cn->next=nn;

	  }
	}
	void display()
	{
		node *cn;
		for(int i=1;i<=nv;i++)
		{
			cout<<"["<<i<<"]";
			cn=adj[i];
			while(cn!=NULL)
			{
				cout<<"->"<<cn->data;
				cn=cn->next;
			}
			cout<<"\n";
		}
	}
};

class adjm:public adjlist
{
	int nv,ne,m,n,G[100][100];
public:
	void create()
	{
		cout<<"\n Enter number of vertices:";
		cin>>nv;
		for(int i=1;i<=nv;i++)
		{
			for(int j=1;j<=nv;j++)
			{
				G[i][j]=0;
			}
		}
		cout<<"\n Enter number of edges:";
		cin>>ne;
		for(int i=1;i<=ne;i++)
		{
			cout<<"\n Enter initial vertex:";
			cin>>m;
			cout<<"\n Enter last vertex:";
			cin>>n;
			G[m][n]=1;
			G[n][m]=1;

		}
	 }
	void display()
	{
		for(int i=1;i<=nv;i++)
		{
			for(int j=1;j<=nv;j++)
			{
				cout<<G[i][j];
				cout<<" ";
			}
			cout<<endl;
		}
	}

};

int main()
{
	adjlist al;
	adjm am;
	al.create();
    al.display();
    am.create();
    am.display();
	return 0;
}
