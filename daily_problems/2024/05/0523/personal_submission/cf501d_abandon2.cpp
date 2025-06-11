#include <bits/stdc++.h>    
using namespace std;    
typedef long long LL;
#define int long long
const int N=200010,md=1e9+7;  

int c[N],n;

int lowbit(int x){
  return x&(-x);
}

void add(int k,int x){
  for(int i=k;i<=n;i+=lowbit(i)){
    c[i]+=x;
  }
}

int ask(int k){
  int res=0;
  for(int i=k;i>=1;i-=lowbit(i)){
    res+=c[i];
  }
  return res;
}

int kth(int x){
  int l=-1,r=n+1;
  while(l+1<r){
    int mid=l+r>>1;
    if(ask(mid)>=x)r=mid;
    else l=mid;
  }
  return r;
}

int a[N],b[N];
signed main(){    
    cin>>n; 
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=n;i>=1;i--){
       b[i]=ask(a[i]+1);
       add(a[i]+1,1);
    }
    for(int i=1;i<=n;i++)add(a[i]+1,-1);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=n;i>=1;i--){
      b[i]+=ask(a[i]+1);
      add(a[i]+1,1);
    }
    
    for(int i=n;i>=1;i--){
      b[i-1]+=b[i]/(n-i+1);
      b[i]%=(n-i+1);
    }


    for(int i=1;i<=n;i++){
      int t=kth(b[i]+1);
      cout<<t-1<<" ";
      add(t,-1);
    }
}    
