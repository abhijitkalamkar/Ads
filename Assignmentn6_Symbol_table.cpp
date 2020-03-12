//============================================================================
// Name        : sytable.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct node
{
	string name,data,initial;
	int n,flag,line[2];
};
class symbol
{
	node table[2];
 public:
         symbol()
         {
        	 for(int i=0;i<2;i++)
        		 table[i].flag=0;
         }
         void insert()
         {
        	 for(int i=0;i<2;i++)
        	 {
        		 if(table[i].flag==0)
        		 {
        			 cout<<"\nEnter the name:";
        			 cin>>table[i].name;
        			 cout<<"\nEnter the data type:";
        			 cin>>table[i].data;
        			 cout<<"\nEnter initial value:";
        			 cin>>table[i].initial;
        			 cout<<"Enter number of lines the identifier is used:";
        			 cin>>table[i].n;
        			 cout<<"\nEnter the line numbers:";
        			 for(int j=0;j<table[i].n;j++)
        				 cin>>table[i].line[j];
        			 table[i].flag=1;


        		 }
        	 }
         }
         void display()
     	{
     	    cout<<"\nName"<<"\t";
		    cout<<"data-type"<<"\t";
		    cout<<"Initial-value"<<"\t";
		    cout<<"NO. of lines"<<"\t";
		    cout<<"Line numbers"<<"\n";
     		cout<<"..................................................................\n";
     		for(int i=0;i<4;i++)
     		{
     			if(table[i].flag==1)
     			{
     				 cout<<table[i].name<<"\t"<<table[i].data<<"\t\t"<<table[i].initial<<"\t\t\t"<<table[i].n<<"\t";
     				for(int j=0;j<table[i].n;j++)
     					cout<<table[i].line[j]<<" ";
     				cout<<"\n";
     			}
     		}
     	}
     	
         void search()
         {
              string a;
        	 int d=0;
        	 cout<<"\n enter the identifier to be searched :";
        	 cin>>a;
        	 cout<<"\nName"<<"\t";
		     cout<<"data-type"<<"\t";
		     cout<<"Initial-value"<<"\t";
		     cout<<"NO. of lines"<<"\t";
		     cout<<"Line numbers"<<"\n";
        	 for(int i=0;i<2;i++)
        	 {
        	 	if(table[i].flag==1)
        	 	{
        	 		if(table[i].name==a)
        	 		{
        	 			 cout<<table[i].name<<"\t"<<table[i].data<<"\t\t"<<table[i].initial<<"\t\t\t"<<table[i].n<<"\t";
        	 			for(int j=0;j<table[i].n;j++)
        	 			   cout<<table[i].line[j]<<" ";
        	 			cout<<"\n";
        	 			d=1;
        	 			break;
        	 		}
                }
        	 }
        	 if(d==0)
        	 {
        		 cout<<"\n identifier is not present";
        	 }
         }
        	
         void modify()
         {
        	 string a;
        	 int d=0;
        	 cout<<"\n enter the identifier to be modified :";
			 cin>>a;
			 for(int i=0;i<2;i++)
			 {
				if(table[i].flag==1)
				{
				  if(table[i].name==a)
				  {
					  cout<<"\nEnter the data type:";
					  cin>>table[i].data;
					  cout<<"\nEnter initial value:";
					  cin>>table[i].initial;
					  cout<<"Enter number of lines the identifier is used:";
					  cin>>table[i].n;
					  cout<<"\nEnter the number of lines:";
					  for(int j=0;j<table[i].n;j++)
					     cin>>table[i].line[j];

					  d=1;
					  break;
					}
                }
	         }
			 if(d==0)
			 {
			      cout<<"\n identifier is not present";
			  }
	 }
	 void delet()
	 {
	   
		string p;
		int d=0;
		cout<<"\n enter the identifier to be deleted :";
		cin>>p;
		for(int i=0;i<2;i++)
		{
			if(table[i].flag==1)
			{
				if(table[i].name==p)
				{
					table[i].flag=0;
					d=1;
					break;
				}
			}
		}
		if(d==0)
			cout<<"\n identifier is not present";
	}
};


        
int main()
{
   symbol s;
   int ch;
   while(1)
   {cout<<"\n1.Insert\n2.display\n3.search \n4.modify\n5.delete";
   cin>>ch;
    switch(ch)
   {
    case 1:
	    s.insert();
        break;
    case 2:
        s.display();
        break;
    case 3:
        s.search();
        break;
    case 4:
    	s.modify();
    	break;
    case 5:
         s.delet();
         break; 	
   }
   }
	return 0;
}
