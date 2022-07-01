#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person
{
private:
    int age, cur_id;
    string name;

public: 
    Person(){};
    virtual void getData() = 0;
    virtual void putData() = 0;
};

class Professor : public Person
{
private:
    int publications;
    static int idGenerator;

public:

    void getData();
    void putData();
};

int Professor::idGenerator = 1;

class Student : public Person
{
private:
    vector<int> marks;
    static int idGenerator;

public:
    void getData();
    void putData();
};

int Student::idGenerator = 1;

int main()
{
    return 0;
}

// int main(){

//     int n, val;
//     cin>>n; //The number of objects that is going to be created.
//     Person *per[n];

//     for(int i = 0;i < n;i++){

//         cin>>val;
//         if(val == 1){
//             // If val is 1 current object is of type Professor
//             per[i] = new Professor;

//         }
//         else per[i] = new Student; // Else the current object is of type Student

//         per[i]->getdata(); // Get the data from the user.

//     }

//     for(int i=0;i<n;i++)
//         per[i]->putdata(); // Print the required output for each object.

//     return 0;

// }
