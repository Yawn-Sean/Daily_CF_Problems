#include <bits/stdc++.h>

using namespace std;
#define rep(i, start, end) for(int i = start; i <= end; ++i)

void output(vector<int>& b) {
    string ans = "";
    for(int& v : b) ans += to_string(v) + '.';
    ans.pop_back();
    cout << ans << endl;
}

void solve() {
    int n;
    cin >> n;
    int a[n + 1] = {0};
    rep(i, 1, n) cin >> a[i];

    vector<int> b;
    b.push_back(a[1]);
    cout << a[1] << endl;

    rep(i, 2, n) {
        int n_b = b.size();
        if(a[i] == 1) {
        } else if(a[i] == b[n_b - 1] + 1) {
            b.pop_back();
        } else {
            while(b[n_b - 1] + 1 != a[i]) {
                b.pop_back();
                n_b = b.size();
            }
            b.pop_back();
        }
        b.push_back(a[i]);
        output(b);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t-- > 0) solve();
    return 0;
}
