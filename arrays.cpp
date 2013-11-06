#include <iostream>

using namespace std;

int main()
{
    int iter = 6;
    float avg;
    int input [iter];
    
    for (int i = 0; i < iter; ++i) {
        cout << "Input a number: ";
        input[i] = rand() % 50;
        cout << input[i] << endl;
    }
    
    avg = input[0];
    for (int i = 1; i < iter; ++i) {
        avg += input[i];
    }
    avg = avg / iter;
    cout << avg << endl;
}