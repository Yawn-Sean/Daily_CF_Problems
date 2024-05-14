#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=2*N,mod=1e9+7;
#define int long long
#define uLL unsigned long long
const long long inf=1e18;
typedef pair<int,int> PII;
typedef long long LL;
using node=tuple<int,int,int>;
int n,m,k;
vector<PII> g0,g1;
void solve()
{
    int c,d;
    cin>>n>>c>>d;
    int mx0=-inf,mx1=-inf;
    for(int i=1;i<=n;i++)
    {
        int b,y;cin>>b>>y;
        char x;cin>>x;
        if(x=='C') {
            if(y>c) continue;
            mx0=max(mx0,b);
            g0.emplace_back(b,y);
        }
        else {
            if(y>d) continue;
            mx1=max(mx1,b);
            g1.emplace_back(b,y);
        }
    }
    int res=mx1+mx0;

    sort(g0.begin(),g0.end(),[&](const auto&p,const auto&q){
        return p.second<q.second;
    });
    sort(g1.begin(),g1.end(),[&](const auto&p,const auto&q){
        return p.second<q.second;
    });
    auto get=[&](vector<PII>&g,int money)
    {
        int ans=-inf;
        multiset<node> st;
        for(int i=0;i<g.size();i++)
        {
            auto [x,y]=g[i];
            st.insert({x,y,i});
        }
        for(int i=0;i<g.size();i++)
        {
            auto [x,y]=g[i];
            st.extract({x,y,i});
            while(st.size())
            {
                auto [xx,yy,zz]=*st.rbegin();
                if(y+yy>money){
                    st.erase(*st.rbegin());
                }else break;
            }
            if(st.size()){
                auto [xx,yy,zz]=*st.rbegin();
                ans=max(ans,x+xx);
            }
        }
        return ans;
    };
    
    cout<<max({0ll,res,get(g0,c),get(g1,d)});
}

signed main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}
