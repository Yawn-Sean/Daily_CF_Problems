#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
void solve(){
    int n;
    std::cin>>n;
    int num[400];
    for(int i=0;i<400;i++){
        num[i]=0;
    }
    int last=0;
    int x;
    int len=0;
    auto sz=[&](int d,int len){
        int i;
        for(i=0;d>0;i++){
            while(num[i]==9){
                i++;
            }
            if(num[i]+d>9){
                d=d+num[i]-9;
                num[i]=9;
            }
            else{
                
                num[i]+=d;
                d=0;
            }
        }
        return std::max(len,i);
    };
    while(n--){
        std::cin>>x;
        int d=x-last;
        if(d>0){
            len=sz(d,len);
        }
        else{
            int j=0;
            while(num[j]==9||d<=0){
                d+=num[j];
                num[j]=0;;
                j++;
            }
            num[j]++;
            d--;
            j++;
            len=std::max(len,j);
            len=sz(d,len);
        }
        last=x;
        for(int i=len-1;i>=0;i--){
            std::cout<<num[i];
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
