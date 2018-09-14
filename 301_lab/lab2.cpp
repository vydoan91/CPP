/*
 * lab2.cpp
 *
 *  Created on: Sep 6, 2018
 *      Author: vydoan
 */

#include <iostream>
using namespace std;

int main() {
    int sumEven = 0;
    int sumOdd = 0;
    int difference = 0;

    // create an array with 5 elements
    int array[] = {0,1,2,3,4};
    // calculate number of elements in array
    int size = sizeof(array) / sizeof(array[0]);

    // visit each element in the array
    // if index i is odd, add to sumOdd
    // if index i is even, add to sumEven
    for(size_t i = 0; i < size; i++) {
        if(i % 2 == 0) {
            sumEven += array[i];
        } else {
            sumOdd += array[i];
        }
    }
    difference = sumOdd - sumEven;
    cout << "Difference = " << difference << endl;
    return 0;
}




