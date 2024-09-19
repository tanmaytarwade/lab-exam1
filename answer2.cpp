/*Write a C++ program to accpet worker information Worker_Name, No_Of_Hours_Worked,
Pay_Rate and Salary. Write necessary functions to calculate and display the salary of Worker. (Use
Default values for Pay_Rate Rs. 500 per hours)*/
#include <iostream>
#include <string>

using namespace std;

class Worker {
private:
    string workerName;
    int hoursWorked;
    double payRate;
    double salary;

public:
   
    Worker(string name, int hours, double rate = 500.0) 
    {
    	workerName = name;
    	hoursWorked = hours;
    	payRate = rate;
    }


    void calculateSalary() {
        salary = hoursWorked * payRate;
    }


    void displayInfo() {
        cout << "Worker Name: " << workerName << endl;
        cout << "Hours Worked: " << hoursWorked << endl;
        cout << "Pay Rate: Rs. " << payRate << endl;
        cout << "Salary: Rs. " << salary << endl;
    }
};

int main() {
    string name;
    int hours;
    double rate;


    cout << "Enter Worker Name: ";
    getline(cin, name);
    cout << "Enter Number of Hours Worked: ";
    cin >> hours;
    Worker w1(name, hours); 
    w1.calculateSalary();
     w1.displayInfo();
    
    

    return 0;
}