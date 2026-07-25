#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // file ko open
    ofstream fout;
    fout.open("zoom.doc"); // if this file  absent then create this file auto matically
    fout << "hello dfv India";

    fout.close();

    return 0;
}