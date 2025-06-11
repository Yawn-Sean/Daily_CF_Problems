#include<bits/stdc++.h>
#define PI acos(-1.0)
using namespace std;
typedef long long ll;
const int maxn = 7;
ll n, ans1, ans2;
int i_, j_;
int a[maxn][maxn], b[maxn][maxn];
 
pair<int,int> t;
map<pair<int,int>, char> mp;
vector<pair<int,int> > vec;
 
void init() {
    cin>>n>>i_>>j_;
    for(int i=1;i<=3;++i)
    {
        for(int j=1;j<=3;++j)
        cin>>a[i][j];
    }
    for(int i=1;i<=3; ++i) 
    {
        for(int j=1;j<=3;++j)
            cin>>b[i][j];
    }
}
void solve() 
{
    ans1=0,ans2=0;
    int ti=i_,tj=j_;
    ll ccc=0;
    while(1)
    {
        t=make_pair(ti,tj);
        if(mp.count(t)) 
            break;
        if(ti==1&&tj==3) 
            mp[t] = 1;
        else 
        if(ti==3&&tj==1)
            mp[t] = 2;
        else 
        {
            if(ti==tj)
                mp[t]=0;
            else 
            if(ti>tj) 
                mp[t]=1;
            else mp[t]=2;
        }
        vec.push_back(t);
        int tt=ti;
        ti=a[ti][tj];
        tj=b[tt][tj];
        ccc++;
        if(ccc==n) 
            break;
    }
    int i;
    for(i=0;i<vec.size();++i) 
    {
        if(vec[i].first==t.first&&vec[i].second==t.second) 
            break;
        if(mp[vec[i]]==1) 
            ans1++;
        else 
            if(mp[vec[i]]==2) 
                ans2++;
    }
    n-=i;
    ll len=(ll)(vec.size()-i);
    ll cnt=(n/len),mod=(n%len);
    ll t1=0,t2=0;
    for(;i<vec.size()&& mod; ++i) 
    {
        if(mp[vec[i]]==1) 
        { 
            ans1++; 
            t1++;
        }
        else 
        if(mp[vec[i]]==2) 
        { 
            ans2++;
            t2++;
        }
        mod--;
    }
    for(;i<vec.size();++i) 
    {
        if(mp[vec[i]]==1) 
        t1++;
        else 
        if(mp[vec[i]]==2) 
        t2++;
    }
    t1*=cnt;t2*=cnt;
    ans1+=t1,ans2+=t2;
    cout<<ans1<<" "<<ans2<<endl;
}
int main() 
{
    init();
    solve();
    return 0;
}