
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
 
void solve() {
    int m;
    cin >> m;
    string s;
    cin >> s;
    queue<int> que[26];
    int n = s.length();
    for (int i = 0; i < n; i++) {
        que[s[i] - 'a'].push(i);
    }
    int it = 0, maxc = 0;
    vector<char> ans;
    vector<int> vis(n);
    while (it < n && it + m - 1 < n) { 
        for (int c = 0; c < 26; c++) {
            int candidiate = -1;
            while (!que[c].empty() && que[c].front() <= it + m - 1) {
                if (que[c].front() >= it) candidiate = que[c].front();
                que[c].pop();    
            }
            if (candidiate != -1) {
                maxc = max(maxc, c);
                ans.push_back('a' + c);
                it = candidiate + 1;
                vis[candidiate] = 1;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i] && s[i] - 'a' < maxc) {
            ans.push_back(s[i]);
        }
    }
    sort(all(ans));
    for (char c : ans) {
        cout << c;
    }
    cout << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}
