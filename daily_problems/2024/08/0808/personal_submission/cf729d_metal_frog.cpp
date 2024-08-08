#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
 
void solve() {
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    string s;
    cin >> s;
    vector<int> ans;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') cnt = 0;
        else {
            cnt++;
            if (cnt == b) {
                ans.push_back(i + 1);
                cnt = 0;
            }
        }
    }
    for (int i = 0; i < a - 1; i++) ans.pop_back();
    cout << ans.size() << endl;
    for (int pos : ans) {
        cout << pos << " ";
    }
    cout << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}
