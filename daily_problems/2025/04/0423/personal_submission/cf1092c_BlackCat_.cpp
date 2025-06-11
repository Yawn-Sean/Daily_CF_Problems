#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
void solve(){
    int n;
    std::cin>>n;
    std::vector<std::string> s;
    std::vector<std::string> m;
    std::string s1;
    std::string ans;
    for(int i=0;i<2*n-2;i++){
        std::cin>>s1;
        ans+=('S');
        s.emplace_back(s1);
        if(s1.size()==n-1){
            m.push_back(s1);
        }
    }
    std::string x=m[0]+m[1][n-2];
    int flag=0;
    std::map<int,int> mp;
    for(int i=0;i<2*n-2;i++){
        int x1=s[i].size();
        if(x.substr(0,x1)==s[i]&&mp[x1]!=1){
            ans[i]='P';
            mp[x1]=1;
        }
        else if(x.substr(n-x1,n)==s[i]&&mp[x1]!=2){
            ans[i]='S';
            mp[x1]=2;
        }
        else{
            flag=1;
            break;
        }
    }
    if(flag){
        mp.clear();
        x=m[1]+m[0][n-2];
        for(int i=0;i<2*n-2;i++){
            int x1=s[i].size();
            if(x.substr(0,x1)==s[i]&&mp[x1]!=1){
                ans[i]='P';
                mp[x1]=1;
            }
            else if(x.substr(n-x1,n)==s[i]&&mp[x1]!=2){
                ans[i]='S';
                mp[x1]=2;
            }
            else{
                flag=1;
                break;
            }
        }
    }
    std::cout<<ans<<endl;
}
signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
