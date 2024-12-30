
#include<bits/stdc++.h>
//#define int long long 
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
const int N = 1e3 + 10;

int p[N];
vector<int> sz(N, 1);

int find(int x) {
    if (p[x] != x) return p[x] = find(p[x]);
    return p[x];
}

void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v ) return;
    p[u] = v;
    sz[v] += sz[u];
}

void solve(int _) 
{
    int n, d;
    cin >> n >> d;
    for (int i = 1; i < N; i ++ ) p[i] = i;
    int cnt = 1;
    for (int i = 1, u, v; i <= d; i ++ ) {
        cin >> u >> v;
        u = find(u), v = find(v);
        if (u == v) cnt ++;
        else {
            merge(u, v);
        }
        vector<int> tmp;
        for (int j = 1; j <= n; j ++ ) {
            if (find(j) == j) {
                tmp.push_back(sz[j]);
            }
        }
        sort(all(tmp), greater<int>());

        int ans = 0;
        for (int j = 0; j < SZ(tmp) && j < cnt; j ++ ) {
            ans += tmp[j];
        }

        cout << (ans - 1) << endl;
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