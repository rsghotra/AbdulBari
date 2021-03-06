#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

//make it global so that every function can have access to it.
Node* first=NULL;
Node* last=NULL;
Node* second=NULL;

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

Node* search_iterative_move_head(Node* ptr, int key) {
    if(ptr==0) return NULL;
    //when element is present at head then while loops' logic breaks down.
    if(ptr->data == key) return ptr;
    Node* tail = ptr;
    while(ptr) {
        if(ptr->data == key) {
            cout << "Element found. ";
            tail->next = ptr->next;
            ptr->next=first;
            first = ptr;
            return ptr;
        }
        tail = ptr;
        ptr = ptr->next;
    }
    return nullptr;
}

Node* search_recursive(Node* ptr, int key) {
    //if you are searching then the terminative condition will have successul case as well
    if(ptr==0)  {
        cout << "Element not found. ";
        return nullptr;
    }
    if(ptr->data == key) {
        cout << "Element found. ";
        return ptr;
    }
    search_recursive(ptr->next, key);
}

Node* search_iterative(Node* ptr, int key) {
    while(ptr) {
        if(ptr->data == key) {
            cout << "Element found. ";
            return ptr;
        }
        ptr = ptr->next;
    }
    cout << "Element not found. ";
    return nullptr;
}

void insert_after(Node* ptr, int pos, int k) {
    //we need to handle insert at 0 sepratrely
    if(pos >= 0) {
        Node* tmp;
        tmp->data = k;
        if(pos==0) {
            cout << "Inserting at HEAD." << endl;
            tmp->next = first;
            first = tmp;
        } else {
            //ptr is pointing to temp
            for(int i=0;i<pos-1 && ptr != 0;i++) {
                ptr = ptr->next;
            }
            //means a valid index
            if(ptr) {
                tmp->next = ptr->next;
                ptr->next = tmp;
            } else {
                cout << "In-valid index supplied." << endl;
            }
        }
    } else{
        cout << "Negative index supplied."<<endl;
    }
}

void insert_last(int val) {
    //create node
    Node* temp = new Node();
    temp->data = val;
    temp->next = 0;

    //NODE IS CREATED MUST FIRST HANDLE WHEN THERE IS NO NODE AND ITITIATE THE POINTER THERE AFTER
    if(first == 0) {
        first = last = temp;
    } else {
        last->next = temp;
        last = temp;
    }
}

void insert_last(int val, bool sList) {
    //create node
    Node* temp = new Node();
    temp->data = val;
    temp->next = 0;

    //NODE IS CREATED MUST FIRST HANDLE WHEN THERE IS NO NODE AND ITITIATE THE POINTER THERE AFTER
    if(second == 0) {
        second = last = temp;
    } else {
        last->next = temp;
        last = temp;
    }
}

void insert_sorted(Node* ptr, int x) {
    /*
        - Inserting in a sorted list has three cases:
            1. Inserting when list is NULL
            2. Inserting before head
            3. Inserting at any other location
    */
   //As this function will definitely ADD a NODE. WE can create it now
   Node* node = new Node;
   node->data = x;
   node->next = 0;
   Node* tail = 0;

   //First special case:
   if(first==0) {
       first = node;
   } else {
       while(ptr != 0 && ptr->data < x) {
           tail = ptr;
           ptr = ptr->next;
       }
       //Second special case - when the element to be inserted is the smalles element
       if(ptr == first) {
           node->next = first;
           first = node;
       } else {
           node->next = tail->next;
           tail->next = node;
       }
   }
}

int delete_index(int pos) {
    /*
        Delete an element by its position. It has three cases:
            1. Delete when list is NULL
            2. Delete HEAD, i.e. pos=1
            3. Delete from anywhere else
    */
   //NULL CASES
}

bool isSorted(Node* ptr) {
    int x = -65000;
    while(ptr) {
        if(ptr->data < x) {
            //unsorted list detected
            return false;
        } else {
            x = ptr->data;
            ptr = ptr->next;
        }
    }
    return true;
}

void remove_duplicates(Node* ptr) {
    Node* currentPtr = ptr;
    Node* nextPtr = ptr->next;
    //no worry about first being changes in this algo
    if(currentPtr == 0 || nextPtr == 0) return;

    while(nextPtr) {
        if(currentPtr->data == nextPtr->data) {
            // it is a duplicate
            currentPtr->next = nextPtr->next;
            nextPtr=0;
            nextPtr=currentPtr->next;
        } else {
            currentPtr=currentPtr->next;
            nextPtr=nextPtr->next;
        }
    }
}

