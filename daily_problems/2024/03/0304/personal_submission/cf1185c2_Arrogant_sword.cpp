// 注意数据范围秒了
#include<bits/stdc++.h>

#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}

//////////////////////////////////////////////////

void solve() 
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n+1), s(n+1);
    for (int i = 1; i <= n; i ++ ) {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }

    vector<int> cnt(110);
    for (int i = 1; i <= n; i ++) {
        int x = s[i];
        int ans = 0;
        for (int j = 100; j >= 1; j -- ) {
            if (x > m && cnt[j]) {
                int mn = min(cnt[j], (x - m + j - 1) / j);
                ans += mn;
                x -= mn * j;
            }
        }
        cnt[a[i]] ++;
        cout << ans << ' ';
    }
} 

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    //cin >> T;
    while (T --) {
        solve();
    }
    
}