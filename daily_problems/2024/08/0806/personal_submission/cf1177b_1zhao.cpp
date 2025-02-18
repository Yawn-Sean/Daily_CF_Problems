#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long k;
    cin >> k;
    long long mi = 1;
    int bit = 1;
    while(k > mi * 9 * bit) {
        k -= mi * 9 * bit;
        bit ++;
        mi *= 10;
    }
    long long num = mi + ((k-1)/bit);
    cout << to_string(num)[(k-1)%bit] << endl;
}
