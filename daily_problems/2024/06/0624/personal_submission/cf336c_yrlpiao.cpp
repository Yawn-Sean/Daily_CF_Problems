#include <iostream>
#include <set>
using namespace std;
const int N = 1 << 17;

int w[N] {}, n;

int yrlpSolve() {
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
    int ans = -1;
    for (int i = 0; i < 31; i++) {
        int c = (1 << 31) - 1;
        for (int j = 1; j <= n; j++) {
            if (w[j] >> i & 1) c &= w[j];
        }
        if (c % (1 << i) == 0) ans = i;
    }
    if (ans == -1) return cout << -1, 0;
    set<int> s;
    for (int i = 1; i <= n; i++) {
        if (w[i] >> ans & 1) s.insert(w[i]);
    }
    cout << s.size() << endl;
    for (auto x : s) cout << x << " ";
    return 0; 
}

signed main() {
    int T = 1; //cin >> T;
    while (T--) yrlpSolve();
}
