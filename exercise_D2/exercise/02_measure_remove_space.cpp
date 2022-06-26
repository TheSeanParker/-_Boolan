// g++ -O2 -std=c++17 -pthread -I../common 02_measure_remove_space.cpp ../common/profiler.cpp
//

#include <string>        // std::string
#include <ctype.h>       // isspace
#include "fast_mutex.h"  // nvwa::fast_mutex
#include "profiler.h"    // PROFILE_CHECK

enum profiled_functions {
    PF_REMOVE_SPACE,
};

name_mapper name_map[] = {
    {PF_REMOVE_SPACE, "remove_space"},
    {-1, NULL}};

std::string remove_space(std::string s)
{
    PROFILE_CHECK(PF_REMOVE_SPACE);
    std::string result;
    for (size_t i = 0; i < s.length(); ++i) {
        if (!isspace(s[i])) {
            result = result + s[i];
        }
    }
    return result;
}

std::string result;
nvwa::fast_mutex mutex;

#define LOOPS 1000000

int main()
{
    std::string input = "Hello world Hello world Hello world Hello world";

    for (int i = 0; i < LOOPS; ++i) {
        nvwa::fast_mutex_autolock guard(mutex);
        result = remove_space(input);
    }
}
