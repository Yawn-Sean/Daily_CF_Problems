#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
 
void solve() {
    int n;
    cin >> n;
    vector<int> Y(n);
    for (int i = 0; i < n; i++) {
        cin >> Y[i];
    }
    int lo = 1, hi = *max_element(all(Y)) + 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        set<int> X;
        bool okay = true;
        for (int i = 0; i < n; i++) {
            int tmp = Y[i];
            while (tmp > mid) tmp /= 2;
            while (X.find(tmp) != X.end()) {
                tmp /= 2;
                if (tmp == 0) {
                    okay = false;
                    break;
                }
            }
            X.insert(tmp);
        }
        if (!okay) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    set<int> X;
    for (int i = 0; i < n; i++) {
        while (Y[i] > lo) Y[i] /= 2;
        while (X.find(Y[i]) != X.end()) {
            Y[i] /= 2;
        }
        X.insert(Y[i]);
        cout << Y[i] << " ";
    }
    cout << "\n";
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}
