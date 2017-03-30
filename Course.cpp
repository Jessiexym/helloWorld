#include <iostream>
#include <string.h>
using namespace std;
class CEmployee
{
public:
    CEmployee(){}
    CEmployee(int age, char* name)
    {
        this->age=age;
        int len=strlen(name)+1;
        Name = new char[len];
        strcpy(Name,name);
    }
    virtual ~CEmployee()  //���������������������������ٸ��ࡣû��ʱ��ֱ�ӵ��ø���
    {
        cout<<"Destruct CE"<<endl;
        if (Name)
            delete []Name;
    }
private:
    int age;
    char* Name;
};
class Teacher:public CEmployee
{
public:
    Teacher();
    Teacher(int age, char* name, char* kk);
    ~Teacher();
private:
    char* course;
};
Teacher::Teacher()
{
    course=NULL;
}
Teacher::Teacher(int age, char* name, char* kk):CEmployee(age,name)
{
    int length=strlen(kk)+1;
    course = new char[length];
    strcpy(course,kk);
}
Teacher::~Teacher()
{
    cout<<"Destruct Teacher"<<endl;
    if (course)
        delete []course;
}
int main()
{
    CEmployee *a[3];
    a[0]=new CEmployee(28,"lin");
    a[1]=new Teacher(20,"xu","Science");
    a[2]=new Teacher(26,"hh","math");
    for(int i=0;i<3;i++)
        delete a[i];
}
