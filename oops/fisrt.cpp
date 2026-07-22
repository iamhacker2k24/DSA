#include <iostream>
using namespace std;
class student
{
    // by defauklt is is privet , out side of call we didi not us ethis
    string name;
    int roll=-1;

public:
    void setrole(int rolee)
    {
        if(rolee==0){
            cout<<"invaild role \n";
            return;
        }

        roll = rolee;
    }
    void printroll()
    {
        cout << roll << endl;
    }
};
int main()
{
    student s1;
    s1.setrole(0);
    s1.printroll();
    return 0;
}