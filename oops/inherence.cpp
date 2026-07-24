#include <iostream>
using namespace std;
class Human
{
    string Religion, color;
    protected:
    string name;
    int age, weight;
};

class student : public Human
{
private:
    int roll_number, fees;
    student(string name, int age, int weight, int roll_number, int fees)
    {

        this->name = name;
        this->age = age;
        this->weight = weight;
        this->roll_number = roll_number;
        this->fees = fees;
    }
};

main()
{

    return 0;
}