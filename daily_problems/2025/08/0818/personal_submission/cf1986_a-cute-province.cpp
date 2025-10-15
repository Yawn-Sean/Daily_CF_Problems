#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
#define int long long
typedef pair<int, int> PII;
typedef long long LL;
const int N = 2e5+10;
const int mod = 998244353;
int dfn[N], low[N], tot;
//g存边
int fa[N];
int sz[N];
int n, m;
vector<vector<int>> g(N);
int ans = 0;
void tarjan(int x){
    dfn[x] = low[x] = ++tot;
    
    sz[x] = 1;
    for(auto y : g[x]){
        if(!dfn[y]){
        	fa[y] = x;
            tarjan(y);
            
            low[x] = min(low[x], low[y]);
            sz[x] += sz[y]; 
            if(low[y] > dfn[x]){
            ans = max(ans, sz[y] * (n - sz[y]));
            	
			}
        }
        else if(fa[x] != y){
            low[x] = min(low[x], low[y]);
        }
    }
    
    
}

int u[N], v[N];
void solve(){
    ans =  0;
    cin >> n >> m;

	for(int i =1;  i<= n; i ++){
        dfn[i] = 0, low[i] = 0, tot = 0;
        fa[i]=  0, sz[i] = 0;
        g[i].clear();
    }   
    for(int i =1; i <= m;i ++){       
        cin >> u[i] >> v[i];
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
    }
   
     
    tarjan(1);
    cout << n*(n-1)/2 - ans <<'\n';
    

}  
signed main() {
    int t;
    cin >> t;
    //t = 1;
    while(t--){
        solve();
    }

    return 0;
}
