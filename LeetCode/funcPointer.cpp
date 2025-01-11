#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

void PrintValue(int value)
{
    cout<<"value is "<<value<<endl;
}

void ForEach(const vector <int> &values, void (*func)(int))
{
    for (int value: values)
        func(value);
}


int main()
{
    vector<int> values = {1,2,3,4,5};
    ForEach(values,PrintValue);
    return 0;
}