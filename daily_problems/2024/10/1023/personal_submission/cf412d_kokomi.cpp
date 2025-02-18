#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct edge{
    int nx, v;
}e[N];
int n, m, rd[N], totm, hd[N], ans[N], tot, vis[N];

void add(int u, int v){
    e[++totm].nx = hd[u];
    hd[u] = totm;
    e[totm].v = v;
}

void dfs(int now){
    vis[now] = 1;
    for(int i = hd[now]; i; i = e[i].nx) if(!vis[e[i].v]) dfs(e[i].v);
    ans[++tot] = now;
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
		add(x, y);
    }
    for(int i = 1; i <= n; i++) if(!vis[i]) dfs(i);
    for(int i = 1; i <= tot; i++) cout << ans[i] << " ";
}