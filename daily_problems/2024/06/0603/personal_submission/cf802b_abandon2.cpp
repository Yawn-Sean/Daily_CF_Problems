#include<bits/stdc++.h>
using namespace std;
const int N=4e5+10;
typedef pair<int,int>PII;
#define x first
#define y second
int lst[N],nxt[N],vis[N],a[N];

void solve(){
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        nxt[lst[a[i]]]=i;
        lst[a[i]]=i;
        nxt[i]=1e9;
    }    

    priority_queue<PII>q;

    int ans=0,tot=0;
    for(int i=1;i<=n;i++){
        while(!q.empty()&&!vis[q.top().y])
            q.pop();
        if(!vis[a[i]]){
            ans++;
            vis[a[i]]=1;
            if(!q.empty()&&tot>=k){
                vis[q.top().second]=0;
                q.pop();
            }
            else{
                tot++;
            }
        }
        q.push({nxt[i],a[i]});
    }
    cout<<ans<<"\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
