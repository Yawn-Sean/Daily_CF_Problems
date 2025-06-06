/*
 * @Author: BlaCat
 */
#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using i128=__int128_t;
i128 a[40];
i128 er[40];
void solve(){
    i64 n1,k1;
    std::cin>>n1>>k1;
    i128 n=n1;
    i128 k=k1;
    if(n>33){
        std::cout<<"YES"<<" ";
        std::cout<<n1-1<<endl;
        return ;
    }
    k--;
    i128 m=3;
    i128 have=a[n-1];
    for(int i=n-1;i>=0;i--){
        if(have>=k){
            std::cout<<"YES"<<" ";
            std::cout<<i<<endl;
            return ;
        }
        else{
            if(i==0){
                break;
            }
            k-=(m);
            m*=2;
            m++;
            have+=(m-2)*a[i-1];
            if(k<0){
                break;
            }
        }
    }
    std::cout<<"NO"<<endl;
}
signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int t=1;
    std::cin>>t;
    a[0]=0;
    a[1]=1;
    for(int i=2;i<=33;i++){
        a[i]=a[i-1]*4+1;
    }
    while(t--){
        solve();
    }
    return 0;
}
