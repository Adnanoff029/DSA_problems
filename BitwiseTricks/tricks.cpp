#include <bits/stdc++.h>
using namespace std;
// Check wheter a number is even or odd
string checkEvenOdd(int n)
{
    if ((n & 1) == 1)
        return "odd";
    else
        return "even";
}

// Check if a number is a power of 2 (does not work if the number is 0)
bool checkPowerOfTwo(int n)
{
    if (n == 0)
        return false;
    if ((n & (n - 1)) == 0)
        return true;
    else
        return false;
}

// Playing with kth bits
//(i) Check if kth bit is set (from the right 0 to k)
bool checkSetKthBit(int n, int k)
{
    int l = 1;
    l <<= k;
    return (n & l);
}
//(ii) Toggle the kth bit from right (0 to k)
int toggleKthBit(int n, int k)
{
    int l = (n ^ (1 << k));
    return l;
}
//(iii) Set the kth bit as 1
int setKthBit(int n, int k)
{
    return (n | (1 << k));
}
//(iv) Set the kth bit to 0
int unsetKthBit(int n, int k)
{
    return (n & (~(1 << k)));
}

// Find n % (2^k)
int modByPowerOf2(int n, int k)
{
    return (n & ((1 << k) - 1));
}

// Swapping numbers with temperory variables
void swapNos(int n, int m)
{
    cout << "Before swap: " << n << " " << m << endl;
    n = (n ^ m);
    m = (m ^ n);
    n = (n ^ m);
    cout << "After swap: " << n << " " << m << endl;
}

// Easy way for
// if (X == A)      |
//     X = A;       | ----->(X = (X ^ A ^ B))
// else if (X == B) |
//     X = B;       |

int main()
{
    int n;
    cin >> n;
    cout << "Numebr " << n << " is: " << checkEvenOdd(n) << endl;
    cout << "Numebr " << n << " is a power of 2: " << checkPowerOfTwo(n) << endl;
    cout << "Numebr " << n << "'s 3rd bit is: " << checkSetKthBit(n, 3) << endl;
    cout << "Numebr " << n << "'s 3rd bit is toggled: " << toggleKthBit(n, 3) << endl;
    cout << "Numebr " << n << "'s 1st bit is set to 1: " << setKthBit(n, 1) << endl;
    cout << "Numebr " << n << "'s 3rd bit is set to 0: " << unsetKthBit(n, 3) << endl;
    cout << "Numebr " << n << "mod by 2^4: " << unsetKthBit(n, 4) << endl;
    cout << "Swapping 2 numbers: " << endl;
    swapNos(9, 19);
    return 0;
}