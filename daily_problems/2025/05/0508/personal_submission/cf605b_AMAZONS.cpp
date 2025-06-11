#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
typedef long long ll;
void solve(){
	int n,m;cin>>n>>m;
    vector<pair<int,int>> vp;
    for(int i=1;i<=m;i++)
    {
        int x,y;cin>>x>>y;
        vp.push_back({x,y});
    }
    vector<int> range(m);
    iota(range.begin(),range.end(),0);
    sort(range.begin(), range.end(),
    [&] (int a, int b) 
    {return vp[a].first < vp[b].first || vp[a].first == vp[b].first && vp[a].second > vp[b].second;});
    vector<int> st(m),ed(m);
    int cur=2,u=2,v=2;
    for(auto& it:range)
    {
        if(vp[it].second==1){
            st[it]=1;
            ed[it]=cur++;
        }
        else{
            v++;
            if(v>=u)
            {
                u++;v=2;
            }
            if(u>=cur)
            {cout<<-1<<endl;return ;}
            st[it]=u;
            ed[it]=v;
        }
    }
    for(int i=0;i<m;i++)
    {
        cout<<st[i]<<" "<<ed[i]<<endl;
    }
}
int main(){
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
