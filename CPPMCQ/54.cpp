#include <iostream>
using namespace std;

/*
    Concept: Creating Base Object in Base Constructor
        - BAD - RECURSIVE CALL
        - DEFAULT CONSTRUCTOR _ CALLING DEFAULT CONSUTRTOR
        - SOLUTION  - PUT A TERMINATING CONDITOIN

*/

int glb = 10;

class Base {
    int _x, _y;
    public:

        Base() {
            //solution
            if(glb-- < 0) {
                return;
            }
            Base b;
            b._x = 0;
            b._y = 0;
            *this = b;
            b.print();  
        }
        void print() {
            cout << _x << " " << _y << endl;
        }
};


int main() {
    Base b;
    b.print();
    return 0;
}

