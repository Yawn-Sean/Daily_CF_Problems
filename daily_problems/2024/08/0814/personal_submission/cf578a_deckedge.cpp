#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using pi = pair<int, int>;

inline int read() {
    int x;
    cin >> x;
    return x;
}

int main() {  
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a = read(), b = read();
    if (a < b) {
        cout << -1 << '\n';
    } else if (a == b) {
        cout << a << '\n';
    } else {
        double k1 = floor((a - b) / 2 / b), k2 = floor((a + b) / 2 / b);
        cout << fixed << setprecision(9) << min((a - b) / k1 / 2, (a + b) / k2 / 2) << '\n';
    }
    return 0;  
}
