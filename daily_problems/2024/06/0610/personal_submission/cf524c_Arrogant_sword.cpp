
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }

    map<int, int> mp;
    mp[0] = 0;
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= k; j ++ ) {
            if (mp.find(a[i] * j) == mp.end()) {
                mp[a[i] * j] = j;
            } else {
                mp[a[i] * j] = min(mp[a[i] * j], j);
            }
        }
    }


    int q;
    cin >> q;
    while(q -- ) {
        int x;
        cin >> x;
        int ans = 1e9;
        for (int i = 1; i <= n; i ++ ) {
            for (int j = 1; j <= k; j ++ ) {
                if (mp.find(x - a[i] * j) == mp.end()) continue;
                ans = min(ans, j + mp[x - a[i] * j]);
            }
        }

        cout << (ans > k ? -1 : ans) << endl;
    }
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