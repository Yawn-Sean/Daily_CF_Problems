/*
Mayoeba Yabureru
*/
#pragma GCC optimize("O3,unroll-loops")

#include<bits/stdc++.h>
using namespace std;

void solve() {
    long long n, x, y;
    cin >> n >> x >> y;

    vector vals(0, vector(0, 0ll));
    vector a(n + 1, 0);
    map<int, vector<int>> vti;
    for (int i = 1; i <= n; i ++) {
        vals.push_back({(x + i - 1) / i, i, 0});
        vals.push_back({(y + i - 1) / i, i, 1});
        cin >> a[i - 1];
        vti[a[i - 1]].push_back(i);
    }
    sort(a.begin(), a.end());
    sort(vals.rbegin(), vals.rend());

    long long mnx = 1e9, mny = 1e9, bstx = -1, bsty = -1;
    vector ans(0, 0ll);
    for (auto v : vals) {
        int num = a.end() - lower_bound(a.begin(), a.end(), v[0]);
        if (v[2] == 0) {
            if (v[1] <= num - mny) ans = {v[0], v[1], 0, bsty, mny, 1}; 
            if (v[1] <= num) {
                if (mnx > v[1]) {
                    mnx = v[1];
                    bstx = v[0];
                }
            }
        }

        else {
            if (v[1] <= num - mnx) ans = {v[0], v[1], 1, bstx, mnx, 0}; 
            if (v[1] <= num) {
                if (mny > v[1]) {
                    mny = v[1];
                    bsty = v[0];
                }
            }
        }
    }

    if (ans.size() == 0) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    
    vector b(0, 0);
    vector anss(2, vector(0, 0));
    for (auto val : a) {
        if (val >= ans[0] && ans[1]) {
            anss[ans[2]].push_back(val);
            ans[1] --;
        }
        else if (val >= ans[3] && ans[4]){
            anss[ans[5]].push_back(val);
            ans[4] --;
        }
    }
    cout << anss[0].size() << ' ' << anss[1].size() << endl;
    for (auto x : anss[0]) {
        cout << vti[x].back() << ' ';
        vti[x].pop_back();
    }
    cout << endl;
    for (auto x : anss[1]) {
        cout << vti[x].back() << ' ';
        vti[x].pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;

    for (int I = 1; I <= T; I ++){
        solve();
    }
}
