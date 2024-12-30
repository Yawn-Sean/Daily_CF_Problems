#include <bits/stdc++.h>
using namespace std;
#define endl '\n' 
using i64 = long long;
typedef pair<int,int>pii;
#define N 2000100
int t;
int cnt[N];
void solve(){
     int n;
     cin>>n;
     for(int i=1;i<=n;i++) cnt[i]=0;
     for(int i=0;i<n;i++){
        int x;cin>>x;
        cnt[x]++;
     }
     vector<int>s;
     for(int i=1;i<=n;i++){
        if(cnt[i]) s.push_back(cnt[i]);
     }
     i64 ans=1e18;
     //for(auto x:s) cout<<x<<" ";
     for(int x=s[0]+1;x>=2;x--){
        bool flag=false;
        i64 res=0;
        for(auto y:s){
            if(y%x==0){
                res+=y/x;
            }
            else{
                if(y/x+y%x<x-1) {
                    flag=true;
                    break;
                }
                else  res+=y/x+1;
            }
        }
        if(flag) continue;
        else{
            ans=min(ans,res);
        }
     }
     cout<<ans<<endl;
   
}
int main(){  
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);   
    cin>>t ;
    while(t--){
        solve();
    } 
    return 0 ;
}
