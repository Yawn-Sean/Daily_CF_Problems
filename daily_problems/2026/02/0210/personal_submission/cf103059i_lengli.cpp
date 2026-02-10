/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

#define int long long

i64 qmi(int a,int b,int m){
    i64 res=1;
    while(b){
        if(b&1) res*=a,res%=m;
        a*=a;
        a%=m;
        b/=2;
    }
    return res;
}

void solve(){
    int n;
    std::cin>>n;
    if(n==1) std::cout<<1<<"\n";
    else if(n==4) std::cout<<"1 3 2 4"<<"\n";
    else{
        bool flag=1;
        for(int i=2;i<n;i++){
            if(n%i==0){
                flag=0;
                break;
            }
        }
        if(flag){
            std::cout<<1<<" ";
            for(int i=2;i<n;i++){
                std::cout<<qmi(i-1,n-2,n)*i%n<<" ";
            }
            std::cout<<n<<"\n";
        }else std::cout<<"-1"<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
