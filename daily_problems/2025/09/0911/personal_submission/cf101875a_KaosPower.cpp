#include<bits/stdc++.h>

#pragma GCC optimize("O3,Ofast,unroll-loops")

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    int g = gcd(n, k);

    cout << 1ll * k * (n - g) + 1ll * (k - 1) * (g - 1);

    return 0;
}