void reverse_ll_array(Node* ptr) {
    /*
        - in-efficient and cumbersome
        - create an array of linked list length
        - traverse the linked list and fill the array with linked list
        - then reverse traverse the array and fill the linked list
    */
   int* A = new int[length_recursive(ptr)];
   int i=0;
   while(ptr) {
       A[i]=ptr->data;
       ptr=ptr->next;
       i++;
   }
   //taking ptr back to first
   ptr=first;
   i--;
   while(ptr) {
       ptr->data = A[i];
       ptr = ptr->next;
       i--;
   }
}

void reverse_ll_sliding(Node* ptr) {
    /*
        - Sliding pointer algorithm:
        - Two requirements-Reverese Links + Change First
        - Three pointers are used at a time.
        - P is in lead.
        - Q is the position where reversal will happen
        - Loop will end when Lead pointer reaches null
        - When loop ends: Change First to Q
    */
    Node* p = ptr; //leader;
    Node* q = 0;
    Node* r = 0;

    while(p) {
        //Slide
        r = q;
        q = p;
        p = p->next;
        //reverse
        q->next = r;
    }
    first = q;
}

void _reverse_ll_recursive(Node* ptr, Node* tail) {
    if(ptr== 0) {
        first = tail;
        return;
    } else {
        _reverse_ll_recursive(ptr->next, ptr);
        ptr->next = tail;
    }

}

void reverse_ll_recursive(Node* ptr) {
    Node* tail = 0;
    _reverse_ll_recursive(ptr, tail);
}

void concat_lists(Node* ptr1, Node* ptr2) {
    while(ptr1->next != 0) {
        ptr1=ptr1->next;
    }
    ptr1->next = ptr2;
}

int main() {
    int A[] = {13,7,5,9,11,16};
    create(A,6);
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

    cout << "Search - Iterative. " << search_iterative(first, 13) << endl;
    cout << "Search - Recursive. " << search_recursive(first, 7) << endl;
    cout << "Search - Iterative - Move First. " << search_iterative_move_head(first, 16) << endl;
    display_recursive(first);
    cout << endl;
    cout << "Insert After - Iterative. " << endl;
    insert_after(first, 2, 17);
    display_recursive(first);

    cout << "\nCreating a Linked List by inserting at last every time" << endl;
    first = 0;
    insert_last(30);
    insert_last(7);
    insert_last(13);
    insert_last(19);
    insert_last(11);
    display_recursive(first);
    last=0;
    cout << "\nInserting in a sorted linked list now." << endl;
    first = 0;
    insert_sorted(first, 20);
    insert_sorted(first, 19);
    insert_sorted(first, 26);
    insert_sorted(first, 99);
    insert_sorted(first, 1);
    insert_sorted(first, 99);
    insert_sorted(first, 19);
    insert_sorted(first, 99);
    insert_sorted(first, 99);
    insert_sorted(first, 1);
    insert_sorted(first, 26);
    insert_sorted(first, 11);

    display_recursive(first);
    cout << "\nDelete from a Linked List from a position." << endl;
    delete_index(1);
    display_recursive(first);
    cout << endl;
    delete_index(6);
    display_recursive(first);
    delete_index(4);
    cout << endl;
    display_recursive(first);

    cout << "\nCheck if linked list is sorted" << endl;
    if(isSorted(first)) cout << ">==>Sorted Linked List." << endl;
    else cout << ">==>Unsorted List." << endl;

    cout << "Removing duplicates from a sorted Linked List" << endl;
    remove_duplicates(first);
    display_iterative(first);

    cout << "\nReversing Linked List Now." << endl;

    cout << "Reverse - Array" << endl;
    reverse_ll_array(first);
    display_iterative(first);

    cout << "Reverse - Sliding Pointers" << endl;
    reverse_ll_sliding(first);
    display_iterative(first);

    cout << "Reverse - Recursive" << endl;
    reverse_ll_recursive(first);
    display_iterative(first);

    cout << "Concatenate Two LLs" << endl;
    insert_last(29, true);
    insert_last(17, true);
    insert_last(27, true);
    insert_last(18, true);
    insert_last(21,true);
    display_recursive(second);
    concat_lists(first, second);
    cout << endl;
    display_iterative(first);
    return 0;
}