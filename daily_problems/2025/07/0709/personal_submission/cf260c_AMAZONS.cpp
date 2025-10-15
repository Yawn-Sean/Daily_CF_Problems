#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
#define int long long

void solve(){
	int n,x;cin>>n>>x;
    vector<int> v(n+1);
    int mini=1e15+7,pos=0;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        if(v[i]<mini){
            mini=v[i];pos=i;
        }
    }
    for(int i=1;i<=n;i++){
        int tmp=0;
        if(v[i]==mini){
            tmp=(i+v[i]%n);
            if(tmp==x){
                pos=i;
                break;
            }
        }
    }
    vector<int> nv=v;int ans=0;
    int now=nv[pos];
    for(int i=1;i<=n;i++)ans+=now,nv[i]-=now;
    int flag=0;
    for(int i=x;i>=1;i--){
        if(nv[i]!=0)
        nv[i]--,ans++;
        else {flag=i;break;}
    }
    for(int i=n;i>x&&!flag;i--){
        if(nv[i]!=0)
        nv[i]--,ans++;
        else {flag=i;break;}
    }


    
    nv[flag]=ans;
    for(int i=1;i<=n;i++){
        cout<<nv[i]<<" ";
    }

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
