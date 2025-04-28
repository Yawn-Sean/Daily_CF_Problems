/*
由于第k个数的末态在开方后要被(k+1)整除，而在第k个数的"+"过程中只会加k的倍数，所以第k个数既是k的倍数，又是(k+1)的倍数，
方便开方将其构造为k*k*(k+1)*(k+1)，则第(k+1)个数的始态为k*(k+1)，第k个数的始态为k*(k-1),
所以第k个数要按"+"的次数为 (末态-始态)/k
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    for (ll i = 1; i <= n; ++i) {
        if (i == 1) {
            cout << "2\n";
        } else {
            cout << i*i*i + 2*i*i + 1 << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 1;
//    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}