#include <iostream>
#include <fstream>
#include <string>
#include<stdlib.h>
using namespace std;

class Student {
    string usn;
    string  name;
    string branch;
    string sem;
public:
    void read();
    void pack(string filename);
    int search(string,string);
    void unpack(string);
    int modify(string key,string);
    };
int main()
{
    int ch;
    //fstream f;

    Student s;
    string key;
   string filename;
    while(1)
    {
    cout<<"1.insert 2.search 3.delete 4.modify\n";
    cout<<"enter your choice";
    cin>>ch;

         switch(ch)
        {
        case 1:
            s.read();
            cout<<"enter filename ";
            cin >>filename;
            s.pack(filename.c_str());
            break;
        case 2:
            cout<<"Enter the USN to be searched\n";
            cin>>key;
            cout<<"enter filename ";
                        cin >> filename;
            s.search(key,filename);
            break;
        case 3:
            s.modify(key,filename);
            break;
        case 4: s.unpack(string filename);
            break;

            }
        }
}
void Student::read(){
    cout<<"enter name"<<endl;
    cin>>name;
    cout<<"enter usn"<<endl;
    cin>>usn;
    cout<<"enter branch"<<endl;
    cin>>branch;
    cout<<"enter sem"<<endl;
    cin>>sem;
}
void Student::pack()
{
    stringstream ss;
    ss << sem;
    return name + "|" + usn + "|" + ss.str () + "|" + branch;

}
void Student::unpack(string filename)
{
	string temp;
    ifstream myf(filename.c_str());
    getline(myf,usn,'|');
    getline(myf,name,'|');
    getline(myf,branch,'|');
    getline(myf,sem,'$');
    getline(myf,temp);
    myf.close();

}
