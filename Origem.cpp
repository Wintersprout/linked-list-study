#include <iostream>
using namespace std;

class node {
private:
    node* link;

public:
    int data;

    node(int x) {
        this->data = x;
        this->link = NULL;
    }

    void setLink(node* next) {
        this->link = next;
    }

    node* getLink() {
        return this->link;
    }
};

int main() {
    node a(1);
    node b(2);
    node c(3);

    a.setLink(&b);
    b.setLink(&c);
    c.setLink(&a);

    cout << a.getLink()->data << " " << b.getLink()->data << " " << c.getLink()->data;
}