#include <iostream>
#include <vector>

#include "header.h"

void duplicateZeros(std::vector<int> arr){
    int duplicateArr[((int)arr.size())];
    int f = 0, arrLength = (int)arr.size();

    for(int s = 0; s < arrLength;){
        if(arr[f] == 0){
            duplicateArr[s] = 0;
            if(s+1 != arrLength){
                duplicateArr[s+1] = 0;
            }
            f++;
            s = s + 2;
        }
        else{
            duplicateArr[s] = arr[f];
            f++;
            s++;
        }
    }

    for(int num : duplicateArr){
        std::cout << num << " ";
    }
}