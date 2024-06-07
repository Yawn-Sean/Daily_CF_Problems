#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=2*N,mod=1e8+7;

#define uLL unsigned long long
const long long inf=1e18;
typedef pair<int,int> PII;
typedef long long LL;
using node=tuple<uLL,int,int>;
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
int x[N],y[N],r[N];
int id[N];
vector<PII> row[N],col[N];
vector<int> numx,numy;
int findx(int x){
    return lower_bound(numx.begin(),numx.end(),x)-numx.begin();
}
int findy(int x){
    return lower_bound(numy.begin(),numy.end(),x)-numy.begin();
}
int xx[N],yy[N];
void solve()
{
    cin>>n>>k;
    dsu d(n+10);
    numx.clear();numy.clear();
    ///unordered_map<int,vector<PII>> row,col;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i]>>r[i];
        numx.push_back(x[i]);numy.push_back(y[i]);

    }
    sort(numx.begin(),numx.end());
    numx.erase(unique(numx.begin(),numx.end()),numx.end());
    sort(numy.begin(),numy.end());
    numy.erase(unique(numy.begin(),numy.end()),numy.end());
    for(int i=1;i<=n;i++){
        xx[i]=findx(x[i]);
        yy[i]=findy(y[i]);
        row[xx[i]].emplace_back(y[i],i);
        col[yy[i]].emplace_back(x[i],i);
    }
    for(int i=0;i<numx.size();i++) sort(row[i].begin(),row[i].end());
    for(int i=0;i<numy.size();i++) sort(col[i].begin(),col[i].end());
    for(int i=1;i<=n;i++)
    {
        auto v=row[xx[i]];
        int l=0,r=v.size()-1;
        while(l<r){
            int mid=l+r>>1;
            if(v[mid].first>y[i]) r=mid;
            else l=mid+1;
        }

        if(abs(v[l].first-y[i])<=k){

            d.unite(i,v[l].second);
        }
        if(l-2<v.size()){
            l-=2;
            if(abs(y[i]-v[l].first)<=k)
            d.unite(i,v[l].second);
        }
        
        v=col[yy[i]];
        l=0,r=v.size()-1;
        while(l<r){
            int mid=l+r>>1;
            if(v[mid].first>x[i]) r=mid;
            else l=mid+1;
        }
        if(abs(v[l].first-x[i])<=k){
            d.unite(i,v[l].second);
        }
        if(l-2<v.size()){
            l-=2;
            if(abs(x[i]-v[l].first)<=k)
            d.unite(i,v[l].second);
        }
    }
    for(int i=1;i<=n;i++){
        id[i]=d.get(i);
    }
    auto check=[&](int tim){
        set<int> st;
        for(int i=1;i<=n;i++)
        {
            if(r[i]<=tim) st.insert(id[i]);
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(st.count(id[i])) continue;
            cnt++;
            st.insert(id[i]);
        }
        return cnt<=tim+1;
    };
    
    int l=0,r=1e9;
    while(l<r){
        int mid=l+r>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l<<"\n";
    for(int i=1;i<=n;i++){
        row[xx[i]].clear();
        col[yy[i]].clear();
    }

}

signed main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int t=1;

    cin>>t;
    while(t--) solve();
    return 0;
}
