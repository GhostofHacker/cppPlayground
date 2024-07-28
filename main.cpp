#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include "tests/header.h"

vector<int> add(vector<int>& numsBig, int n, vector<int>& numsSmall){
    int k = 0, capacity = ((int)numsBig.capacity());
    for(int i = n; i < capacity; i++){
        if(numsBig[i] == 0){
            numsBig[i] = numsSmall[k];
            k++;
        };
    };
    return numsBig;
}


int main(){
    //std::vector<int> arr = {0, 1, 0, 3, 5, -2, 20, 0, 0, 0, 1};
    //duplicateZeros(arr);
    return 0;
}