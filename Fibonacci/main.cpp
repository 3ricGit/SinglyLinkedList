/* Author: Eric Gitangu
   Date: 07/29/2015
   This program spits out the fibionacci sequence for the range of 32-bit numbers
   Assumption: all values are +ve ; unsigned int works here
*/
#include <iostream>
#include <math.h>
#define N pow(2.0,31.0)

using namespace std;

void fibionacci(unsigned int &fib, unsigned int &prevfib){
    int temp = prevfib;
    prevfib = fib;
    fib += temp;
}
int main(){
    int count = 0;
    unsigned int fib = 0u, prev = 1u;

    while(fib < N){
        if( fib ==0 ){
            fib = 0;
            cout<<" "<< fib++ <<" , ";
            continue;
        }
        if( fib == 1 && count++ < 2 ){
            fib = 1;
            cout<< fib <<" , ";
            continue;
        }
        fibionacci(fib, prev);
        cout<< fib <<" , ";
    }
    return 0;
}