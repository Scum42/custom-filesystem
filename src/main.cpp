#include <iostream>
using namespace std;

#include "options.h"

int main(int argc, char *argv[])
{
    auto options = parseOptions(argc, argv);

    for each (auto iter in options)
    {
        cout << iter.first << endl;
        cout << iter.second << "\n\n";
    }
}
