#ifndef options_h
#define options_h

#include <string>
#include <vector>

// Option struct
struct Option
{
    // The name of the option (which is usually one character).
    std::string name;
    // The value or values it contains (which is usually nothing).
    std::string value;
};

// Parser
std::vector<Option> parseOptions(int argc, char *argv[]);

#endif
