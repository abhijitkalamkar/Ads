

#include <iostream>
#include <fstream>
#include <cstring>
#define filename "Student.txt"
#define tempfile "Temp.txt"
using namespace std;

class Student
{
	char name[50];
	char div;
	int roll_no;
	char addr[50];
public:
	void readData()
	{
		cout<<"\nEnter Name : ";
		cin>>name;
		cout<<"Enter Division : ";
		cin>>div;
		cout<<"Enter Roll Number : ";
		cin>>roll_no;
		cout<<"Enter Address : ";
		cin>>addr;
	}
	void displayData()
	{
		cout<<"\nName : "<<name;
		cout<<"\nDivision : "<<div;
		cout<<"\nRoll No : "<<roll_no;
		cout<<"\nAddress : "<<addr;
		cout<<endl;
	}
	char* getName()
	{
		return name;
	}
};

void writeRecord()
{
	Student obj;
	obj.readData();
	ofstream outfile;
	outfile.open(filename,ios::binary|ios::app);
	outfile.write((char*)&obj,sizeof(obj));
	outfile.close();
	cout<<"\nRecord Inserted...\n";
}

void display()
{
	cout<<"\nStudents Information:-\n";
	Student obj;
	ifstream infile;
	infile.open(filename,ios::binary);
	while(infile)
	{
		infile.read((char*)&obj,sizeof(obj));
		if(infile.eof()!=0)
			break;
		obj.displayData();
	}
	infile.close();
}

void searchName()
{
    char key[50];
    bool flag=0;
	cout<<"Enter Name You want to search : ";
	cin>>key;
	Student obj;
	ifstream infile;
	infile.open(filename,ios::binary);
	while(infile)
	{
		infile.read((char*)&obj,sizeof(obj));
		if(infile.eof()!=0)
			break;
		if(!strcmp(obj.getName(),key))
		{
			flag=1;
			cout<<"\nRecord Found:-\n";
			obj.displayData();
		}
	}
	if(!flag)
		cout<<"\nRecord Not Found...\n";
	infile.close();
}

void Delete()
{
	int flag=0;
	char key[50];
	cout<<"\nEnter Name You want to Delete : ";
	cin>>key;
	Student obj;
	fstream file;
	file.open(filename,ios::in|ios::out|ios::binary);
	while(file)
	{
		file.read((char*)&obj,sizeof(obj));
		if(file.eof()!=0)
			break;
		if(!strcmp(obj.getName(),key))
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"\nRecord Not Found.....\n";
	else
	{
		ofstream otfile;
		otfile.open(tempfile,ios::binary|ios::out);
		otfile.close();
		otfile.open(tempfile,ios::binary|ios::app);
		file.seekp(0,ios::beg);
		file.seekg(0,ios::beg);
		while(file)
		{
			file.read((char*)&obj,sizeof(obj));
			if(file.eof()!=0)
				break;
			if(strcmp(obj.getName(),key))
			{
				otfile.write((char*)&obj,sizeof(obj));
				cout<<"\n1\n";obj.displayData();
			}
		}
		file.close();
		otfile.close();
		ifstream itfile;
		ofstream ofile;
		itfile.open(tempfile,ios::in);
		ofile.open(filename,ios::out);
		ofile.close();
		ofile.open(filename,ios::binary|ios::app);
		while(itfile)
		{
			itfile.read((char*)&obj,sizeof(obj));
			if(itfile.eof()!=0)
				break;
			ofile.write((char*)&obj,sizeof(obj));
			cout<<"\n2\n";obj.displayData();
		}
		itfile.close();
		cout<<"\nRecord Deleted...\n";
	}
	file.close();
}

int main()
{
	int ch;
	do
	{
		cout<<"\n1.Enter Student Details";
		cout<<"\n2.Display Details";
		cout<<"\n3.Search Name ";
		cout<<"\n4.Delete Student Details";
		cout<<"\n5.Exit";
		cout<<"\n\nEnter Your choice : ";
		cin>>ch;
		switch(ch)
		{
		case 1:
			writeRecord();
			break;
		case 2:
			display();
			break;
		case 3:
			searchName();
			break;
		case 4:
			Delete();
			break;
		case 5:
			break;
		default:
			cout<<"\nEnter Valid Choice....";
			break;
		}
	}while(ch!=5);
	return 0;
}
