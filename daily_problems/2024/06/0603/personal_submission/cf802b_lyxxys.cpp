#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Pii = pair<int,int>;
const int N = 400550, mod = 998244353, inf = 1e9;
int nxt[N];
struct cmp {
    bool operator()(array<int,2> &a, array<int,2> &b){
        return a[0] < b[0];
    }
};
bool vis[N];
void solve(){
    int n, k;
    cin >> n >> k;
    vector <int> a(n+1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    vector <int> Pos(n+1);
    for (int i = 1; i <= n; ++ i) Pos[i] = n+1;
    for (int i = n; i >= 1; -- i){
        nxt[i] = Pos[a[i]];
        Pos[a[i]] = i;
    }
    int res = 0;

    priority_queue <array<int,2>, vector<array<int,2>>, cmp> pq;
    for (int i = 1, cnt = 0; i <= n; ++ i){
        int x = a[i];
        array<int,2> t;
        if (pq.size()){
            t = pq.top();
            while (!vis[t[1]]) pq.pop(), t = pq.top();
        }
        
        if (!vis[x]){
            ++ res;
            if (cnt == k) vis[t[1]] = 0, pq.pop(), -- cnt;
            vis[x] = 1;
            pq.push({nxt[i], x});
            ++ cnt;
        }
        pq.push({nxt[i], x});
    }
    cout << res << "\n";
}

int main(){
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#else
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    int _ = 1;
    while (_--) solve();
    return 0;
}
