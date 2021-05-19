#include <iostream>

using namespace std;

class Person {
protected:
    string name;
    int year_of_birth;
public:
    Person(const string& name, int year_of_birth) : name{name}, year_of_birth{year_of_birth}{};
    ~Person(){};
    virtual void print(ostream&os) const{
        cout << "name: " << name << endl;
        cout << "year_of_birth: " << year_of_birth << endl;
    }
};

class Worker : public Person {
protected:
    double salary;
public:
    Worker(const string& name, int year_of_birth, double salary) : Person(name, year_of_birth), salary{salary}{};
    ~Worker(){};
    void print(ostream& os) const{
        Person::print(os);
        cout << "Salary: " << salary << endl;
    }
    double get_salary() const;
};

class Manager : public Worker {
    string dept;
public:
    Manager(const string& name, int year_of_birth, double salary, const string& dept) : Worker(name, year_of_birth, salary), dept{dept}{};
    ~Manager(){};//ok
    void print(ostream& os) const{
        Worker::print(os);
        cout << "dept: " << dept << endl;
    };
    string get_dept() const;


};
ostream& operator<<(ostream& os, const Person& o){
    o.print(os);
    return os;
};

int main() {
    Person p("Szymon", 2001);
    Worker w("Szymon", 2001, 999.99);
    Manager m("Szymon", 2001, 999.99, "cos");
    p.print(cout);
    cout << "=============================" << endl;
    w.print(cout);
    cout << "=============================" << endl;
    m.print(cout);
    cout << "=============================" << endl;

    return 0;
}
