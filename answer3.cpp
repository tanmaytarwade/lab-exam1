#include<iostream>
using namespace std;
/*Write a program create employee class with members variable as EmpId,Name of Employee and
Salary. For 10 Employees
Print list of all employees.
Print list of employee who got heights salary.*/
class employee
{
    private:
    string name;
    int idno;
    int salary;
    public:
    void create_human(string n,int id,int s)
    {
        cout<<"\nconstructor called...";
        name=n;
        idno=id;
        salary=s;
        cout<<"\nemployee with name "<<name<<"created.";
        cout<<"\nid no is:"<<idno;
        cout<<"\nsalary :"<<salary;
    }
    void print_human()
    {
        cout<<"\nid no:"<<idno<<"\t Name:"<<name;
    }
    
 
    
};

int main()
{
cout<<"Enter number of employee:";
int max;
 int n,i;
 cin>>n;
 employee h[n];

 for(i=0;i<n;i++)
    {
        
        string name;
        int idno;
        int salary;
        cout<<"\nName:";
        cin>>name;
        cout<<"\nID:";
        cin>>idno;
        cout<<"\nsalary";
        cin>>salary;
        h[i].create_human(name,idno,salary);
    }
cout<<"List of employee are:\n";
 for(i=0;i<n;i++)
     {
     h[i].print_human();
     }

     
 return 0;
}