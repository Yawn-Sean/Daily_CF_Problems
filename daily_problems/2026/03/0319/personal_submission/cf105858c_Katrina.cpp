#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define vdbg(a) cerr << #a << " = "; for (auto x : a) cerr << x << " "; cerr << endl;


const int MOD = 998244353;
void solve() {  
    string a, b; cin >> a >> b;
    vector<int> cnt(10);
    for (char c : a) {
        int x = c - '0';
        cnt[x]++;
    }
    for (char c : b) {
        int x = c - '0';
        cnt[x]++;
    }
    int l = max(a.size(), b.size());
    vector<int> w(l);
    for (int i = 0; i < a.size(); ++i) w[i]++;
    for (int i = 0; i < b.size(); ++i) w[i]++;

    ll ans = 0, cur = 9;
    for (int i = l - 1; i >= 0; --i) {
        ans = ans * 10 % MOD;
        while (w[i]--) {
            while (!cnt[cur]) cur--;
            ans = (ans + cur) % MOD;
            cnt[cur]--;
        }
    }
    cout << ans << "\n";
}                                                                     

signed main() {  
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);
   
    int T = 1;
    // cin >> T;  
    while (T--) solve();    
    return 0;
}
