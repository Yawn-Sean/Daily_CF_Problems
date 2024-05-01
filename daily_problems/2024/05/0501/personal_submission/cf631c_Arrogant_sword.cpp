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
const int N = 2e5 + 10;
const int inf = 1e14;

void solve(int _) 
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    vector<PII> stk;
    for (int i = 0; i < m; i ++ ) {
        int t, r;
        cin >> t >> r;
        while (!stk.empty() && r >= stk.back().y) stk.pop_back();
        stk.emplace_back(t, r); 
    }
    vector<int> ans;
    sort(a.begin() + 1, a.begin() + stk[0].y + 1);
    stk.emplace_back(0, 0);
    int r = stk[0].y, l = 1;
    for (int i = 0; i < SZ(stk) - 1; i ++ ) {
        if (stk[i].x == 1) {
            for (int j = stk[i+1].y + 1; j <= stk[i].y; j ++ ) ans.push_back(a[r --]);
        } else {
            for (int j = stk[i+1].y + 1; j <= stk[i].y; j ++ ) ans.push_back(a[l ++]);
        }
    }

    for (int i = stk[0].y - 1; i >= 0; i -- ) cout << ans[i] << ' ';
    for (int i = stk[0].y + 1; i <= n; i ++ ) cout << a[i] << ' ';
    cout << endl;
    
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