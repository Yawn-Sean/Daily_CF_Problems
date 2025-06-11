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
int pre[N],suf[N];
void solve()
{
    string s;cin>>s;n=s.size();
    s+=s;
    int mx=1,now=1;
    for(int i=1;i<2*n;i++){
        if(s[i]!=s[i-1]) now++;
        else now=1;
        mx=max(mx,min(now,n));
    }
    cout<<mx;
}

signed main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int t=1;

   // cin>>t;
    while(t--) solve();
    return 0;
}
