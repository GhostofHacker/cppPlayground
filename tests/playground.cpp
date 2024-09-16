//This file meant for trying out ideas and lerning.
#include <iostream>
#include <map>
#include <string>
#include <time.h>
#include <vector>

void expPointers() {
    int x = 12;
    int y = 20;

    int * pX = &x;
    // int pY = &y; you cannot add a adress to a regular int a pointer will hold hex value. 0x008fec is not a int, its a type of int

    std::cout << "The x is:" << x << std::endl; // Ouput's x
    std::cout << "The y is:" << y << std::endl; // Ouput's y

    std::cout << "The pX is:" << pX << std::endl;   // Output's x adress in memory 0x01008e and such
    std::cout << "The &x is:" << &x << std::endl;   // Output's x adress in memory same us the upper line.
    std::cout << "The *pX is:" << *pX << std::endl; // Output's x value
    // std::cout << "The **pX is:" << **pX << std::endl; You can't output anything from here.
    std::cout << "The &pX is:" << &pX << std::endl; // Output's pX adress in memory, it differs from the x's adress because pX also has a place in memory
}

void expPointers_2() {
    //Trying excercises given by ChatGPT

    //Declare a pointer:
    int intVar = 42;
    int* intPtr = &intVar;
    std::cout << "Value of intVar is: " << *intPtr << std::endl;

    //Modify a value through a pointer
    *intPtr = 100;
    std::cout << "Modified value of intVar is: " << *intPtr << std::endl;

    //Declare a refence
    int num = 10;
    int& refNum = num;
    std::cout << "Value of num is: " << num << std::endl;
    std::cout << "Value of refNum is:" << refNum << std::endl;

    //Modify a value through a refence
    refNum = 20;
    std::cout << "After modifiying refNum the value of num is:" << num << std::endl;

    //The rest made no sense to me so I left here. 
}

void expPointers_3() {
    // The code below is from a website I found. It takes a string as a char array and stores it then we give a pointer to array then look up the values. 
    // char str[] = "A string";
    // char *pc = str;
    // std::cout << str[0] <<' '<< *pc <<' '<<pc[3]<<"\n";
    // pc += 2;
    // std::cout <<*pc<<' '<< pc[2] <<' '<< pc[5];

    //Write a program to print the address of a variable whose value is input from user.
    int givenNum;
    int *pGivenNum = &givenNum;
    std::cout << "Write a number:";
    std::cin >> givenNum; 
    std::cout <<"\n The adress of given number is: " << pGivenNum << std::endl;
}

void expStructs() {
    //This was a leetcode problem. 
    //Under is a Linked List. It works very basicly:
    //There is a node that holds two value: one for to data to store and the other to point to other node(an adress).
    //This is way more efficient to an array, that's way we use it. 
    struct ListNode {
        int val;
        ListNode *next;
        //Below are the possible constructers we declared, not funtion for a function you just write like a normal fucntion.
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {} 
    };


    int size = 10;
    ListNode nums[size];
    nums[0].val = 1;
    std::cout << nums[0].val << " ";
    for(int i = 1; i < size; i++){
        nums[i] = ListNode(i+1);
        nums[i-1].next = &nums[i];
        std::cout << nums[i].val << " ";
    }

    //You don't have to store data as you see middle pointer will hold the last adress it's been to. In this case
    //it's been to the middle of the linked list. Thus if we leave it there middle will be in the middle of the list 
    //and will be pointing to next element.
    short int length = 0;
    ListNode *head = &nums[0];
    ListNode *middle = head;
    while (head != nullptr && head->next != nullptr)
    {
        middle = middle->next;
        head = head->next->next;
    }

    std::cout << "\n" << middle->val << std::endl;

}

void printHashMap(const std::string message, const std::map<int, std::string> &m){
    std::cout << message << std::endl;
    for(const auto& [key, value] : m){
        std::cout << key << ":" << value << std::endl;
    }
}

void expHashMaps(){
    srand((unsigned int)time(NULL));
    //This time around I'll be learning about HashMaps!
    //In general hashmap is a cool very fast data getting thing.
    //There is a key, value, bucketlist and hashcode. 
    //A key is the key of the given value like a student's name is a value and it's school number is key.
    //All keys and value are stored in a hashmap. HashCode does some cool shit and places values by their key in this map.
    //It works as 221 and 111 being two different keys but HashCode will indicate them as 1 and 1 thus they collide in the space
    //where theye will be placed thus creating bucketlist which is a linked list!
    //Why is there a collision because HasCode uses hashmap's size and divedes the keys so it can place them inside of it. Like each
    //1 being in the same 1!

    std::map<std::string, int> nameMap{{"Jack", 5}, {"Finn", 10}, {"Skelta", 15}};
    nameMap.insert({"Gaya", 25});
    std::cout << nameMap["Jack"] << std::endl;
    std::cout << nameMap["Gaya"] << std::endl;


    std::map<int, std::string> classB;
    std::string students[10] = {"Jack", "Daniel", "Finn", "Hade", "Elinora", "PatoKing", "Onizuka", "Kayo", "Saitama", "Gensi"};

    for(std::string student : students){
        classB.insert({rand() %1000, student});
    }

    printHashMap("Students of Class B", classB);
}


bool expLeetCodeHashMap(std::string ransomNote, std::string magazine){
    std::map<short int, char> checkerMap;
    int canConstruct = 0;
    short int mag_i = 0;
    for(char magazineChar : magazine){
        checkerMap.insert({mag_i, magazineChar});
        mag_i++;
    }

    for(char ransomChar : ransomNote){;
        for(const auto& [key, value] : checkerMap){
            if(ransomChar == checkerMap[key]){ 
                checkerMap.erase(key);
                canConstruct++;
            }
        }
    }

    if(canConstruct == ransomNote.length()){
        return true;
    }
    else{
        return false;
    }
}

int appendCharacter(std::string s, std::string t){
    int sPlace = 0, tPlace = 0, finalPlace;
    for(; sPlace < s.length(); sPlace++){
        std::cout << "t:" << tPlace << std::endl;
        std::cout << "s:" << sPlace << " "; 
        for(; tPlace < t.length(); tPlace++){
            std::cout << "t:" << tPlace << " ";
            if(s.at(sPlace) == t.at(tPlace)){ 
                std::cout << "checked!" << std::endl;
                tPlace++;
                finalPlace = sPlace;
                break; 
            }
        }
        
    }   
    
    std::cout << "\n final:" << finalPlace << std::endl;
    std::cout << "tPlace:" << tPlace << std::endl;
    return (finalPlace + 1 == s.length()) ? 0 : s.length() - (finalPlace + 1);
}


//I believe the code below is wrong. Because cards are suppose to be in continues order. 
bool isNStraightHand(std::vector<int> hand, int groupSize) {
    return (hand.size() % groupSize == 0) ? true : false;
}


//https://www.youtube.com/watch?v=otaOQJ61QP8&ab_channel=STEMwithProf.Erickson checkout the fourt example

void runPlayground() {
    std::vector<int> hand {8, 10, 12}; 
    int groupSize = 3;
    
    std::cout << isNStraightHand(hand, groupSize);
}
