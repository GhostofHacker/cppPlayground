#include <iostream>
#include <vector>
#include <algorithm>

#include "header.h"

std::vector<int> add(std::vector<int>& numsBig, int n, std::vector<int>& numsSmall){
    int k = 0, capacity = ((int)numsBig.capacity());
    for(int i = n; i < capacity; i++){
        if(numsBig[i] == 0){
            numsBig[i] = numsSmall[k];
            k++;
        };
    };
    return numsBig;
}

void mergeVectors(){
    std::vector<int> nums1 = {-1,0,0,3,3,3,0,0,0};
    std::vector<int> nums2 = {1,2,2};
    int n = 6, m = 3, k = 0;
    
    nums1 = add(nums1, n, nums2);

    sort(nums1.begin(), nums1.end());

    for(int num : nums1){
        std::cout << num << " ";
    }
}