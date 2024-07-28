#include <iostream>
#include <vector>
#include <algorithm>

#include "header.h"

void sortedSquaresLong(){
    std::vector<int> givenNums = {-10,-5,-4,-3,-2,-1,0,1,1,7};
    std::vector<int> sqrNums(givenNums.size());
    int index = 0, lastIndex = 0, sorted = 1, currentNum = 0;
    int numsLength = (int)(givenNums.size());
    lastIndex = numsLength;

    for(int num : givenNums){
        sqrNums[index] = num * num;
        index++;
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
        }
    }

    for(int num : sqrNums){
        std::cout << num << " ";
    }
}

void sortedSquaresShort(){
    std::vector<int> givenNums = {-10,-5,-4,-3,-2,-1,0,1,1,7};
    std::vector<int> sqrNums;

    for(int num : givenNums){
        sqrNums.insert(sqrNums.end(), (num * num));
    }

    sort(sqrNums.begin(), sqrNums.end());
    
    for(int num : sqrNums){
        std::cout << num << " ";
    }
    std::cout << "\n\n";
}

void squareSort(){
    std::cout << "\n" << "Custom Sorting Algorithm:" << std::endl;
    sortedSquaresLong();

    std::cout << "\n\n" << "Standalone Sorting Algorithm:" << std::endl;
    sortedSquaresShort();
}