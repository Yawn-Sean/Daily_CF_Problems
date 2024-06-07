
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
    int n, q;
    cin >> n >> q;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    sort(all(a));
    vector<int> s(n+1);
    for (int i = 1; i <= n; i ++ ) {
        s[i] = s[i-1] + a[i];
    }
    map<int, int> mp;
    function<void(int, int)> work = [&](int l, int r) -> void {
        mp[s[r] - s[l-1]] = 1;
        if (l == r) {
            return;
        }
        int mid = (a[l] + a[r]) / 2;
        int pos = upper_bound(a.begin() + l, a.begin() + r + 1, mid) - a.begin();
        // cout << l << ' ' << pos - 1 << ' ' << pos << ' ' << r << endl;
        work(l, pos - 1);
        work(pos, r);   

    };
    work(1, n);
    
    while (q --) {
        int x;
        cin >> x;
        cout << (mp[x] ? "Yes" : "No") << endl;
    }
} 

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    cin >> T;
    for (int _ = 1; _ <= T; _ ++ ) {
        solve(_);
    }
    return 0;
}