#include<bits/stdc++.h>

// #define XAERIC666
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#ifndef XAERIC666
  #define xaeric(...) {fprintf(stderr,__VA_ARGS__);fflush(stderr);}
#else
  #define xaeric(...) 114514
#endif
int read(){
  int x=0,f=1;
  char c=getchar();
  while(c<'0'||'9'<c){if(c=='-')f=-1;c=getchar();}
  while('0'<=c&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}
// void in(int*a,int n){for(int i=1;i<=n;i++)a[i]=read();}
// void out(int*a,int n){for(int i=1;i<=n;i++)printf("%lld%c",a[i]," \n"[i==n]);}
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define _rep(i,a,b) for(int i=(b);i>=(a);--i)
#define YES puts("YES");
#define NO puts("NO");
void chmax(auto&a,auto b){if(a<b)a=b;}
void chmin(auto&a,auto b){if(a>b)a=b;}
using namespace std;
bool begin_mem;

const int P=1e9+7;
const int N=21;
int n,a[N],b[N];
int gr[N][N];
void solve(){
  n=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  for(int i=1;i<=n;i++){
    b[i]=read();
  }
  int ans=0;
  for(int k=30;~k;k--){
    
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        gr[i][j]=(a[i]+b[j])>>k&1;
      }
    }
    vector<vector<int>>dp(2,vector<int>(1<<n));
    dp[0][0]=1;
    for(int s=0;s<(1<<n);s++){
      for(int j=0;j<=1;j++){
        for(int i=0;i<n;i++){
          if(s>>i&1){
            continue;
          }

          int x=__builtin_popcount(s);
          dp[j^gr[x+1][i+1]][s|(1<<i)]+=dp[j][s];
          dp[j^gr[x+1][i+1]][s|(1<<i)]%=P;
        }
      }
    }
    ans=(ans+dp[1][(1<<n)-1]%P*((1<<k)%P)%P);
    ans%=P;
  }
  printf("%lld\n",ans);
}

bool end_mem;
signed main(){
  int TTTT=1;
  // int TTTT=read();
  while(TTTT--){
    solve();
  }
  // fprintf(stderr,"Memory Awa %.12lf MB.\n",abs(&begin_mem-&end_mem)/1024.0/1024);
  // fprintf(stderr,"Memory Awa %.12lf GB.\n",abs(&begin_mem-&end_mem)/1024.0/1024/1024);
}