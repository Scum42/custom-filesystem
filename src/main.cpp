#include <iostream>
using namespace std;

#include "options.h"

int main(int argc, char *argv[])
{
    vector<Option> options = parseOptions(argc, argv);

    for each (Option op in options)
    {
        cout << "Option: " << op.name << "\n";
        cout << "Value:  " << op.value << "\n\n";
    }
}
