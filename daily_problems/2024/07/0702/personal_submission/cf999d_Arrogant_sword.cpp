#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define PII pair<int,int>
#define SZ(a) ((int)a.size())
#define rep(i, n) for (int i = 1; i <= n; i ++)
#define rep0(i, n) for (int i = 0; i < n; i ++)

using namespace std;
void print(vector<int>& vi) {
    for (auto t: vi) {
        cout << t << ' ';
    }
    cout << endl;
}

//////////////////////////////////////////////////
const int N = 2e5 + 10;

void solve(int _) 
{
    int n, m;
    cin >> n >> m;
    vector<int> cnt[m], a(n);
    rep0(i, n) {
        cin >> a[i];
        cnt[a[i] % m].push_back(i);
    }

    int ans = 0;
    vector<int> stk;
    rep0(i, 2*m) {
        int x = i % m;
        while (!stk.empty() && cnt[x].size() < n / m) {
            int j = stk.back(); stk.pop_back();
            int v = (x - a[j] % m + m) % m;
            ans += v; a[j] += v;
            cnt[x].push_back(j);
        }
        while (cnt[x].size() > n / m) {
            stk.push_back(cnt[x].back());
            cnt[x].pop_back();
        }
    }

    cout << ans << endl;
    print(a);
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