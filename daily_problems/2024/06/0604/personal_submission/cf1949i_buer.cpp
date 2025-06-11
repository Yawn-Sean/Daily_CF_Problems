#include<bits/stdc++.h>
using namespace std;
const int N=5010+10,M=2*N,mod=1e8+7;
#define int long long
#define uLL unsigned long long
const long long inf=1e18;
typedef pair<int,int> PII;
typedef long long LL;
using node=tuple<int,int,int>;
int n,m,k;
vector<int> g[N];
int dist(int x1,int y1,int x2,int y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
void solve()
{
    cin>>n;
    vector<array<int,3>> a(n);
    for(auto&e:a){
        cin>>e[0]>>e[1]>>e[2];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            //if(i==j) continue;
           // cout<<dist(a[i][0],a[i][1],a[j][0],a[j][1])<<"\n";
            if(dist(a[i][0],a[i][1],a[j][0],a[j][1])==(a[i][2]+a[j][2])*(a[i][2]+a[j][2])){
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
        // cout<<i<<"\n";
        // for(auto x:g[i]) cout<<x<<" ";
        // cout<<"\n";
    }
    vector<int> st(n+10),color(n+10);
    vector<int> c(5);
    function<bool(int,int)>dfs=[&](int u,int col)->bool{
        color[u] = col;
        c[col]++;
        bool f=true;
        for (auto j:g[u])
        {
            if (!color[j])
            {
                if (!dfs(j, 3 - col)) f=false;
            }
            else if (color[j] == col) f=false;
        }
    
        return f;
    };
    for(int i=0;i<n;i++){
        if(!color[i])
        {
            c[1]=c[2]=0;
            if(dfs(i,1)==false) continue;
            if(c[2]!=c[1])
            {
                cout<<"YES\n";return ;
            }
        }
    }
    
    cout<<"NO\n";
}

signed main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int t=1;

   // cin>>t;
    while(t--) solve();
    return 0;
}
