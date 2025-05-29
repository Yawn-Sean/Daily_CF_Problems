#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::string> a(n); 
    std::vector<std::string> b(n);
    for(int i=0;i<n;i++){
        std::cin>>a[i];
        for(int j=0;j<m;j++){
            b[i].push_back('.');
        }
    }
    std::vector<std::array<int,4>> ans;
    for(char x='a';x<='z';x++){
        int x0=-1,y0=-1,x1=-1,y1=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]==x){
                    if(x0==-1){
                        x0=i;
                        y0=j;
                        x1=i;
                        y1=j;
                    }
                    else{
                        x1=i;
                        y1=j;
                    }
                }
            }
        }
        if(x0!=x1&&y1!=y0){
            std::cout<<"NO"<<endl;
            return ;
        }
        if(x0==-1){
            continue;
        }
        while(ans.size()<=x-'a'){
            ans.push_back({x0+1,y0+1,x1+1,y1+1});
        }
    }
    for(int i=0;i<ans.size();i++){
        char s='a'+i;
        auto [x0,y0,x1,y1]=ans[i];
        for(int x=x0-1;x<x1;x++){
            for(int y=y0-1;y<y1;y++){
                b[x][y]=s;
            }
        }
    }
    if(b==a){
        std::cout<<"YES"<<endl;
        std::cout<<ans.size()<<endl;
        for(auto [x0,y0,x1,y1]:ans){
            std::cout<<x0<<' '<<y0<<" "<<x1<<" "<<y1<<endl;
        }
    }
    else{
        std::cout<<"NO"<<endl;
    }
}
signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t=1;
    std::cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
