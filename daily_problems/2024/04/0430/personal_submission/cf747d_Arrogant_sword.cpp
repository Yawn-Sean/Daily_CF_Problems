#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define x first
#define y second
#define SZ(a) ((int)a.size())
using namespace std;
void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}
//////////////////////////////////////////////////
const int inf = 1e14;
const int N = 2e5 + 10;
void solve(int _) 
{
    int n, k;
    cin >> n >> k;
    vector<int> cost;
    int cur = 0, flag = 0;
    
    for (int i = 0, x; i < n; i ++) {
        cin >> x;
        if (x >= 0) {
            cur ++;
        } else {
            k --;
            if (flag && cur != 0) cost.push_back(cur);
            flag = 1; cur = 0;
        }
    }
    if (k < 0) {
        cout << -1 << endl;
        return;
    }
    if (!flag) {
        cout << 0 << endl;
        return;
    }
    int ans = (SZ(cost) + 1) * 2;
    //cout << ans << endl;
    
    sort(all(cost));
    function<int(int)> cal = [&](int x) -> int {
        int res = 0;
        for (int &t: cost) {
            if (x >= t) {
                x -= t;
                res += 2;
            } else {
                break;
            }
        }
        return res;
    };  

    cout << min(ans - cal(k), (k >= cur) ? ans - cal(k - cur) - 1 : inf) << endl;
} 

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    //cin >> T;
    for (int _ = 1; _ <= T; _ ++ ) {
        solve(_);
    }
    return 0;
}
