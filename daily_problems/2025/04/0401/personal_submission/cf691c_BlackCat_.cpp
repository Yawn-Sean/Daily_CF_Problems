#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
void solve(){
    std::string s;
    std::cin>>s;
    int n=s.size();
    int l;
    for(int i=0;i<n;i++){
        if(s[i]!='0'){
            l=i;
            break;
        }
    }
    int w=n-1;
    for(int i=0;i<n;i++){
        if(s[i]=='.'){
            w=i;
            break;
        }
    }
    int r=n-1;
    for(int i=n-1;i>w;i--){
        if(s[i]!='0'){
            r=i;
            break;
        }
    }
    std::string ans;
    int b=0;
    int flag=1;
    int need=-1;
    int flag1=1;
    for(int i=l;i<=r;i++){
        
        if(s[i]!='.'){
            b+=flag;
            if(s[i]!='0'){
                flag1=0;
                if(flag==-1){
                    flag=0;
                }
            }
            
            if(!flag1){
                ans.push_back(s[i]);
                
                if(need==-1){
                    ans.push_back('.');
                    need=0;
                }
            }
        }
        else{
            if(b==0)
                flag=-1;
            else{
                flag=0;
            }
        }
    }
    if(b>0){
        b--;
    }
    if(ans.empty()){
        std::cout<<0<<endl;
        return ;
    }
    int wei=ans.size();
    for(int i=ans.size()-1;i>=0;i--){
        if(ans[i]!='0'){
            wei=i;
            break;
        }
    }
    if(ans[wei]=='.')
    ans.erase(ans.begin()+wei,ans.end());
    else{
        ans.erase(ans.begin()+wei+1,ans.end());
    }
    std::cout<<ans;
    if(b!=0){
        std::cout<<"E"<<b<<endl;
    }
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
