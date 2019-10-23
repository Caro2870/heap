#include <iostream>
#include <string>
#include <vector>

#include "tree.h"

using namespace std;

class Book {
    string name;
    int year;
    float score; // good reads

public:
    Book(string name, int year, float score)
        : name(name), year(year), score(score) {}

    string getName() { return name; }
    int getYear() { return year; }
    float getScore() { return score; }

    void setname(string name) { this->name = name; }
    void setyear(int year) { this->year = year; }
    void setscore(float score) { this->score = score; }
};

int main() {
    typedef Tree<Book*, string, nullptr> TreeStr;
    typedef Tree<Book*, int, nullptr> TreeInt;
    typedef Tree<Book*, float, nullptr> TreeFlt;

    vector<Book*> books;
    books.push_back(new Book("Moby Dick", 1851, 4.2));
    books.push_back(new Book("Kokito", 2019, 5));
    books.push_back(new Book("El Principito", 1943, 4.3));
    books.push_back(new Book("Sangre de campeón", 2001, 3));
    books.push_back(new Book("El rey palido", 2011, 4.0));
    books.push_back(new Book("Boveda de acero", 1954, 5));
    books.push_back(new Book("La ciudad y los perros", 1963, 4.5));

    auto l1 = [](Book* a) { return a->getName(); };
    auto l2 = [](Book* a) { return a->getYear(); };
    auto l3 = [](Book* a) { return a->getScore(); };

    TreeStr* nameTree = new TreeStr(l1);
    TreeInt* yearTree = new TreeInt(l2);
    TreeFlt* scoreTree = new TreeFlt(l3);

    for (auto book : books) {
        nameTree->add(book);
        yearTree->add(book);
        scoreTree->add(book);
    }

    auto prnt = [](Book* a) {
        cout << "{"
            << a->getName() << ", "
            << a->getYear() << ", "
            << a->getScore() << "}\n";
    };
    nameTree->inorder(prnt); cout << "-----------------------==\n";
    yearTree->inorder(prnt); cout << "-----------------------==\n";
    scoreTree->inorder(prnt); cout << "-----------------------==\n";

    prnt(nameTree->find("El rey palido"));
    prnt(yearTree->find(2011));
    prnt(scoreTree->find(4.5));

    delete nameTree;
    delete yearTree;
    delete scoreTree;
    system("pause");
    return 0;
}