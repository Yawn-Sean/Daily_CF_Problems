#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 10;
struct node{
    ll x, y, id;
}a[N];
ll sum1[N], sum2[N];
vector<ll> G[N];
ll ans[N];
map<int, int> rk;
bool cmp(node a, node b){
    return (a.x - a.y) < (b.x - b.y);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i].x >> a[i].y;
        a[i].id = i;
    }
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    sort(a + 1, a + 1 + n, cmp);
    for(int i = 1; i <= n; i++){
        rk[a[i].id] = i;
    }
    for(int i = 1; i <= n; i++){
        sum1[i] = sum1[i - 1] + a[i].x;
    }
    for(int j = n; j >= 1; j--){
        sum2[j] = sum2[j + 1] + a[j].y;
    }
    for(int i = 1; i <= n; i++){
        ans[a[i].id] += sum1[i - 1] + (i - 1) * a[i].y;
        ans[a[i].id] += sum2[i + 1] + (n - i) * a[i].x;
        for(int j = 0; j < G[a[i].id].size(); j++){
            int v = rk[G[a[i].id][j]];
            ans[a[i].id] -= min(a[i].x + a[v].y, a[i].y + a[v].x);
        }
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    return 0;
    
}