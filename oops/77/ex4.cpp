#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream fout;
    fout.open("ex4.txt");
    fout << "hello india \n";
    fout << "hello india \n";
    fout << "hello india \n";
    fout.close();
    ifstream fin;
    fin.open("ex4.txt");
    string line;
    while (getline(fin,line ))
    {
        cout<<line<<endl;
    }
    fout.close();
    

    return 0;
}   