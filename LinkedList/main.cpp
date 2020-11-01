#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

//make it global so that every function can have access to it.
Node* first=NULL;

void create(int A[], int n) {
    int i;
    Node* t, *last;
    first = new Node();
    first->data = A[0];
    first->next = NULL;
    last = first;

    //rest i will create using for loop
    for(int i=1;i<n;i++) {
        //node is created
        t = new Node();
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display_iterative(Node* ptr) {
    cout << "Displaying - Iterative." << endl;
    while(ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

/*
Number of Call = n+1
Stack Space = n+1
*/

//Tail Recursion
void display_recursive(Node* ptr) {
    if(ptr != 0) {
        cout << ptr->data << " ";
        display_recursive(ptr->next);
    }
}

//Head Recursion
void display_reverse_recursive(Node* ptr) {
    if(ptr != 0) {
        display_recursive(ptr->next);
        cout << ptr->data << " ";
    }
}

int length_iterative(Node* ptr) {
    int count = 0;
    while(ptr) {
        count++;
        ptr = ptr->next;
    }
    return count;
}

int length_recursive(Node* ptr) {
    if(ptr==0) {
        return 0;
    }
    return 1 + length_recursive(ptr->next);
}

int sum_iterative(Node* ptr) {
    int sum = 0;
    while(ptr) {
        sum += ptr->data;
        ptr=ptr->next;
    }
    return sum;
}

int sum_recursive(Node* ptr) {
    if(ptr == 0) return 0;
    else return sum_recursive(ptr->next) + ptr->data;
}

int max_iterative(Node* ptr) {
    int max = -32567;
    while(ptr) {
        if(ptr->data > max) {
            max = ptr->data;
        }
        ptr=ptr->next;
    }
    return max;
}

//watch out - head recursion
int max_recursive(Node* ptr) {
    //Freaking HEAD recursion
    int x = 0;
    if(ptr==0) return x;
    else {
        x = max_recursive(ptr->next);
        if(ptr->data > x) {
            return ptr->data;
        }
    }
    return x;
}

int main() {
    int A[] = {13,7,5,9,11,16};
    create(A, 5);
    display_iterative(first);
    cout << "Displaying - Recursive." << endl;
    display_recursive(first);
    cout << endl;
    cout << "Displaying - Reverse - Recursive." << endl;
    display_reverse_recursive(first);
    cout << endl;
    
    cout << "Length - Iterative. " << length_iterative(first) << endl;
    cout << "Length - Recursive. " << length_recursive(first) << endl;

    cout << "Sum - Iterative. " << sum_iterative(first) << endl;
    cout << "Sum - Recursive. " << sum_recursive(first) << endl;

    cout << "Max - Iterative. " << max_iterative(first) << endl;
    cout << "Max - Recursive. " << max_recursive(first) << endl;

    return 0;
}