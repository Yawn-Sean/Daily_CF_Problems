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
const int M=2*N;
struct gph{
  int to[M],nx[M],hd[N],t=1;
  void add(int u,int v){
    to[++t]=v,nx[t]=hd[u],hd[u]=t;
  }
}g;
int n,m;
int dis[N];
void solve(){
  n=read(),m=read();
  vector<pii>ans;
  for(int i=1;i<=m;i++){
    int u=read(),v=read();
    g.add(u,v);
    g.add(v,u);
    if(u!=v){
      if(u<v){
        ans.push_back({u,v});
      }
      else{
        ans.push_back({v,u});
      }
    }
  }
  
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      dis[j]=2e9;
    }
    dis[i]=0;
    queue<int>q;
    q.push(i);
    while(q.size()){
      int u=q.front();
      q.pop();
      for(int j=g.hd[u];j;j=g.nx[j]){
        if(dis[g.to[j]]>dis[u]+1){
          dis[g.to[j]]=dis[u]+1;
          q.push(g.to[j]);
        }
      }
    }
    for(int j=1;j<=n;j++){
      if(dis[j]==2&&i<j){
        ans.push_back({i,j});
      }
    }
  }
  sort(ans.begin(),ans.end());
  ans.erase(unique(ans.begin(),ans.end()),ans.end());
  printf("%lld\n",ans.size());
  for(auto[u,v]:ans){
    printf("%lld %lld\n",u,v);
  }
}

bool end_mem;
signed main(){
  // int TTTT=1;
  int TTTT=read();
  while(TTTT--){
    solve();
    for(int i=1;i<=n;i++){
      g.hd[i]=0;
    }
    g.t=1;
  }
  // fprintf(stderr,"Memory Awa %.12lf MB.\n",abs(&begin_mem-&end_mem)/1024.0/1024);
  // fprintf(stderr,"Memory Awa %.12lf GB.\n",abs(&begin_mem-&end_mem)/1024.0/1024/1024);
}