#include<bits/stdc++.h>
using namespace std;
// #define int long long
void solve(){
   string s;cin>>s;
   vector<int>cnt(10);
   for(auto&i:s){
    cnt[i-'0']++;
   } 
   auto cnt2=cnt;
   deque<int>a,b;
   int flag=0;
   for(int i=1;i<10;i++){
    if(cnt[i]&&cnt2[10-i]&&cnt[i]>cnt[9-i]&&cnt2[10-i]>cnt2[9-(10-i)]){
        flag=1;
        cnt[i]--;
        cnt2[10-i]--;
        a.push_back(i);
        b.push_back(10-i);
        break;
    }
   }
   if(flag==0){
    for(int i=1;i<10;i++){
        if(cnt[i]&&cnt2[10-i]){
            cnt[i]--;
            cnt2[10-i]--;
            a.push_back(i);
            b.push_back(10-i);
            flag=1;
            break;
        }
    }
   }
   if(flag){
    for(int i=0;i<10;i++){
        while(cnt[i]&&cnt2[9-i]){
            cnt[i]--;
            cnt2[9-i]--;
            a.push_front(i);
            b.push_front(9-i);
        }
    }
   }
   while(cnt[0]&&cnt2[0]){
    cnt[0]--,cnt2[0]--;
    a.push_back(0),b.push_back(0);
   }
   for(int i=0;i<10;i++)while(cnt[i])cnt[i]--,a.push_front(i);
   for(int i=0;i<10;i++)while(cnt2[i])cnt2[i]--,b.push_front(i);
   while(a.size())cout<<a.front(),a.pop_front();cout<<'\n';
   while(b.size())cout<<b.front(),b.pop_front();
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // int t;cin>>t;while(t--)
    solve();
}