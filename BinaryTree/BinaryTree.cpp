#include<iostream>
#include<stack>
using namespace std;
#include "BinaryTree.h"
#include "Queue.h"

BinaryTree::BinaryTree() {
    this->root = 0;
}

BinaryTree::~BinaryTree() {
    this->root = 0;
}

void BinaryTree::CreateTree() {
    //Data Structure
    Node* ptr; //traveller
    Node* temp; //creator
    int x; //guide = user will be the guide and -1 means no child
    Queue* q = new Queue(100); //storer

    //Initial Setup Step
    cout << "Enter root element: " << endl;
    cin >> x;
    temp = new Node;
    temp->val = x;
    temp->left = temp->right = 0;
    //initialize root
    this->root = temp;
    ptr = temp;
    q->enqueue(ptr);

    //Repeating Step until the storer is not empty
    while(!q->isEmpty()) {
        //game begines. Dequeue: Ask for each node's left child and push the newly created child. Ask for each node's right child
        ptr = q->dequeue();
        cout << "Enter left child of " << ptr->val << endl;
        cin >> x;
        if(x!=-1) {
            temp = new Node;
            temp->val = x;
            temp->left = temp->right = 0;
            q->enqueue(temp);
            ptr->left = temp;
        }
        cout << "Enter right child of " << ptr->val << endl;
        cin >> x;
        if(x!=-1) {
            temp = new Node;
            temp->val = x;
            temp->left = temp->right = 0;
            q->enqueue(temp);
            ptr->right = temp;
        }
    }
}

void BinaryTree::PreOrder(Node* p) {
    if(p) {
        cout << p->val << " ";
        PreOrder(p->left);
        PreOrder(p->right);
    }
}

void BinaryTree::PreOrder_R() {
    PreOrder(this->root);
}

void BinaryTree::InOrder(Node* p) {
    if(p) {
        InOrder(p->left);
        cout <<  p->val << " ";
        InOrder(p->right);
    }
} 

void BinaryTree::InOrder_R() {
    InOrder(this->root);
}

void BinaryTree::PostOrder(Node* p) {
    if(p) {
        PostOrder(p->left);
        PostOrder(p->right);
        cout << p->val << " ";
    }
}

void BinaryTree::PostOrder_R() {
    PostOrder(this->root);
}

void BinaryTree::LevelOrder() {
    /*
        Level Order: Tree is filled Level By Level; Just Like Creation of Tree - Queue is used
    */
    //Setup
    Node* ptr; //traveller
    Queue* q = new Queue(100); //storer; Algo finishes when Storer is empty

    //Initialization of Setup
    ptr = this->root;
    q->enqueue(ptr);

    //Repeating Step
    while(!q->isEmpty()) {
        ptr = q->dequeue();
        cout << ptr->val << " ";
        if(ptr->left) {
            q->enqueue(ptr->left);
        }
        if(ptr->right) {
            q->enqueue(ptr->right);
        }
    }
}

void BinaryTree::PreOrder_I() {
    /*
        - Iterative and Tree Traversal - Stack Will Be Used
    */
   //setup
    stack<Node*> stk; //storer
    Node* ptr; //traveller
    //==>Algo finishes when both traveller and storer are null and empty respectively
    //initialization
    ptr = this->root;

    while(ptr != 0 || !stk.empty()) {
        if(ptr!=0) {
            cout << ptr->val << " ";
            stk.push(ptr);
            ptr = ptr->left;
        } else {
            ptr = stk.top();
            stk.pop();
            ptr = ptr->right;
        }
    }
}

void BinaryTree::InOrder_I() {
    //setup
    Node* ptr=0; //traveller
    stack<Node*> stk; //storeror

    //initialization of setup
    ptr = this->root;
    while(ptr != 0 || !stk.empty()) {
        if(ptr!= 0) {
            stk.push(ptr);
            ptr = ptr->left;
        } else {
            ptr = stk.top();
            cout << ptr->val << " ";
            stk.pop();
            ptr = ptr->right;
        }
    }
}

