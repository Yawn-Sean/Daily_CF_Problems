#include<bits/stdc++.h>
using namespace std;
#define int long long
int sum=0;
int mod=1e9+7;
int a[2021120];
int power(int a,int b){
  int res=1;
  while(b){
    if(b&1)res=res*a%mod;
    b>>=1;
    a=a*a%mod;
  }
  return res;
}
signed main(){
  int _=1;
  while(_--){
    int m,i,j,x=1,y;
    int n;
    cin>>n>>m;
    int s=0,res=0;;
    for(i=1;i<=n;i++)cin>>a[i],s+=a[i];
    sort(a+1,a+n+1);

    int zs=s-a[n];
    map<int,int>mp;
    for(i=1;i<=n;i++){
      mp[-a[i]]++;
    }
    while(1){
      auto i=*mp.begin();
      int chu=i.second/m,y=i.second%m;
      if(y==0){
        mp[i.first+1]+=chu;
        zs++;
        mp.erase(mp.find(i.first));
      }
      else break;
      
    }
    cout<<power(m,min(s,zs));
  }

    

}
