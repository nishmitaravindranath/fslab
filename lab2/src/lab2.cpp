//============================================================================
// Name        : pgm2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<fstream>
using namespace std;
class Student
{
	string usn;
	string name;
	string sem;
	string branch;
public:
	void read();
	void pack(string filename);
	void unpack();
	void modify();
};
int main() {
	int choice;
	Student s;
	string fname;
	while(1)
	{
		cout<<"1.Enter data 2.Search 3.Modify"<<endl;
			cout<<"enter your choice"<<endl;
			cin>>choice;
		switch(choice)
		{
		case 1:
			s.read();
			cout<<"enter filename";
			cin>>fname;
			s.pack(fname);
			break;
		case 2:
		//s.pack();
			break;
		case 3:
		//s.unpack();
			break;
		case 4:
			//s.modify();
			break;
		}
	}
}
void Student::read()
{
	cout<<"enter the name"<<endl;
	cin>>name;
	cout<<"enter the usn"<<endl;
	cin>>usn;
	cout<<"enter the sem"<<endl;
	cin>>sem;
	cout<<"enter the branch"<<endl;
	cin>>branch;

}
void Student::pack(string filename)
{
	string buffer;
	ofstream myf(filename.c_str(),ios::app);
	buffer=usn+"|"+name+"|"+sem+"|"+branch;
	myf<<buffer;
	myf.close();
}
