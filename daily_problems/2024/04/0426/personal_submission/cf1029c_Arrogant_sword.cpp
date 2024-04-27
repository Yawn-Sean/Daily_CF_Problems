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
void solve(int _) 
{
    int n;
    cin >> n;
    vector<PII> segs(n+1);
    vector<int> lpre(n+2), rpre(n+2, INT_MAX);
    for (int i = 1; i <= n; i ++ ) {
        cin >> segs[i].x >> segs[i].y;
        lpre[i] = max(lpre[i-1], segs[i].x);
        rpre[i] = min(rpre[i-1], segs[i].y);
    }

    int ans = 0;
    int lsuf = 0, rsuf = INT_MAX;
    for (int i = n; i >= 1; i -- ) {
        ans = max(ans, min(rpre[i-1], rsuf) - max(lpre[i-1], lsuf));
        lsuf = max(lsuf, segs[i].x);
        rsuf = min(rsuf, segs[i].y);
    }

    cout << ans << endl;
    
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
