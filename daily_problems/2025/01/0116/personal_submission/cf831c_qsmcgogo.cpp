#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;

int a[5555],b[5555];
signed main(){
  ios::sync_with_stdio(false);cin.tie(0);
  int _=1;
//  cin>>_;
  while(_--){
    int m,i,j,k;
    int n;
    int x,y,c=0;
    cin>>n>>k;
    map<int,int>mp;
    for(i=0;i<n;i++)cin>>a[i];
    for(i=0;i<k;i++)cin>>b[i],mp[b[i]]++;
    set<int>s;
    int su=0;
    for(i=0;i<n;i++){
      su+=a[i];
      int st=b[0]-su;
      int jud=1;
      for(j=0;j<n;j++){
        st+=a[j];
        mp[st]--;
      }
      for(auto j:mp){
        if(j.second>0)jud=0;
      }
      for(j=n-1;j>=0;j--){
        mp[st]++;
        st-=a[j];
      }
      map<int,int>mp2;
      for(auto j:mp){
        if(j.second)mp2[j.first]=j.second;
      }
      swap(mp,mp2);
      if(jud)s.insert(st);
    }
    cout<<s.size()<<'\n';
    
  }

    

}
