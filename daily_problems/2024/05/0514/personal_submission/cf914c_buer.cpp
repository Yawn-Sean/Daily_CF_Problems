#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=2*N,mod=1e9+7;
#define int long long
#define uLL unsigned long long
const long long inf=1e18;
typedef pair<int,int> PII;
typedef long long LL;
using node=tuple<int,int,int>;
int n,m,k;
int a[N];
vector<int> g[N];
string s;
int f[1010][1010][2][2];
int dfs(int i,int limit,int num,int now)
{
    if(i==s.size()) return num&&(now==0);
    int &res=f[i][now][limit][num];
    if(res!=-1) return res;
    res=0;
    if(!num) res=dfs(i+1,false,false,now);
    int up,di;
    if(limit) up=(s[i]-'0');
    else up=1;
    di=0;
    if(!num) di=1;
    for(int d=di;d<=up;d++){
        if(now-(d==1)>=0)
res+=dfs(i+1,limit&&d==up,true,now-(d==1));
        res%=mod;
    }
    return res;
}
void solve()
{
    
    cin>>s>>k;
    //只关心二进制的个数
    if(k==0){
        cout<<1;return ;
    }
    if(k>5){
        cout<<"0\n";return ;
    }
    for(int i=1;i<=1000;i++)
    {
        int cnt=1;
        int x=i;
        while(x>1)
        {
            cnt++;
            x=__builtin_popcount(x);
        }
  
       // cout<<cnt<<" "<<i<<"\n";
        g[cnt].push_back(i);
    }
    // for(int i=1;i<=1000;i++){
    //     if(g[i].size()) cout<<i<<"\n";
    // }
    memset(f,-1,sizeof(f));
   // int res=dfs(0,1,0,2);
   int res=0;
    for(auto x:g[k]) 
    {
        res=(res+dfs(0,1,0,x))%mod;
    }
    if(k==1) res--;
    res=(res%mod+mod)%mod;
   // res=(res+dfs(0,1,0,x))%mod;
    cout<<res;
}

signed main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}
