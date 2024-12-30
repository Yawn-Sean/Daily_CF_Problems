#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10,M=2*N,mod=1e9+7;
#define int long long
#define uLL unsigned long long
const long long inf=1e18;
typedef pair<int,int> PII;
typedef long long LL;

int n,m,k;
int a[N];
int judge[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int zcnt=0,fcnt=0;
    int ztot=0,ftot=0;
    for(int i=1;i<=n;i++){
        if(a[i]<=i){
            fcnt++;
            ftot+=i-a[i];
        }else{
            zcnt++;
            ztot+=a[i]-i;
            judge[a[i]-i]++;
        }
    }
    //pi-i>0
    //pi-i<=0
    int ans=ztot+ftot,idx=0;
    for(int i=1;i<n;i++){
        ztot-=zcnt;
        zcnt-=judge[i];
        ftot+=fcnt;
        fcnt+=judge[i];
        int x=a[n-i+1];
        ftot-=n-x,fcnt--;
        ftot--;
        if(x>1)
        {
            judge[x-1+i]++;
            ztot+=x-1;
            zcnt++;
        }else fcnt++;
        if(ans>ftot+ztot){
            ans=ftot+ztot;
            idx=i;;
        }
    }
    cout<<ans<<" "<<idx;
    
}   
signed main()
{
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
}
