
#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;

};
class set
{
	

public:
	node *hn;
	node *ln;
	set()
  {
	 hn=NULL;
	 ln=NULL;
	

  }
  void create()
  {
	  char ch;
	  do
	  {
	   
     
		if(hn==NULL)
		{
			cout<<"Enter data:";
			node *nn=new node;
			cin>>nn->data;
			hn=nn;
			ln=nn;
		}
		else
		{
			cout<<"Enter data:";
			node *nn=new node;
			cin>>nn->data;
			
			ln->next=nn;
			ln=nn;
		}
			  cout<<"Do you want to insert another node?\n";
						cin>>ch;
			}while(ch=='Y' || ch=='y');
				}


    void display()
    {
    	node *temp;
    	temp=hn;
    	while(temp!=NULL)
    	{
    		cout<<temp->data<<" ";
    		temp=temp->next;

    	}
    }
    void union_list(set s1, set s2)
    {
    	int flag=0;

    	node *cn1,*cn2;
    	s1.display();

    	for(cn2=s2.hn;cn2!=NULL;cn2=cn2->next)
    	{
    		flag=0;

    		for(cn1=s1.hn;cn1!=NULL;cn1=cn1->next)
    		{
    			if(cn1->data==cn2->data)
    		      flag=1;


    		}
    		if(flag==0)
    		{
    			cout<<cn2->data<<" ";
    		}
    	}
    }
    void intersection_list(set s1,set s2)
    {
    	int flag=0;
    	node *cn1,*cn2;

    	for(cn1=s1.hn;cn1!=NULL;cn1=cn1->next)
    	{
    	    flag=0;
    		for(cn2=s2.hn;cn2!=NULL;cn2=cn2->next)
    		{
    			if(cn1->data==cn2->data)
    			{
    		       flag=1;
    		       break;
    		    }   

    		}
    		if(flag==1)
    		{
    			cout<<cn1->data<<" ";

    		}
    	}
    }
    void diff_list(set s1,set s2)
    {
    	int flag=0;
	   node *cn1,*cn2;


	   for(cn1=s1.hn;cn1!=NULL;cn1=cn1->next)
	   {
	   		flag=0;

	       for(cn2=s2.hn;cn2!=NULL;cn2=cn2->next)
	       	{
	       		if(cn1->data==cn2->data)
	       		   flag=1;

	       	}
	        if(flag==0)
	        {
	        	cout<<cn1->data<<" ";

	        }
	    }
    }
    void symdiff_list(set s1,set s2)
    {
       
    	diff_list(s1 , s2);
    	diff_list(s2 , s1);
    
    }

       
};
int main()
{
    
	        set s1,s2,s3,s4,s5,s6;
	        int ch;
	        do
	        {
	        
			    cout<<"\n1.insert 2.display 3.union 4.Intersection 5.diff 6.symmdiff 7.Exit\n";        
			    cout<<"\n Enter ur choice:";
			    cin>>ch;
			    
			    switch(ch)
			    {
			      case 1:
			      
					  cout<<"First linked list:\n";
					  s1.create();
					  cout<<"second list:\n";
					  s2.create();
					  break;
					  
				 case 2:   
		              cout<<"First linked list is:\n";
					  s1.display();
					  cout<<"\nSecond linked list is:\n";
					  s2.display();
					  break;
					  
				 case 3:

					  cout<<"\n union of linked list:\n";
					  s3.union_list(s1,s2);
					  break;
					  
				 case 4:
					  
					 cout<<"\n Intersection of linked list:";
					 s4.intersection_list(s1,s2);
					 break;
					
				case 5:
					 
				   cout<<"\n diff of linked list:";
				   s5.diff_list(s1,s2);
				   break;
				   
			   case 6:
			   	   
				  cout<<"\n symmetric diff of linked list:";
				  s6.symdiff_list(s1,s2);
				  break;
			   
			   case 7:
				       break;
				       	  
			 }
			}while(ch!=7);
			 return 0;
	}   	  
				  

			  
