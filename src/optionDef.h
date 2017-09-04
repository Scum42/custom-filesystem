#ifndef optionDef_h
#define optionDef_h

#include <map>
#include <bitset>

enum OptionTypes
{
    O_HELP = 0,
    O_FILENAME,

    NUM_OPTIONS
};

const char OPTION_CHARS[NUM_OPTIONS] =
{
    '?',
    'f'
};

class OptionData
{
public:
    static std::bitset<NUM_OPTIONS> opFlags;
    static std::map<char, std::string> opValues;
};

#endif
