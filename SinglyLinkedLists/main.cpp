#include <iostream>
#include "LList.h"
using namespace std;

int main() {
    LList ll;
    ll.deletes(30.0);
    ll.append(25.0);
    ll.insert(10.0);
    ll.append(15.0);
    ll.append(45.0);
    ll.insert(5.0);
    ll.append(95.0);
    ll.deletes(10.0);
    ll.sort();
    ll.display();
    ll.reverse();
    ll.display();
    return 0;
}