#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "tree.h"

using namespace std;

int main() {
    Tree<int>* tree = new Tree<int>();

    auto proc = [](int x) { cout << x << " "; };

    srand(time(0));
    for (int i = 0; i < 20; ++i) {
        int randomNumber = rand() % 100;
        proc(randomNumber);
        tree->add(randomNumber);
    }
    cout << endl;
    tree->preorder(proc); cout << endl;
    tree->postorder(proc); cout << endl;
    tree->inorder(proc); cout << endl;

    delete tree;
    system("pause");
    return 0;
}