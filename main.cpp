#include <cmath>
#include <cstdio>
#include <vector>
#include <array>
#include <iostream>
#include <algorithm>
using namespace std;

class Person
{
protected:
    int age, cur_id;
    string name;

public: 
    Person();
    // virtual ~Person() = 0;
    virtual void getdata() = 0;
    virtual void putdata() = 0;
};

Person::Person()
{
    age = cur_id = 0;
    name = "";
}

class Professor : public Person
{
private:
    int publications;
    static int idGenerator;

public:
    Professor();
    void getdata();
    void putdata();

    static int generateID();

};

int Professor::idGenerator = 1;

int Professor::generateID()
{
    return idGenerator++;
}

Professor::Professor() : Person()
{
    publications = 0;
    cur_id = Professor::generateID();
}

void Professor::getdata()
{
    cin >> name;
    cin >> age;
    cin >> publications;
}

void Professor::putdata()
{
    cout << name << " ";
    cout << age << " ";
    cout << publications << " ";
    cout << cur_id << endl;
}

class Student : public Person
{
private:
    array<int, 6> marks;
    static int idGenerator;

    int sumOfMarks();

public:
    Student();
    void getdata();
    void putdata();

    static int generateID();
};

int Student::idGenerator = 1;

int Student::generateID()
{
    return idGenerator++;
}

Student::Student() : Person()
{
    cur_id = Student::generateID();
}

void Student::getdata()
{
    cin >> name;
    cin >> age;
    for (size_t i = 0; i < 6; i++)
    {
        cin >> marks[i];
    }
}

void Student::putdata()
{
    cout << name << " ";
    cout << age << " ";
    cout << sumOfMarks() << " ";
    cout << cur_id << endl;
}

int Student::sumOfMarks()
{
    int sum = 0;
    for (int mark : marks)
    {
        sum += mark;
    }
    return sum;
}


int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
