#include<bits/stdc++.h>
using namespace std;
const int N=110+10,M=2*N,mod=1e9+7;
#define int long long
#define uLL unsigned long long
const long long inf=1e18;
typedef pair<int,int> PII;
typedef long long LL;
using node=tuple<int,int,int>;
int n,m,k;
int g[N][N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

void solve()
{
    cin>>n;
    string s;cin>>s;
    m=s.size();
    s="?"+s;
    int x=1,y=1;
    
    bool f=true;
    for(int i=1;i<=m;i++)
    {
        if(s[i]=='R') x++;
        else y++;
        if(i>1&&s[i]!=s[i-1]){
            f=false;
        }
    }
    if(f){
        cout<<n<<"\n";return ;
    }
  //  cout<<x<<" "<<y<<"\n";
    int res=(n-x+1)*(n-y+1);
    //cout<<res<<"\n";
    int i=2;
    res++;
    while(s[i]==s[i-1]) res++,i++;
    for(;i<=m;i++){
        res++;
        if(s[i]=='R') res+=(n-y);
        else res+=(n-x);
    }
    cout<<res<<"\n";
  
}

signed main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}
