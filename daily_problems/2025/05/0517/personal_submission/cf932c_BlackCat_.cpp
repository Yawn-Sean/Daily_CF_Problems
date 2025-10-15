#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
void solve(){
    int n,a,b;
    std::cin>>n>>a>>b;
    for(int i=0;i*a<=n;i++){
        int j;
        if((n-i*a)%b==0){
            j=(n-i*a)/b;
            int st=1;
            for(int k=0;k<i;k++){
                for(int h=1;h<=a;h++){
                    if(h==a){
                        std::cout<<st<<" ";
                    }
                    else
                    std::cout<<st+h<<" ";
                }
                st+=a;
            }
            for(int k=0;k<j;k++){
                for(int h=1;h<=b;h++){
                    if(h==b){
                        std::cout<<st<<" ";
                    }
                    else
                    std::cout<<st+h<<" ";
                }
                st+=b;
            }
            return ;
        }

        else{
            continue;
        }
    }
    std::cout<<-1<<endl;
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
