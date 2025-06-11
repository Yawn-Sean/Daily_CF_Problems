#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
using u64 =long long;
using d64= double;
using ld64= long double;
#define endl '\n'

void solve(){
    int a,b,c;
    i64 k;
    std::cin>>a>>b>>c>>k;
    i64 now=0;
    int lowa=pow(10,a-1);
    int higha=pow(10,a)-1;
    int lowb=pow(10,b-1);
    int highb=pow(10,b)-1;
    int lowc=pow(10,c-1);
    int highc=pow(10,c)-1;
    for(int i=lowa;i<=higha;i++){
        i64 l=std::max(lowb,lowc-i);
        i64 r=std::min(highb,highc-i);
        if(l>r){
            continue;
        }
        else if((r-l+1)+now>=k){
            for(int j=l;j<=r;j++){
                now++;
                if(now==k){
                    std::cout<<i<<" + "<<j<<" = "<<i+j<<endl;
                    return ;
                }
            }
        }
        else{
            now+=(r-l+1);
        }
    }
    std:cout<<-1<<endl;



}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    std::cin>>t;
    while(t--){
        solve();
    }
}
