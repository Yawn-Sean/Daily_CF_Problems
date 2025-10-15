#include <bits/stdc++.h>
using namespace std;
#define int long long
int fa[111122];
int fat[111122];
int mod=1e9+7;
int tong[202020];
string s[1010];
int vis[1010][1010];
set<int>sn[1010],sm[1010];
int op[4][2]={0,1,0,-1,1,0,-1,0};
int a[900009],c[202002];
int power(int x,int y){
    int res=1;
    while(y){
        if(y&1)res=res*x%mod;
        y>>=1;
        x=x*x%mod;
    }
    return res;
}
signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
   // int n,i,j;
    int _=1;

    //  cin>>_;
    while(_--){
        int n,i,j,k,m;
        cin>>n>>m;
        for(i=0;i<m;i++)cin>>a[i];
        int p=a[0];
        map<int,int>mp;
        for(i=1;i<=n;i++)mp[i]++;
        for(i=1;i<m;i++){
            if(c[p]==0){
                c[p]=(a[i]-a[i-1]+n-1)%n+1;
                mp[(a[i]-a[i-1]+n-1)%n+1]--;
                if(mp[(a[i]-a[i-1]+n-1)%n+1]<0)return cout<<-1,0;
            }
            else if(c[p]!=(a[i]-a[i-1]+n-1)%n+1)return cout<<-1,0;
            p=a[i];
        }
        j=0;
        for(i=1;i<=n;i++){
            while(j<n+1&&!mp[j])j++;
            if(c[i]==0)c[i]=j,mp[j]--;
        }
        for(i=1;i<=n;i++)cout<<c[i]<<" ";
        
    }
    return 0;
}
/*
9
ADD 1
ADD 2
ADD 3
ADD 4
ADD 5
ACCEPT 3
ACCEPT 4
ADD 3
ADD 4
*/
