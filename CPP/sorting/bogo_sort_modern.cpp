#include <array>
#include <algorithm>
#include <random>

#include <iostream>
#include "assert.h"

template<class RandomIt>
void bogo_sort(RandomIt first, RandomIt last){
    //make the random number generator
    std::random_device rd;
    std::mt19937 g(rd());

    while(!std::is_sorted(first, last)){
        std::shuffle(first, last, g);
    }
}


int main(void){
    std::array<int,6> test {1,5,6,2,-1,3};

    bogo_sort(test.begin(), test.end());

    //print the list
    for(auto i=0; i<test.size(); ++i){
        std::cout << test[i] << ", ";
    }

    //verify it is sorted
    assert(std::is_sorted(test.begin(), test.end()));
}
