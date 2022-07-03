// g++ -O2 -std=c++17 -pthread -I../common 03_measure_container_access.cpp ../common/profiler.cpp
//

#include <algorithm>      // std::find
#include <list>           // std::list
#include <set>            // std::set
#include <unordered_set>  // std::unordered_set
#include <vector>         // std::vector
#include <stdlib.h>       // rand
#include "fast_mutex.h"   // nvwa::fast_mutex
#include "profiler.h"     // PROFILE_CHECK

enum profiled_functions {
    PF_FIND_VECTOR,
    PF_FIND_LIST,
    PF_FIND_MULTISET,
    PF_FIND_UNORDERED_MULTISET,
};

name_mapper name_map[] = {
    {PF_FIND_VECTOR, "find(vector)"},
    {PF_FIND_LIST, "find(list)"},
    {PF_FIND_MULTISET, "find(multiset)"},
    {PF_FIND_UNORDERED_MULTISET, "find(unordered_multiset)"},
    {-1, NULL}};

#define LEN 10000
#define LOOPS 10000

int main()
{
}
