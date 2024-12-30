//https://codeforces.com/contest/1609/submission/260215335

#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=2*N,mod=1e9+7;

int n,m,k;
class dsu {
    public:
    vector<int> p,d;
    int n;
 
    dsu(int _n) : n(_n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        d.resize(n);
        fill(d.begin(),d.end(),1);
    }
    inline int get(int x) {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }
    inline int getd(int x){
        x=get(x);
        return d[x];
    }
    inline bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            d[y]+=d[x];
            d[x]=0;
            p[x] = y;
            return true;
        }
        return false;
    }
};
void solve()
{
    cin>>n>>m;
    dsu d(n+10);
    int res=0,now=1;
    //当前有多少个联通块
    multiset<int> st1,st2;
    for(int i=1;i<=n;i++) st2.insert(1);

    for(int i=1;i<=m;i++)
    {
        int x,y;cin>>x>>y;
        if(d.get(x)==d.get(y))
        {
            now++;
        }
        else
        {
            int dx=d.getd(x),dy=d.getd(y);
            if(st1.count(dx))
            {
                st1.extract(dx);res-=dx;
            }else if(st2.count(dx)){
                st2.extract(dx);
            }
            if(st2.count(dy))
            {
                st2.extract(dy);
            }else if(st1.count(dy)){
                st1.extract(dy);
                res-=dy;
            }
            d.unite(x,y);
            st2.insert(d.getd(y));
        }
        while(st1.size()<now&&st2.size())
        {
                auto x=*st2.rbegin();
                res+=x;
                st1.insert(x);
                st2.extract(x);
        }
        while(st1.size()&&st2.size()&&*st1.begin()<*st2.rbegin())
        {
            auto x=*st1.begin();
            auto y=*st2.rbegin();
            res-=x;res+=y;
            st1.extract(x);st2.extract(y);
            st1.insert(y);st2.insert(x);
        }
        cout<<min(res-1,n-1)<<"\n";
    }
}

signed main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int t=1;
   // cin>>t;
    while(t--) solve();
    return 0;
}
