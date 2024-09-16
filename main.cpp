#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include "tests/header.h"

void beforeDiv(){
    float i = 1.0, k = 2.0;
    for(; k <= 1001; k++){
        cout << i / k << " ";
        i++;
    }
}

int main(){
    runPlayground();
    return 0;
}