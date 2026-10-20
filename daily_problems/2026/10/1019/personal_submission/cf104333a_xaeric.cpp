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
const int N=3e5+5;
int fac[N],ifac[N];
int qpow(int a,int k,int p=P){
  int r=1;
  while(k){
    if(k&1){
      r=r*a%p;
    }
    a=a*a%p;
    k/=2;
  }
  return r;
}
void zuhe(int n){
  fac[0]=1;
  for(int i=1;i<=n;i++){
    fac[i]=fac[i-1]*i%P;
  }
  ifac[n]=qpow(fac[n],P-2);
  for(int i=n-1;~i;i--){
    ifac[i]=ifac[i+1]*(i+1)%P;
  }
}
int c(int n,int m){
  if(n<0||m<0){
    return 0;
  }
  if(m>n){
    return 0;
  }
  return fac[n]*ifac[m]%P*ifac[n-m]%P;
}
int n,a[N],b[N],cao[35];
void solve(){
  n=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  for(int i=1;i<=n;i++){
    b[i]=read();
  }
  sort(a+1,a+n+1);
  sort(b+1,b+n+1);
  for(int i=1;i<=n;i++){
    for(int k=0;k<=18;k++){
      int t=(b[i]>>k)%2;
      if(t){
        cao[k]++;
      }
    }
  }
  int ans=0;
  for(int i=1;i<=n;i++){
    for(int k=0;k<=18;k++){
      int t=(a[i]>>k)%2;
      if(t){
        ans+=(1<<k)*(n-cao[k])%P;
      }
      else{
        ans+=(1<<k)*(cao[k])%P;
      }
      ans%=P;
    }
  }
  ans=(ans*fac[n-1]%P);
  printf("%lld\n",ans);
}

bool end_mem;
signed main(){
  zuhe(N-5);
  int TTTT=1;
  // int TTTT=read();
  while(TTTT--){
    solve();
  }
  // fprintf(stderr,"Memory Awa %.12lf MB.\n",abs(&begin_mem-&end_mem)/1024.0/1024);
  // fprintf(stderr,"Memory Awa %.12lf GB.\n",abs(&begin_mem-&end_mem)/1024.0/1024/1024);
}