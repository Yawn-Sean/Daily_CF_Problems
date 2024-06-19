#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=2*N,mod=1e9+7;
#define int long long
#define uLL unsigned long long
const long long inf=1e18;
typedef pair<int,int> PII;
typedef long long LL;

int n,m,k;
int f[100][100];
void solve()
{
    string a;cin>>a;
    string b;cin>>b;
    memset(f,0x3f,sizeof(f));
    for(int i=0;i<26;i++)
    f[i][i]=0;
    cin>>m;
    for(int i=1;i<=m;i++){
        char x,y;int z;cin>>x>>y>>z;
        f[x-'a'][y-'a']=min(f[x-'a'][y-'a'],z);
    }
    for(int k=0;k<26;k++){
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    if(a.size()!=b.size()){
        cout<<-1;return ;
    }
    int res=0;
    string s;
    for(int i=0;i<a.size();i++){
        char x=a[i],y=b[i];
        
        int ans=inf;
        for(int j=0;j<26;j++){
            ans=min(ans,f[x-'a'][j]+f[y-'a'][j]);
        }
        if(ans==inf){
            cout<<"-1\n";return ;
        }
        for(int j=0;j<26;j++){
            if(ans==f[x-'a'][j]+f[y-'a'][j]){
                s+=(char)(j+'a');break;
            }
        }
        res+=ans;
    }
    cout<<res<<"\n";cout<<s;
}   
signed main()
{
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
}
