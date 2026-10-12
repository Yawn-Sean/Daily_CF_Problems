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

const int P=998244353;
const int N=3e5+5;
int n,a[N];
int dp[N][2];
set<pii>q;
void ins(int x,int y){
  pii u={x,y};
  while(q.size()){
    auto it=q.lower_bound(u);
    if(it!=q.end()){
      if(it->se<=y){
        q.erase(it);
      }
      else{
        break;
      }
    }
    else{
      break;
    }
  }
  auto it=q.lower_bound(u);
  if(it==q.begin()||prev(it)->se<y){
    q.insert(u);
  }
}
void solve(){
  n=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  dp[1][0]=1;
  dp[2][1]=1+(a[1]>a[2]);
  ins(a[1],1);
  ins(a[1],dp[2][1]);
  
  
  for(int i=2;i<=n;i++){
    auto it=q.lower_bound({a[i],0});
    if(it==q.begin()){
      dp[i][0]=1;
    }
    else{
      it--;
      dp[i][0]=1+(it->se);
    }

    if(i<n){
      dp[i+1][1]=dp[i][0];
      if(a[i+1]<a[i]){
        auto it=q.lower_bound({a[i+1],0});
        if(it==q.begin()){
          chmax(dp[i+1][1],2);
        }
        else{
          it--;
          chmax(dp[i+1][1],2+(it->se));
        }
      }
      ins(a[i],dp[i+1][1]);
    }
    ins(a[i],dp[i][0]);
  }
  int ans=0;
  for(int i=1;i<=n;i++){
    ans=max({ans,dp[i][0],dp[i][1]});
    // xaeric("   %lld %lld\n",dp[i][0],dp[i][1]);
    dp[i][0]=dp[i][1]=0;
  }
  printf("%lld\n",ans);
  q.clear();
}

bool end_mem;
signed main(){
  // int TTTT=1;
  int TTTT=read();
  while(TTTT--){
    solve();
  }
  // fprintf(stderr,"Memory Awa %.12lf MB.\n",abs(&begin_mem-&end_mem)/1024.0/1024);
  // fprintf(stderr,"Memory Awa %.12lf GB.\n",abs(&begin_mem-&end_mem)/1024.0/1024/1024);
}