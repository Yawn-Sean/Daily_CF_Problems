//  A. Clear Symmetry

#include<bits/stdc++.h>

#pragma GCC optimize("O3,Ofast,unroll-loops")

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x;
    cin >> x;

    int n = 1;
    while ((n * n + 1) / 2 < x) n += 2;
    if (x == 3) n = 5;

    cout << n;

    return 0;
}
