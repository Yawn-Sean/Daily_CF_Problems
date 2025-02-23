#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

signed main(){
  // ios::sync_with_stdio(false);cin.tie(0);
  int _=1;
//  cin>>_;
  while(_--){
    int i,j,k,x;
    string s,t;
    cin>>s>>t;
    int n=s.size();
    s[n-1]++;
    for(i=n-1;i>0;i--){
      if(s[i]>'z')s[i]='a',s[i-1]++;
    }
    if(s==t)cout<<"No such string";
    else cout<<s;


  }

  
}

