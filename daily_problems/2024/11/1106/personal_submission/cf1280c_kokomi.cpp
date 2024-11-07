#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, k, head[N], si[N];
typedef long long ll;
struct edge{
    int v, w, last;
}e[N << 1];
ll ans;

void add(int u, int v, int w){
    e[++k].last = head[u];
    e[k].v = v;
    e[k]. w = w;
    head[u] = k;
}

void dfs_min(int u, int fa){
    si[u] = 1;
    for(int i = head[u]; i; i = e[i].last){
        int v = e[i].v;
        if(v == fa) continue;
        dfs_min(v, u);
        si[u] += si[v];
        if(si[v] & 1) ans += e[i].w;
    }
}

void dfs_max(int u, int fa){
    si[u] = 1;
    for(int i = head[u]; i; i = e[i].last){
        int v = e[i].v;
        if(v == fa) continue;
        dfs_max(v, u);
        si[u] += si[v];
        ans += (ll)min(si[v], n -si[v]) * e[i].w;
    }
}
//贪心。
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        n *= 2;
        k = 0;
        for(int i = 1; i <= n; i++) head[i] = 0;
        for(int u, v, w, i = 1; i < n ; i++){
            cin >> u >> v >> w;
            add(u, v, w);
            add(v, u, w);
        }
        ans = 0;
        dfs_min(1, 0);
        cout << ans << " ";
        ans = 0;
        dfs_max(1, 0);
        cout << ans << endl;

    }
}