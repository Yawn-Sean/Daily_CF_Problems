
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
    vector<int> cnt(n), cost(n, n+1);
    for (int i = 0; i < m; i ++ ) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        cost[a] = min(cost[a], (b - a + n) % n);
        cnt[a] ++;
    }

    vector<int> a(2 * n);
    for (int i = 0; i < n; i ++ ) {
        if (cnt[i]) {
            a[i] = i + (cnt[i] - 1) * n + cost[i];
        }
    }
    for (int i = n; i < n*2; i ++ ) {
        if (a[i-n]) a[i] = a[i-n] + i;
    }

    vector<int> q;
    for (int i = 0; i < n; i ++ ) {
      while (!q.empty() && a[i] > q.back()) q.pop_back();
      q.push_back(a[i]);  
    }

    for (int i = 0; i < n; i ++ ) {
        cout << q.front() - i << ' ';
        while (!q.empty() && a[i+n] > q.back()) q.pop_back();
        q.push_back(a[i+n]);
    }
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