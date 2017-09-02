#include "options.h"
using namespace std;

// Helper functions

bool isShortOption(string str)
{
    return
        str.length() >= 2 &&
        str[0] == '-' &&
        str[1] != '-';
}

bool isLongOption(string str)
{
    return
        str.length() >= 3 &&
        str[0] == '-' &&
        str[1] == '-' &&
        str[2] != '-';
}

bool isOption(string str)
{
    return isShortOption(str) || isLongOption(str);
}

string trimDashes(string str)
{
    while (str.length() > 0 && str[0] == '-')
    {
        str = str.substr(1);
    }

    return str;
}

// Parser

vector<Option> parseOptions(int argc, char *argv[])
{
    vector<Option> options;
    vector<string> args;

    // First convert argv to a vector for ease of use
    for (int i = 0; i < argc; i++) args.push_back(argv[i]);

    for (int i = 0; i < args.size(); i++)
    {
        // The current and next arguments as supplied by Windows
        string current = args[i];
        string next = i + 1 < args.size() ? args[i + 1] : "";

        // If the current string is a short option and is more than two characters...
        if (isShortOption(current) && current.length() > 2)
        {
            current = trimDashes(current);

            // ...then this is multiple combined options, which means we don't need to worry about arguments.
            for each (char c in current)
            {
                Option op;
                op.name = c;
                op.value = "";
                options.push_back(op);
            }
        }
        // If it is a one-character option or a long option, there might be an argument.
        else if (isOption(current))
        {
            current = trimDashes(current);

            Option op;
            op.name = current;
            op.value = "";

            // If the next thing isn't an option, then it is an argument.
            if (!isOption(next) && next != "")
            {
                op.value = next;

                // Increment the counter, because we've already processed the next one.
                i++;
            }

            options.push_back(op);
        }
        // If it isn't an option at all, it's just some junk.
        else
        {
            Option op;
            op.name = "";
            op.value = current;
            options.push_back(op);
        }
    }

    return options;
}
