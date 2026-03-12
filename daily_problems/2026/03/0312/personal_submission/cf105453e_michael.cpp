#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAX = 1001;
const int MAX_EDGES = 1001 + 1001 * 1000/2;
struct Edge{
    int u,v,w;
    bool operator<(const Edge& other) const{
        return w < other.w;
    }
};
vector<Edge> edge(MAX_EDGES);
int cnt;
vector<int> fa(MAX);

void build(int n){
    cnt = 0;
    for(int i = 0; i <= n; ++i){
        fa[i] = i;
    }
}

int find(int x){
    if(x != fa[x]){
        fa[x] = find(fa[x]);
    }
    return fa[x];
}

bool uin(int x,int y){
    int fx = find(x);
    int fy = find(y);
    if(fx == fy){
        return false;
    }else{
        fa[fx] = fy;
        return true;
    }
}

void solve(){
    int n;
    cin >> n;
    build(n);
    for(int i = 1,x; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> x;
            if(i == j){
                edge[cnt].u = 0;
                edge[cnt].v = i;
                edge[cnt++].w = x;
            }else if(i < j){
                edge[cnt].u = i;
                edge[cnt].v = j;
                edge[cnt++].w = x;
            }
        }
    }
    sort(edge.begin(),edge.begin() + cnt);
    ll ans = 0;
    for(int i = 0; i < cnt; ++i){
        if(uin(edge[i].u,edge[i].v)){
            ans += edge[i].w;
        }
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    cout << flush;
    return 0;
}