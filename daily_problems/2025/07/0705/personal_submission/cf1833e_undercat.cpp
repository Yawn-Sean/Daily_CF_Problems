#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;cin>>n;
    vector<int>a(n),b(n),v(n),g[n];
    for(auto&i:a)cin>>i,i--;
    for(int i=0;i<n;i++)b[i]=i;
    auto get=[&](auto&&get,int i)->int{
        if(b[i]==i)return i;
        return b[i]=get(get,b[i]);
    };
    int ans1=0,ans2=0,temp=0;
    set<int>st;
    for(int i=0;i<n;i++){
        int bi=get(get,i);
        int bj=get(get,a[i]);
        b[bi]=bj;
    }
    for(int i=0;i<n;i++){
        int v=get(get,b[i]);
        st.insert(v);
        g[v].push_back(i);
    }
    ans2=st.size();
    for(int i=0;i<n;i++){
        int len=g[i].size();
        if(len==0)continue;
        if(len<=2){
            temp=1;
            continue;
        }
        vector<int>t;
        for(auto j:g[i])t.push_back(a[j]);
        sort(t.begin(),t.end());
        t.erase(unique(t.begin(),t.end()),t.end());
        if(len==t.size())ans1++;
        else temp=1;
    }
    cout<<ans1+temp<<' '<<ans2<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;while(t--)
    solve();
}