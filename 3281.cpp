//
//  3281.cpp
//  ACM
//
//  Created by Angel Avila on 2/18/16.
//  Copyright © 2016 Angel Avila. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

unsigned long int sumTo(unsigned long int n) {
    return ((n - 1) * n) >> 1;
}

unsigned long int read_input()
{
    unsigned long int _integer=0;
    char _char=0;
    while(_char<48)
        _char=getchar_unlocked();
    while(_char>=48)
    {
        _integer=10*_integer+_char-48;
        _char=getchar_unlocked();
    }
    return _integer;
}

bool isCenter(unsigned long int n, unsigned long int top) {
    
    if (n > 1) {
        unsigned long int firstSum = sumTo(n);
        unsigned long int m = ceil(sqrt(4 * firstSum + 2 * n) + .5);
        
        if (top < m - 1)
            return false;
        
        unsigned long int secondSum = (((m - 1) * m)>>1) - firstSum - n;
        
        if (firstSum == secondSum)
            return true;
    }
    
    return false;
}

int main() {
    
    unsigned long int top;
    top = read_input();

    while(top != 0) {
        short int numberOfCenters = 0;
        
        unsigned int i = 6;
        
        while (i < top) {
            
            if (isCenter(i, top)) {
                numberOfCenters++;
            } else if(isCenter(i + 1, top)) {
                numberOfCenters++;
                i += 1;
            }
            
            i = i * 5.828427125;
        }

        printf("%d\n", numberOfCenters);
        top = read_input();
    }

    return 0;
}