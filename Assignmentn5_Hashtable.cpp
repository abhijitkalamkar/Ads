

#include <iostream>
#define MAX 20
using namespace std;

struct node
{
	long int tle_no;
	string name;
};

class Telephone_Dir
{
	int flag[MAX];
	node a[MAX];
public:
	int n;
	Telephone_Dir()
	{
		for(int i=0;i<MAX;i++)
			flag[i]=0;
	}
	void insert()
	{
		long int no;
		cout<<"Enter Phone Number : ";
		cin>>no;
		int j=no%n;
		for(int i=0;i<n;i++)
		{
			if(!flag[j])
			{
				a[j].tle_no=no;
				cout<<"Enter Name : ";
				cin>>a[j].name;
				flag[j]=1;
				return;
			}
			else
				j=(j+1)%n;
		}
		cout<<"\nSpace is not available in Hash Table...\n";
	}
	void display()
	{
		cout<<"\nTelephone Directory :- \n";
		for(int i=0;i<n;i++)
		{
			if(!flag[i])
				cout<<"\n-------------------------";
			else
				cout<<"\nName : "<<a[i].name<<"  Phone Number : "<<a[i].tle_no;
		}
		cout<<endl;
	}
	void search()
	{
		long int no;
		cout<<"\nEnter Number You want to search : ";
		cin>>no;
		int j=no%n;
		for(int i=0;i<n;i++)
		{
			if(flag[j]==1 && no==a[j].tle_no)
			{
				cout<<"\nRecord Found :-\nName : "<<a[j].name
					<<"\nPhone No : "<<a[j].tle_no<<endl;
				return;
			}
			else
				j=(j+1)%n;
		}
		cout<<"\nRecord Not Found...\n";
	}
	void Delete()
	{
		long int no;
		cout<<"\nEnter Number You want to Delete : ";
		cin>>no;
		int j=no%n;
		for(int i=0;i<n;i++)
		{
			if(flag[j]==1 && no==a[j].tle_no)
			{
				flag[j]=0;
				cout<<"\nRecord Deleted...\n";
				return;
			}
			else
				j=(j+1)%n;
		}
		cout<<"\nRecord Not Found...\n";
	}
};

int main()
{
	Telephone_Dir d;
	cout<<"\nEnter Size of Hash Table : ";
	cin>>d.n;
	int ch;
		do
		{
			cout<<"\n1.Insert Data";
			cout<<"\n2.Display Directory";
			cout<<"\n3.Search Number";
			cout<<"\n4.Delete Record";
			cout<<"\n5.Exit";
			cout<<"\n\nEnter Your Choice : ";
			cin>>ch;
			switch(ch)
			{
			case 1:
				d.insert();
				break;
			case 2:
				d.display();
				break;
			case 3:
				d.search();
				break;
			case 4:
				d.Delete();
				break;
			case 5:
				break;
			default:
				cout<<"\nPlease Enter Valid Choice...";
				break;
			}
		}while(ch!=5);
	return 0;
}
