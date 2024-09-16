#include <iostream>
#include <vector>
#include <algorithm>

#include "header.h"

//The below code works but it compute is longer. O(n²)
std::vector<int> disappearedNumsLong(std::vector<int> nums){
    std::vector<int> disappearedNumbers;
    int i = 0, checker = 1, n = (int)nums.size();
    while(checker < n + 1){
        if(i < nums.size() && nums[i] == checker){
            nums.erase(nums.begin() + i);
            i = -1;
            checker++;
        }
        if(i >= (int)nums.size()){
            disappearedNumbers.insert(disappearedNumbers.end(), checker);
            checker++;
            i = -1;
        }
        i++;
    }
    
    return disappearedNumbers;
}

//The below code also works but it compute is less longer. O(n log n)
std::vector<int> disappearedNumsShort(std::vector<int> nums){
    std::vector<int> disappearedNums;
    int checker = 1, i = 0;
    std::sort(nums.begin(), nums.end());
    if(i < (int)nums.size() && nums[0] != checker){
        disappearedNums.insert(disappearedNums.end(), checker);
        checker++;
        i++;
    }
    else{
        checker++;
        i++;
    }
    for(; i < (int)nums.size(); i++){
        if(nums[i] == nums[i-1]) i++;
        if(nums[i] != checker){
            disappearedNums.insert(disappearedNums.end(), checker);
            checker++;
            i--;
        }
        else{
            checker++;
        }
    }

    return disappearedNums;
}