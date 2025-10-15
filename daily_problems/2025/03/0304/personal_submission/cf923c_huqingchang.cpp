#include <bits/stdc++.h>
using namespace std;

const int HIGH_BIT = 30;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> A(n), P(n);
    for (int &a : A) cin >> a;
    for (int &p : P) cin >> p;
    
    int idx = 0;
    vector<vector<int>> g(1, vector<int>(2, -1));
    vector<vector<int>> cnt(1, vector<int>(2, 0));
    
    for (int x : P) {
        int cur = 0;
        for (int j = 0; j < HIGH_BIT; ++j) {
            int bit = 29 - j;
            int val = (x >> bit) & 1;
            if (g[cur][val] == -1) {
                idx++;
                g.push_back({-1, -1});
                cnt.push_back({0, 0});
                cnt[cur][val]++;
                g[cur][val] = idx;
                cur = idx;
            } else {
                cnt[cur][val]++;
                cur = g[cur][val];
            }
        }
    }
    
    vector<int> ans;
    for (int a : A) {
        int cur = 0;
        int tmp = 0;
        for (int j = 0; j < HIGH_BIT; ++j) {
            int bit = 29 - j;
            int val = (a >> bit) & 1;
            int b = val ^ 1;
            if (cnt[cur][val]) {
                cnt[cur][val]--;
                cur = g[cur][val];
            } else {
                cnt[cur][b]--;
                cur = g[cur][b];
                tmp |= (1 << bit);
            }
        }
        ans.push_back(tmp);
    }
    
    for (int x : ans) cout << x << " ";
    cout << "\n";
    
    return 0;
}
