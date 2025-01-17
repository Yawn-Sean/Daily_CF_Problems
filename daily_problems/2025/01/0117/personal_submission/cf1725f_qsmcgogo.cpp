#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=998244353;
map<int,int>ans;
int su[1202020];
pair<int,int>a[202020],b[202020];
int q[202020],tot;
int hs(int x){
  return lower_bound(q+1,q+1+tot,x)-q;
}
signed main(){
  ios::sync_with_stdio(false);cin.tie(0);
  int _=1;
//  cin>>_;
  while(_--){
    int m,i,j,k,tt,x;
    int n;
    cin>>n;
    for(i=0;i<n;i++){
      cin>>a[i].first>>a[i].second;
    }
    for(i=0;i<30;i++){
      tot=0;
      int cc=0;
      for(j=0;j<n;j++){
        b[j].first=a[j].first%(1<<i);
        b[j].second=a[j].second%(1<<i);
        if(a[j].second-a[j].first+1<(1<<i))q[++tot]=b[j].first,q[++tot]=b[j].second+1;
      }
      int j=1;
      sort(q+1,q+1+tot);  
      tot=unique(q+1,q+1+tot)-(1+q);
      for(j=0;j<=2*n;j++){
        su[j]=0;
      }
      for(j=0;j<n;j++){
        if(a[j].second-a[j].first+1>=(1<<i))cc++;
        else{
          su[hs(b[j].first)]++;
          su[hs(b[j].second+1)]--;
          if(b[j].second<b[j].first){
            su[0]++;
          }
        }
      }
      int ma=0;
      for(j=1;j<=2*n;j++){
        su[j]+=su[j-1];
        ma=max(ma,su[j]);
      }
      ans[1<<i]=cc+ma;
    }
    int q;
    cin>>q;
    while(q--){
      int x;
      cin>>x;
      cout<<ans[x&-x]<<'\n';
    }
  }

    

}
/*

*/
