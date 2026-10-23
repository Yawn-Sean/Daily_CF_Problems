#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int N = 1e5+10;
const int Q = 1e4+10;
const int C = 1e6;

int n,q;
ll a[N];
ll b[N];
int x[Q];
ll ans = 0;
vector<int> e[N];
vector<int> res;

void init(){
    bitset<1000001> f;
    f[0] = 1;
    for(int i = 1;i <= q;i++){
        f |= (f << x[i]);
    }
    for(int i = 0;i <= C;i++){
        if(f[i]) res.push_back(i);
    }
}

void dfs(int u,int fa){
    ll B = 0;
    b[u] = a[u];
    ll d = 0;
    if(ans == -1) return;
    for(auto v : e[u]){
        if(v == fa) continue;
        dfs(v,u);
        B = max(B,b[v]);
        d = max(d,B-a[u]);
        if(d > 0){
            auto it = lower_bound(res.begin(),res.end(),d);
            if(it == res.end()){
                ans = -1;
                return;
            }
            d = *(it);
        }
    }
    b[u] += d;
    if(ans == -1) return;
    ans += b[u];
}

int main(){
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> a[i];
    int u,v;
    for(int i = 1;i < n;i++){
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for(int i = 1;i <= q;i++) cin >> x[i];
    init();
    dfs(1,0);
    cout << ans << '\n';
    return 0;
}