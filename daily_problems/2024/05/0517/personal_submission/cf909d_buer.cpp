#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=2*N,mod=1e9+7;
#define int long long
#define uLL unsigned long long
const long long inf=1e18;
typedef pair<int,int> PII;
typedef long long LL;
using node=tuple<int,int,int>;
int n,m,k;
char a[N];
int sz[N],c[N];
void solve()
{
    string a;cin>>a;
    n=a.size();a="?"+a;
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(a[i]==c[cnt]) sz[cnt]++;
        else c[++cnt]=a[i],sz[cnt]=1;
    }
    int res=0;
    while(cnt>1){
        for(int i=1;i<=cnt;i++){
            if(i==1||i==cnt) sz[i]--;
            else sz[i]-=2;
        }
        int cur=0;
        for(int i=1;i<=cnt;i++){
            if(sz[i]<=0) continue;
            if(c[i]==c[cur]) sz[cur]+=sz[i];
            else c[++cur]=c[i],sz[cur]=sz[i];
        }
        res++;
        cnt=cur;
    }
    cout<<res;
}

signed main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int t=1;

   // cin>>t;
    while(t--) solve();
    return 0;
}
