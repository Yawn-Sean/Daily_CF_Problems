#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
#define int long long
bool cmp(pair<int,int> p1,pair<int,int> p2){
    if(p1.first==p2.first){
        return p1.second>p2.second;
    }
    return p1.first>p2.first;
}
void solve(){
	int n,m,ou=0,ji=0;cin>>n>>m;vector<int> nv(n+1);
    vector<pair<int,int>> v(n+1);set<int> s;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        v[i]={x,i};
        nv[i]=x;
    }
    int ha=n/2;
    vector<int> vis(n+1,0);
    sort(v.begin()+1,v.end(),cmp);
    set<int> s1,s2;
    for(int i=1;i<=n;i++){
        auto it=v[i];
        int f=it.first,pos=it.second;
        if(f&1&&s1.size()<ha&&s1.find(f)==s1.end()){
            vis[pos]=f;
            s1.insert(f);
        }
        else if(f%2==0&&s2.size()<ha&&s2.find(f)==s2.end()){
            vis[pos]=f;
            s2.insert(f);
        }

    }

    // cout<<s1.size()<<" "<<s1.size()<<endl;
    int v1=1,v2=2,maxi=0,ans=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]&&s1.size()<ha){
            while(s1.find(v1)!=s1.end())
            {v1+=2;}
            vis[i]=v1;s1.insert(v1);
            maxi=max(maxi,v1);
            ans++;
        }
        else if(!vis[i]&&s2.size()<ha){
            while(s2.find(v2)!=s2.end())
            {v2+=2;}
            s2.insert(v2);
            vis[i]=v2;
            maxi=max(maxi,v2);
            ans++;
        }
    }
    if(maxi>m){cout<<-1<<endl;return ;}
    cout<<ans<<endl;
    for(int i=1;i<=n;i++){
        cout<<vis[i]<<" ";
    }
    // cout<<'\n';


}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}