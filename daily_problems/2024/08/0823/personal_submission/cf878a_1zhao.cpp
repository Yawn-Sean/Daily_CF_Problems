#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a=0, b=1023;
    for(int i=0; i<n; i++) {
        char op;
        int num;
        cin >> op >> num;
        if(op == '|') {
            a |= num;
            b |= num;
        } else if(op == '&') {
            a &= num;
            b &= num;
        } else if(op == '^') {
            a ^= num;
            b ^= num;
        }
    }
    
    int toOr = 0, toAnd = 1023, toXor = 0;
    for(int i=1; i<(1<<10); i<<=1) {
        int ai = a & i;
        int bi = b & i;
        if(ai == 0 && bi == 0) {
            toAnd -= i;
        } else if(ai > 0 && bi > 0) {
            toOr += i;
        } else if(ai > 0 && bi == 0) {
            toXor += i;
        }
    }

    int k = (toOr != 0) + (toAnd != 1023) + (toXor != 0);
    cout << k << endl;
    if (toOr != 0) cout << "| " << toOr << endl;
    if (toAnd != 1023) cout << "& " << toAnd << endl;
    if (toXor != 0) cout << "^ " << toXor << endl;
}
