//region define
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0),cout.tie(0)
#define eb emplace_back
#define pb push_back
#define PA(arr, start, end) { cout << #arr << ": "; for(int _i = (start); _i <= (end); _i++) cout << (arr)[_i] << " "; cout << endl; }
#define endl '\n'
#define openfile(a) freopen((to_string(a) + ".in").c_str(), "r", stdin);
#define rep(i,a,b) for(int i = a ; i <= b ; i++)
#define per(i,a,b) for(int i = a ; i >= b ; i--)
#define int long long
using namespace std;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int ddx[8] = {-1,-1,1,1,2,2,-2,-2};
int ddy[8] = {-2,2,-2,2,-1,1,-1,1};
int jdx[8] = {0,0,0,0,1,1,-1,-1};
int jdy[8] = {-1,1,-1,1,0,0,0,0};
typedef long double ld;
typedef long long ll;
typedef __int128_t lll;
constexpr int MOD = 1e9 + 7;
const ld eps = 1e-7;
//endregion
void solve() {
    //交代码之前关openfile
    int n;
    cin >> n;
    vector<string> s(n + 1),t(n + 1);
    rep(i,1,n)cin >> s[i];
    rep(i,1,n)cin >> t[i];
    vector<int> c1(26),c2(26);
    rep(i,1,n) {
        for (auto& c : s[i])c1[c - 'a']++;
        for (auto& c : t[i])c2[c - 'a']++;
    }
    rep(i,0,25)if (c1[i] != c2[i]) {
        cout << -1 << endl;
        return;
    }
    auto lcs = [](const string& s,const string& t)->int {
        // string ss = s;
        // string tt = t;
        // ss = " " + ss;
        // tt = " " + tt;
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n + 1,vector<int>(m + 1));
        rep(i,1,n) {
            rep(j,1,m) {
                dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
                if (s[i - 1] == t[j - 1])dp[i][j] = max(dp[i][j],dp[i - 1][j - 1] + 1);
            }
        }
        // rep(i,1,n) {
        //     rep(j,1,m) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return dp[n][m];
    };
    vector<vector<int>> cnt1(n + 1,vector<int>(26));
    vector<vector<int>> cnt2(n + 1,vector<int>(26));
    int ans = 0;
    vector<vector<int>> need(n + 1,vector<int>(26));
    vector<vector<int>> rest(n + 1,vector<int>(26));
    rep(i,1,n) {
        for (auto& c : s[i])cnt1[i][c - 'a']++;
        for (auto& c : t[i])cnt2[i][c - 'a']++;
        rep(j,0,25) {
            if (cnt1[i][j] < cnt2[i][j]) {
                need[i][j] += cnt2[i][j] - cnt1[i][j];
            }
            else {
                rest[i][j] += cnt1[i][j] - cnt2[i][j];
            }
        }
        int lc = lcs(s[i],t[i]);
        int comm = 0;
        rep(j,0,25)comm += min(cnt1[i][j],cnt2[i][j]);
        // cout << lc << endl;
        ans += comm - lc;
    }
    rep(c,0,25) {
        int p = 1,q = 1;
        while (1){
            while (p <= n && !rest[p][c])p++;
            while (q <= n && !need[q][c])q++;
            if (p == n + 1 && q == n + 1)break;
            int cut = min(rest[p][c],need[q][c]);
            ans += cut * (abs(p - q) + 1);
            rest[p][c] -= cut;
            need[q][c] -= cut;
        }
    }
    cout << ans << endl;
}
signed main() {
    // openfile(1)
    IOS;
    int TTTT = 1;
    // cin >> TTTT;
    while (TTTT--) {
        int T = 1;
        // cin >> T;
        while (T--) {
            solve();
        }
    }
    return 0;
}
/*

##     ##   #######   ########    ###     ########  ##   ##
##     ##  ##     ##     ##      ## ##    ##    ##  ##   ##
##     ##  ##     ##     ##     ##   ##   ##    ##  ##   ##
#########  ##     ##     ##    ##     ##  ########  ##   ##
##     ##  ##     ##     ##    #########  ##  ##    ##   ##
##     ##  ##     ##     ##    ##     ##  ##   ##   ##   ##
##     ##   #######      ##    ##     ##  ##    ##   #####

*/


