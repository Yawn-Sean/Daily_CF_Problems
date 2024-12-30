#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using pi = pair<int, int>;

const int N = 1e5 + 7;
int q[N];

inline int red() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    int a = red(), b = red();
    int64_t mul = 1ll * a * b;
    int low = 1, high = 1e6;
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (1ll * mid * mid * mid > mul) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << (1ll * high * high * high == mul && a % high == 0 && b % high == 0 ? "Yes\n" : "No\n");
}
  
int main() {  
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = red();
    while (t--) {  
        solve();
    }  
    return 0;  
}

