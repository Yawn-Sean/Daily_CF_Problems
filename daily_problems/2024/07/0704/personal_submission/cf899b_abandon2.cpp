#include<bits/stdc++.h>
using namespace std;
const int N =2e5+10;
using PII=pair<int,int>;
int a[N],ne[N],le[N];
int s[N],c[N];


void solve(){
    int n;cin>>n;
    int tot=0;
    for(int i=n;i>=1;i--)cin>>a[i];
    for(int i=1;i<=n;i++){
        if(a[i]==a[i-1]){
            s[tot]++;
        }
        else{
            c[++tot]=a[i];
            s[tot]=1;
        }
    }

    priority_queue<PII>q;
    for(int i=1;i<=tot;i++){
        ne[i]=i+1;
        le[i]=i-1;
        q.push({s[i],i});
    }

    int ans=0;
    std::vector<int> v(n+2,0);
    while(q.size()){
        auto [len,st]=q.top();q.pop();
        //cout<<st<<" "<<len<<" \n";
        if(v[st])continue;
        int x=le[st],y=ne[st];
        ne[x]=y;le[y]=x;
        v[st]=1;
        if(x&&c[x]==c[y]){
            le[ne[y]]=x;
            ne[x]=ne[y];
            v[y]=1;
            q.push({s[x]+=s[y],x});
        }
        ans++;
    }
    cout<<ans<<"\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
