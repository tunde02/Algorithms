// not yet

#include <iostream>
using namespace std;

int n;

class Node {
  public:
    Node* parent;
    Node* left;
    Node* right;
    Node() : parent(nullptr), left(nullptr), right(nullptr) {};
};

class Tree {
  public:
    Node* root;
};

void calcTree(Tree* tree, int n) {
    
}

void printTree(Node node) {
    if(node.left) {
        cout << "(";
        printTree(node.left);
        cout << ")";
    }

    cout << "X";

    if(node.right) {
        cout << "(";
        printTree(node.right);
        cout << ")";
    }
}

int main() {
    cin >> n;

    Tree tree;

    return 0;

}