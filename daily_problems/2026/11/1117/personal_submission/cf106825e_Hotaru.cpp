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
    int s;
    cin >> s;
    int n = 1 << s;
    vector<int> g(n + 1);
    vector<int> m(n + 1);
    rep(i,1,n)cin >> g[i];
    rep(i,1,n)cin >> m[i];
    vector<int> differs;
    vector<int> tmp = g;
    sort(tmp.begin() + 1,tmp.end());
    differs.push_back(0);
    rep(i,1,n) {
        rep(j,i + 1,n) {
            differs.push_back(tmp[j] - tmp[i] + 1);
        }
    }
    sort(differs.begin(),differs.end());
    differs.erase(unique(differs.begin(),differs.end()),differs.end());
    int w = 0;
    int minv_d = 1e18;
    for (auto& d : differs) {
        int re = 0;
        int len = n;
        vector<int> arr(n + 1);
        rep(i,1,n)arr[i] = i;
        while (len > 1) {
            vector<int> nxt(1);
            for (int l = 1 ; l <= len ; l += 2) {
                int g1 = g[arr[l]],m1 = m[arr[l]];
                int g2 = g[arr[l + 1]],m2 = m[arr[l + 1]];
                re += m1 + m2;
                if (g1 < g2) {
                    g1 += d;
                    if (g1 > g2)nxt.push_back(arr[l]);
                    else nxt.push_back(arr[l + 1]);
                }
                else {
                    g2 += d;
                    if (g2 > g1)nxt.push_back(arr[l + 1]);
                    else nxt.push_back(arr[l]);
                }
            }
            len /= 2;
            arr = nxt;
        }
        if (re > w) {
            w = re;
            minv_d = d;
        }
        else if (re == w && d < minv_d) {
            minv_d = d;
        }
    }
    cout << w << endl << minv_d << endl;
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


