#include <iostream>
#include<cstring>
using namespace std;

typedef struct node{
	string word,meaning;
	struct node *lf,*rt;

}node;
class Bst
{


  public:
	     node *root;

	Bst()
   {
	 root=NULL;

   }
	node *getroot()
	{
	  return root;
	}

	void insert()
	{
	    int n;
	   cout << "\n Enter the number of words : ";
	   cin >> n;

		node *cn,*nn;
		for(int i=0; i<n; i++)
	    {
		nn=new node;
		nn->lf=nn->rt=NULL;
		cout<<"Enter word: ";
		cin>>nn->word;
		cout<<"\n "<<"Enter meaning: ";
		cin>>nn->meaning;
		cout<<"\n ";
		if(root==NULL)
			root=nn;
		else
		{
			int att=0;
			cn=root;
			while(att==0)
			{
		       if(nn->word<cn->word)
		       {
		    	   if(cn->lf==NULL)
		    	   {
		    		   cn->lf=nn;
		    		   att=1;
		    	   }
		    	   else

		    		   cn=cn->lf;
		       }
		       else
		       {
		    	   if(cn->rt==NULL)
		    	   {
		    		   cn->rt=nn;
		    		   att=1;
		    	   }
		    	   else
		    	   {
		    		   cn=cn->rt;
		    	   }
		       }
			}
		}
	}
	}

	void display(node *cn)
	{
		if(cn != NULL)
			{
				display(cn->lf);
				cout << "\n " << cn->word << " - " << cn->meaning << "\n";
				display(cn->rt);
			}
		}
		void inorder(node *cn)
	{
		if(cn!=NULL)
		{
			inorder(cn->lf);
			cout << "\n " << cn->word << " - " << cn->meaning << "\n";
			inorder(cn->rt);

		}
	}

	void preorder(node *cn)
		{
			if(cn!=NULL)
			{
				cout << "\n " << cn->word << " - " << cn->meaning << "\n";
				preorder(cn->lf);
				preorder(cn->rt);

			}
		}


	void postorder(node *cn)
		{
			if(cn!=NULL)
			{
				postorder(cn->lf);
				postorder(cn->rt);
				cout<< "\n "<<cn->word<<"- "<<cn->meaning<< "\n";
			}
		}
	   node* search(node *root,string key)
	   {
		   if(root == NULL || root->word == key)
		   		return root;
		   											// Key is greater than cn's data
		   	if (root->word < key)
		   		return search(root->rt, key);
		   											// Key is smaller than cn's data
		   	    return search(root->lf, key);
		   }

		   void  update(node *cn)
		   {
		   	 cout << "\n Enter the new meaning of the word " << cn->word << " : ";
		   	 cin >> cn->meaning;
		   }
		   void delet(string key)
		   {
			  bool flag=0;
			  string word1,meaning1;
			  node *cn,*parent,*temp;
			  cn=root;
			  
			  
			  while(cn!=NULL)
			  {
			    if(key<cn->word)
			    {
			      parent=cn;
			      cn=cn->lf;
			      flag=0;
			    }
			    else if(key>cn->word)
			    {
			      parent=cn;
			      cn=cn->rt;
			      flag=0;
			    }
			    else
			    {
			       flag=1;
			       break;
			    }
			  }
			  if(flag==1)
			  {
			    if(cn->lf==NULL && cn->rt==NULL)     
			    {
			       if(parent->lf==cn)
			          parent->lf=NULL;
			       else
			          parent->rt=NULL;
			     }
			     else if(cn->rt==NULL)
			     {
			        if(parent->lf==cn)
			            parent->lf=cn->lf;
			        else
			            parent->rt=cn->lf;
			      }
			      else if(cn->lf==NULL)
			     {
			        if(parent->lf==cn)
			            parent->lf=cn->rt;
			        else
			            parent->rt=cn->rt;
			      }
			      else if(cn->lf!=NULL && cn->rt!=NULL)  
			      {
			         temp=cn->lf;
			         while(temp->rt!=NULL)
			         {
			            temp=temp->rt;
			         }
			         word1=temp->word;
			         meaning1=temp->meaning;
			         delet(temp->word);              
			         delet(temp->meaning);
			         cn->word=word1;
			         cn->meaning=meaning1;
			      }
			      else
			         cout<<"\nword not present";
			    }
			   }                     
};
	int main()
	{
		Bst obj;
		node *temp;
		int ch;
		string key;
		do
		{
			cout<<"\n 1.insert 2.display 3.inorder 4.preorder 5.postorder 6.search 7.update 8. delet 9.Exit \n";
			cout<<"Enter your choice: ";
			cin>>ch;
			switch(ch)
			{
			case 1:
				    obj.insert();
				    break;
			case 2:
				     obj.display(obj.root);
				     break;
			case 3:
				    obj.inorder(obj.root);
				      break;
			case 4:
				     obj.preorder(obj.root);

				     break;
			case 5:
				    obj.postorder(obj.root);

					  break;
			case 6:
				 cout << "\n Enter the word to be searched : ";
							cin >> key;
							temp = obj.search(obj.getroot(), key);
							if(temp != NULL)
								cout << "\n" << temp->word << " - " << temp->meaning << "\n";
							else
								cout << "\n Word not found! " << "\n";
								break;

			case 7:
				cout << "\n Enter the word whose meaning is to be updated : ";
									cin >> key;
									temp = obj.search(obj.getroot(), key);
									obj.update(temp);
								break;
		    case 8: cout << "\n Enter the word to be deleted from the dictionary : ";
					cin >> key;
					obj.delet(key);
					cout << "\n The word is delete. ";
			     	break;

              case 9:
                       break;
			default:
				     cout<<"Enter valid choice";
			}
		}while(ch!=9);
		return 0;
	}

