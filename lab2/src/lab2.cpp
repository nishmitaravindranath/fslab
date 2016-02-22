
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
	void pack(string fname);
	void unpack();
	void search(string key,string fname);
};
int main() {
	int choice;
	Student s;
	string fname,key;
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
		cout<<"enter the usn to be searched\n";
		cin>>key;
		s.search(key,fname);
			break;
		case 3:
		s.unpack(fname);
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
void Student::pack(string fname)
{
	string buffer;
	ofstream myf(fname.c_str(),ios::app);
	buffer=usn+"|"+name+"|"+sem+"|"+branch;
	myf<<buffer;
	myf.close();
}
void Student::unpack(string fname)
{
	ifstream myf(fname.c_str());
	getline(myf,usn,'|');
	getline(myf,name,'|');
	getline(myf,branch,'|');
	getline(myf,sem,'|');
	myf.close();
}
void Student::search(string key,string fname)
{
	Student s[10];
	int i=0;
	ifstream myf(fname.c_str());
	while(!myf.eof())
	{
		cout<<"In search";
		s[i].unpack(fname);
	if(key==s[i].usn)
	{
		cout<<"record found\n";
		cout<<s[i].usn<<"\t"<<s[i].name;
	    break;
	}
	i++;
}
}
