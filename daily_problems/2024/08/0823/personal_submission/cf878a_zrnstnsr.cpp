#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<int> op(10, 2);
    while (n--) {
        char c; int v;
        cin >> c >> v;
        switch (c) {
            case '^':
                for (int i = 0; i < 10; ++i) if (v & (1 << i)) {
                    if (op[i] > 1) op[i] = 5 - op[i];
                    else op[i] ^= 1;
                }
                break;
            case '&':
                for (int i = 0; i < 10; ++i) if (!(v & (1 << i))) op[i] = 0;
                break;
            case '|':
                for (int i = 0; i < 10; ++i) if (v & (1 << i)) op[i] = 1;
                break;
        }
    }
    int _and = 1023, _or = 0, _xor = 0;
    for (int i = 0; i < 10; ++i) {
        switch (op[i]) {
            case 0: _and ^= 1 << i; break;
            case 1: _or ^= 1 << i; break;
            case 3: _xor ^= 1 << i; break;
        }
    }
    println("3");
    println("& {}\n| {}\n^ {}", _and, _or, _xor);
}


int main() {
    int T;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cin >> T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
