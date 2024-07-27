#include <iostream>
#include <vector>

#include "header.h"

void sortedSquares(){
    std::vector<int> givenNums = {-10,-5,-4,-3,-2,-1,0,1,1,7};
    std::vector<int> sqrNums(givenNums.size());
    int index = 0, lastIndex = 0, sorted = 1, currentNum = 0;
    int numsLength = (int)(givenNums.size());
    lastIndex = numsLength;

    for(int num : givenNums){
        sqrNums[index] = num * num;
        index++;
    }

    std::cout << numsLength << std::endl;

    for(int num : sqrNums){
        std::cout << num << " ";
    }
    
    while(sorted != numsLength){
        for(int i = 0; i <= lastIndex; i++){
            if(i+1 < numsLength && sqrNums[i] >= sqrNums[i+1]){
                currentNum = sqrNums[i];
                sqrNums[i] = sqrNums[i+1];
                sqrNums[i+1] = currentNum;
            }
            else{
                lastIndex = i;
                sorted++;
            }
            std::cout << sorted << std::endl;
        }
    }

    for(int num : sqrNums){
        std::cout << num << " ";
    }
}