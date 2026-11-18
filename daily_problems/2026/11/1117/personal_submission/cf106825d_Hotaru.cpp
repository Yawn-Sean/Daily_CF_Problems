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
    vector<int> arr(n + 1);
    rep(i,1,n)cin >> arr[i];
    int l = 0,r = 1e18;
    int re = 1e18;
    while (l <= r) {
        int mid = (l + r) >> 1;
        auto check = [&](int v)->int {
            vector<int> tmp = arr;
            int rest = 0;
            rep(i,1,n) {
                if (tmp[i] <= v) {
                    int cur = v - tmp[i];
                    if (i < n) {
                        int cost = min(cur,tmp[i + 1]);
                        tmp[i + 1] -= cost;
                        cur -= cost;
                        if ((cur & 1) && cost > 0) {
                            tmp[i + 1] ++;
                            cur ++;
                        }
                    }
                    rest += cur / 2;
                }
                else {
                    tmp[i] -= v;
                    rest -= tmp[i];
                    if (rest < 0)return 0;
                }
            }
            return 1;
        };
        if (check(mid)) {
            re = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << re << endl;
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


