#include <iostream>

using namespace std;

class x
{
    char name[50];
    int age;
    int rollno;
    public:
    void getdata(void);
    void putdata(void);
    
};

void x::getdata(void)
{
    cout<<"\nEnter the name of student :";
    cin>>name;
    cout<<"\nEnter the age of the student :";
    cin>>age;
    cout<<"\nEnter the Roll no of the student :";
    cin>>rollno;
}

void x::putdata(void)
{
    cout<<"\nEntered name is: "<<name;
    cout<<"\nEntered age is: "<<age;
    cout<<"\nEntered rollno is: "<<rollno;
}
const int size=3;

int main()
{
    x emp[size];
    int i,n;
    cout<<"Number of Students =";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"\nEnter details of student number "<<i+1;
        emp[i].getdata();
        
    }
    for(i=0;i<n;i++)
    {
        cout<<"\nDetails of the student number "<<i+1;
        emp[i].putdata();
        
    }
    
    return 0;
}

