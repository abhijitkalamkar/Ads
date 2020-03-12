#include <iostream>
#include<stdio.h>
#include<stack>
using namespace std;


 struct node
{
    char data;
    node *left, *right;
};
class exptree
{
public:
	node *root;

	exptree()
    {
		root=NULL;

    }
	int isoperand(char a)
	{

		if(a=='*' || a=='/'  || a=='+' || a=='-')
		{
			return 0;
		}
		else
			 return 1;

	}
	 int priority(char b)
	 {
	       if(b=='*' || b == '/')
	                return 2;
	       else if(b=='+' || b=='-')
	                return 1;
	  }
	  
	void create()
	{
	    int length;
	    stack<node*>s1,s2;
        char exp[20];
        node *op, *lc, *rc, *nn;
        cout << "\n Enter the exp : ";
        cin >> exp;
         for(int i=0;exp[i]!='\0';i++)
		  length+=1;
		  cout<<length;
        for(int i=length-1; i>=0; i--)
        {
            if(isoperand(exp[i]))
            {
                nn = new node;
                nn->data = exp[i];
                nn->right = nn->left = NULL;
                s1.push(nn);
                cout<<"\n s1 :"<<nn->data;
            }

                else
                {
                   if(!s2.empty() && (priority(s2.top()->data)>priority(exp[i])))
                   {

                     while(!s2.empty() && priority(s2.top()->data)> priority(exp[i]))
                     {
                        op = s2.top();
                        s2.pop();
                        lc = s1.top();
                        s1.pop();
                        rc = s1.top();
                        s1.pop();
                        op->left = lc;
                        op->right = rc;
                        s1.push(op);
                        cout<<"\n s1 :"<<op->data;
                    }
                }
                   nn = new node;
                   nn->data = exp[i];
                   nn->left = nn->right = NULL;
                   s2.push(nn);
                  cout<<"\n s2:"<<nn->data;
            }
        }

		while(!s2.empty())
		{
			op = s2.top();
			s2.pop();
			lc = s1.top();
			s1.pop();
			rc = s1.top();
			s1.pop();
			op->left = lc;
			op->right = rc;
			s1.push(op);
			cout<<"\n s1:"<<op->data;
		}

		root = s1.top();
		s1.pop();
	}
	void inorder(node *cn)
	{
		if(cn!=NULL)
		{
			inorder(cn->left);
			cout <<cn->data;
			inorder(cn->right);
		}
	}
	void postorder(node *cn)
	{
		if(cn!=NULL)
		{
			postorder(cn->left);
			postorder(cn->right);
			cout <<cn->data;
		}
	}
	 void preorder(node *cn)
	{
		if(cn!=NULL)
		{
		    cout <<cn->data;
			preorder(cn->left);
			preorder(cn->right);
			
		}
	}
	void  prenonre(node *root)
	{
	  stack<node *>s;
      node *cn;
	  {
	    if(root==NULL)
	       return ;
	    else
	       s.push(root);   
	    while(!s.empty())
	    {
	    
	       cn= s.top();
	       s.pop();
	       cout<<cn->data;              
	       if(cn->right!=NULL)
	          s.push(cn->right);
	       if(cn->left!=NULL)
	          s.push(cn->left);
	     }
	    }
	 } 
	  void inornonre(node *root)
	 {
	   stack<node *>s;
	   node *cn;
	   
	     if (root==NULL)
	         return ;
	     else
	    
	       cn=root;
	       while(cn!=NULL)
	       {
	          s.push(cn);
	          cn=cn->left;
	        }
	        while(!s.empty())
	        {
	          cn=s.top();
	          s.pop();
	          cout<<cn->data;
	          if(cn->right!=NULL)
	          {
	            cn=cn->right;
	          while(cn!=NULL)
	          {
	              s.push(cn);
	              cn=cn->left;
	           }
	         }
	   }  
	               
}    
     void postnonre(node *root)
     {
         stack<node*>s1,s2;
         node *cn;
         if(root==NULL)
           return;
        else
        {
        
         s1.push(root);
         while(!s1.empty())
         {
             cn=s1.top();
             s1.pop();
             s2.push(cn);
             if(cn->left!=NULL)
               s1.push(cn->left);
             if(cn->right!=NULL)
               s1.push(cn->right);
           }    
             while(!s2.empty())
             {
               cn=s2.top();
               s2.pop();
               cout<<cn->data;
             }
         }
     }   
            
    
	          

	      
	            
	            
};
int main()
{

exptree obj;
obj.create();
cout<<"\n Inorder:";
obj.inorder(obj.root);
cout<<"\n postorder:";
obj.postorder(obj.root);
cout<<"\n preorder:";
obj.preorder(obj.root);
cout<<"\n preorder non recursive:";
obj.prenonre(obj.root);
cout<<"\n inorder non recursive:";
obj.inornonre(obj.root);
cout<<"\n postorder non recursive:";
obj.postnonre(obj.root);
cout<<"\n";
return 0;

}
