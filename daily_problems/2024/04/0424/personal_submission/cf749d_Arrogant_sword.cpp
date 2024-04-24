
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define x first
#define y second
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
    vector<vector<int>> bid(n+1);
    vector<int> mx(n+1);
    set<int> s;
    for (int i = 0, a, b; i < n; i ++ ) {
        cin >> a >> b;
        s.insert(a);
        bid[a].push_back(b);
        mx[a] = max(mx[a], b);
    }
    mx[0] = 1e9+10;
    vector<int> idx(n+1);
    iota(all(idx), 0);
    sort(all(idx), [&](int x, int y) {
        return mx[x] > mx[y];
    });
    int m, tol = s.size();
    cin >> m;
    while (m -- ) {
        int k;
        cin >> k;
        map<int,int> mp;
        for (int i = 0, x; i < k; i ++ ) {
            cin >> x;
            mp[x] = 1;
        }
        int fir = 0, sec = 0;
        for (int i = 1; i <= tol; i ++ ) {
            if (!mp[idx[i]]) {
                if (!fir) fir = idx[i];
                else if (!sec) sec = idx[i];
                else break;
            }
        }
        if (!fir && !sec) {
            cout << 0 << ' ' << 0 << endl;
            continue;
        }
        if (!sec) {
            cout << fir << ' ' << bid[fir][0] << endl;
            continue;
        }
        int tmx = bid[sec].back();

        int ans = upper_bound(all(bid[fir]), tmx) - bid[fir].begin();
        cout << fir << ' ' << bid[fir][ans] << endl;
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
