#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=2*N,mod=1e9+7;
#define uLL unsigned long long
const long long inf=1e18;
typedef pair<int,int> PII;
typedef long long LL;
using node=tuple<int,int,int>;
int n,m,k;
int a[N];
map<int,int> mp[20];
int pw[N];
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    pw[0]=1;
    for(int i=1;i<=15;i++){
        pw[i]=1ll*pw[i-1]*10;
        pw[i]%=k;
    }
    for(int i=1;i<=n;i++)
    {
        string s=to_string(a[i]);
        int len=s.size();
        mp[len][a[i]%k]++;
        // for(int j=1;j<=10;j++)
        // {
        //     mp[j][(1ll*a[i]*pw[j])%k]++;
        // }
    }
    LL res=0;
    for(int i=1;i<=n;i++)
    {
        string s=to_string(a[i]);
        int len=s.size();
        mp[len][a[i]%k]--;
        for(int j=1;j<=10;j++)
        {
            int x=1ll*a[i]*pw[j]%k;
            x=(((k-x)%k)+k)%k;
            if(mp[j].count(x))
            res+=mp[j][x];
        }
        
        mp[len][a[i]%k]++;
        // int x=a[i]%k; 
        // mp[len][(1ll*a[i]*pw[len])%k]--;
        // if(mp[len].count(((k-x)%k+k)%k))
        // res+=mp[len][((k-x)%k+k)%k];
        // mp[len][(1ll*a[i]*pw[len])%k]++;
    }
    cout<<res;
}

signed main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}
