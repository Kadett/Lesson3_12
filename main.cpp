#include <iostream>
#include <ctime>
#include "src/BinTree.h"


int main() {
    // Task 1
    BinTree t;
    t.insert(50);
    t.insert(60);
    t.insert(70);
    t.insert(40);
    t.insert(30);
    std::cout << (t.isBalance() ? "Tree is balanced" : "Tree is not balanced") << "\n\n";



    //Task 2 and Task 3
    srand(time(0));
    const int size = 50;
    int count = 0;
    for (int i = 0; i < size; ++i) {
        BinTree t;
        while (t.getSize() < 10000) {
            t.insert(rand());
        }
        if(t.isBalance()) count++;
    }
    std::cout << "balanced trees " << (double) count * 100 / size << "%" << "\n\n";

    // Task 4
    BinTree t1;
    t1.insert(10);
    t1.insert(11);
    t1.insert(12);
    t1.insert(9);
    t1.insert(5);
    t1.insert(3);
    t1.insert(15);
    bool res = t1.search(17);
    std::cout << (res ? "Value found" : "Value not found");



    return 0;
}
