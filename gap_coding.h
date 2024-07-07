#ifndef GAP_CODING_H
#define GAP_CODING_H

#include <vector>

struct Sample {
    std::vector<int> values; 
    int gap;
};
std::vector<int> gap_coding(const std::vector<int>& arr);
int binary_search_gap_coded(const std::vector<int>& gc, const Sample& sample, int x);

#endif // GAP_CODING_H
