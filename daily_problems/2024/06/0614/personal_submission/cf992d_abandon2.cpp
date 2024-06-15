#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
#define int long long
typedef long long LL;
const LL mx=LLONG_MAX;
int ne[N],le[N];
int a[N];

void solve(){
    int n;LL k;cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }   
    ne[n+1]=n+1;
    for(int i=n;i>=1;i--){
        if(a[i+1]!=1)ne[i]=i+1;
        else ne[i]=ne[i+1];
    }
    // for(int i=1;i<=n;i++){
    //     cout<<ne[i]<<" ";
    // }
    // cout<<"\n";
    int ans=0;
    for(int i=1;i<=n;i++){
        LL p=1,s=0;int cnt=0;

        for(int now=ne[i],pre=i;pre!=n+1;pre=now,now=ne[now]){
            if(pre>=n+1)break;
            if(p>=mx/a[pre]||cnt>62)break;
            cnt++;
            //cout<<i<<" "<<pre<<" "<<now<<" ccc\n";
            p*=a[pre];
            s+=a[pre];
            if(p==k*s){
                ans++;
            }
            if(pre>=n+1)break;
            int d=p-s*k;
            if(p/k>s&&p/k<=(s+now-pre-1)&&d%k==0)ans++;
            //cout<<p<<" "<<s<<"qq\n";
            s+=(now-pre-1);
            if(now>=n+1)break;
            //cout<<p<<" "<<s<<"kk\n";
            //cout<<ans<<"\n\n";
        }
    }
    cout<<ans<<"\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
