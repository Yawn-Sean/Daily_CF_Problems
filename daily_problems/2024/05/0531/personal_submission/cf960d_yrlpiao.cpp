#include <iostream>
#include <vector>
using namespace std;
#define int long long

int get(int x) {
    for (int i = 62; i >= 0; i--) {
        if (x >> i & 1) return i;
    }
    return 0;
}

void ys(int x, vector<vector<int>>& cnt, int l) {
    cout << x << " ";
    if (l == 0) return;
    int k = (cnt[1][l] + cnt[2][l]) % (1LL << l);
    x = ((x + k) & ((1LL << l) - 1)) + (1LL << l);
    x >>= 1; l -= 1;
    k = (1LL << l) - cnt[1][l];
    x = ((x + k) & ((1LL << l) - 1)) + (1LL << l);
    ys(x, cnt, l); 
    return;
}

void yrlpSolve() {
    int q; cin >> q;
    int t, x, k;
    vector<vector<int>> cnt(3, vector<int>(100));
    for (int i = 0; i < q; i++) {
        cin >> t >> x;
        int l = get(x);
        if (t == 1 || t == 2) {
            cin >> k;
            int n = 1LL << l;
            k %= n; k += n; k %= n;
            cnt[t][l] += k; cnt[t][l] %= n;
        } else {
            ys(x, cnt, l);
            cout << endl;
        }
    }
    return; 
}

signed main() {
    int T = 1; //cin >> T;
    while (T--) yrlpSolve();
}
