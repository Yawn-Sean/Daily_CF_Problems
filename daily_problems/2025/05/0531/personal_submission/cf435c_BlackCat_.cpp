#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n);
    i64 sum=0;
    int l=0;
    int l1=0;
    int r1=0;

    for(int i=0;i<n;i++){
        std::cin>>a[i];
        sum+=a[i];
        if(i&1){
            l-=a[i];
        }
        else{
            l+=a[i];
        }
        l1=std::min(l1,l);
        r1=std::max(r1,l);
    }
    std::string s;
    for(int i=0;i<sum;i++){
        s.push_back(' ');
    }
    std::vector<std::string> ans(r1-l1+1,s);
    int st=0;
    int st2=r1-1;
    int x=0;
    for(int i=0;i<n;i++){
        if(i&1){
            for(int j=0;j<a[i];j++){
                
                ans[st2][st]='\\';
                if(j!=a[i]-1){
                    st2++;
                }
                st++;
            }
        }
        else{
            for(int j=0;j<a[i];j++){
                // std::cerr<<st2<<endl;
                std::cerr<<st<<endl;
                ans[st2][st]='/';
                if(j!=a[i]-1){
                    st2--;
                }
                st++;
            }
        }
    }
    for(auto x:ans){
        for(auto y:x){
            std::cout<<y;
        }
        std::cout<<endl;
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
