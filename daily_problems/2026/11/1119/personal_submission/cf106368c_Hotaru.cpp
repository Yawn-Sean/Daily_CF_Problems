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
    int n,D,t;
    cin >> n >> D >> t;
    vector<pair<int,int>> arr(n + 1);
    rep(i,1,n)cin >> arr[i].first >> arr[i].second;
    priority_queue<pair<int,int>> pq;
    int ans = 0;
    for (int l = 1,r = 2 ; l <= n ; l = r) {
        // cout << "!" << endl;
        while (r <= n && arr[l].first == arr[r].first)r++;
        int nxt = r == n + 1 ? D + 1 : arr[r].first;
        int cur = arr[l].first;
        rep(i,l,r - 1) {
            pq.push({arr[i].second,i});
        }
        for (int i = cur ; i <= nxt - 1 && !pq.empty() ; i++) {
            auto [w,idx] = pq.top();
            ans += w;
            pq.pop();
        }
    }
    set<int> s;
    while (!pq.empty()) {
        auto [w,idx] = pq.top();
        pq.pop();
        s.insert(idx);
    }
    priority_queue<int,vector<int>,greater<>> pqq;
    vector<int> days(n + 1);
    for (int l = 1,r = 2 ; l <= n ; l = r) {
        while (r <= n && arr[l].first == arr[r].first)r++;
        int nxt = r == n + 1 ? D + 1 : arr[r].first;
        int cur = arr[l].first;
        rep(i,l,r - 1) {
            if (s.find(i) == s.end())pqq.push(i);
        }
        for (int i = cur ; i <= nxt - 1 && !pqq.empty() ; i++) {
            int idx = pqq.top();
            days[idx] = i;
            pqq.pop();
        }
    }
    if (days[1] == 0)days[1] = arr[1].first;
    rep(i,2,n) {
        if (!days[i])days[i] = max(arr[i].first,days[i - 1]);
    }
    if (t == 1) {
        cout << ans << endl;
    }
    else {
        cout << ans << endl;
        rep(i,1,n - 1)cout << days[i] << " ";
        cout << days[n] << endl;
    }
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


