#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n & 1) {
        for(int i=1; i<=n; i+=2) cout << i << ' ';
        for(int i=n-2; i>=1; i-=2) cout << i << ' ';
        for(int i=2; i<=n; i+=2) cout << i << ' ';
        for(int i=n-1; i>=2; i-=2) cout << i << ' ';
        cout << n << endl;
    } else {
        for(int i=1; i<=n; i+=2) cout << i << ' ';
        for(int i=n-1; i>=1; i-=2) cout << i << ' ';
        for(int i=2; i<=n; i+=2) cout << i << ' ';
        for(int i=n-2; i>=2; i-=2) cout << i << ' ';
        cout << n << endl;
    }
}
