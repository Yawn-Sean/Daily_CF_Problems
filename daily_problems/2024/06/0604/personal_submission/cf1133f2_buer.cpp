#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=2*N,mod=1e8+7;
#define int long long
#define uLL unsigned long long
const long long inf=1e18;
typedef pair<int,int> PII;
typedef long long LL;
using node=tuple<int,int,int>;
int n,m,k;

class dsu {
    public:
    vector<int> p;
    int n;
 
    dsu(int _n) : n(_n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }
 
    inline int get(int x) {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }
 
    inline bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            p[x] = y;
            return true;
        }
        return false;
    }
};
void solve()
{
    cin>>n>>m>>k;
    vector<array<int,2>> a(m);
    dsu d(n+10);int cnt=m;
    for(auto&e:a){
        cin>>e[0]>>e[1];
        if(e[0]==1||e[1]==1) continue;
        d.unite(e[0],e[1]);
        cnt--;
    }
    set<int> st;
    dsu d1(n+10);
    
    for(int i=2;i<=n;i++){
        st.insert(d.get(i));
    }
   
    if(st.size()>k||cnt<k)
    {
        cout<<"NO\n";return ;
    }
    vector<PII> res;
    vector<bool> vis(m+10);
    for(int i=0;i<m;i++)
    {
        auto e=a[i];
        int x=e[0],y=e[1];
        if(x!=1&&y!=1) continue;
        int z=x;if(x==1) z=y;
        if(st.count(d.get(z)))
        {
            vis[i]=true;;
            d1.unite(x,y);
            st.erase(d.get(z));
            k--;
            res.emplace_back(x,y);
            //cout<<x<<" "<<y<<"\n";
        }
    }

    for(int i=0;i<m;i++){
        auto e=a[i];
        int x=e[0],y=e[1];
        if(x!=1&&y!=1||vis[i]) continue;
        if(k>0)
        {
            d1.unite(x,y);k--;
            res.emplace_back(x,y);
        }
    }
    
    for(int i=0;i<m;i++){
        auto e=a[i];
        int x=e[0],y=e[1];
        if(x==1||y==1) continue;
        if(d1.get(x)!=d1.get(y)){
            d1.unite(x,y);
            res.emplace_back(x,y);
        }
   
    }
    if(res.size()!=n-1){
        cout<<"NO\n";return ;
    }
    cout<<"YES\n";
    for(auto [x,y]:res) cout<<x<<" "<<y<<"\n";
}

signed main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int t=1;

   // cin>>t;
    while(t--) solve();
    return 0;
}
