#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int d = (n-1)/k;
    int r = (n-1)%k;
    if(r == 0) cout << d * 2 << endl;
    else if(r == 1) cout << d * 2 + 1 << endl;
    else cout << d * 2 + 2 << endl;

    for(int i=0, v=2; i<k; i++) {
        for(int j=0; j<d+(i<r); j++, v++) {
            if(j==0) cout << 1 << ' ' << v << endl;
            else cout << v-1 << ' ' << v << endl;
        }
    }
}
