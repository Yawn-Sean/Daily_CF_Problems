#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
using u64 =long long;
using d64= double;
using ld64= long double;
#define endl '\n'

void solve()
{
    i64 x1,y1,x2,y2;
    std::cin>>x1>>y1>>x2>>y2;
    i64 e1=0,e2=0,s1=0,s2=0;
    auto get2=[&](i64 v)->i64{
        i64 ans=0;
        while(v%2==0){
            v/=2;
            ans++;
        }
        return ans;
    };
    auto get3=[&](i64 v)->i64{
        i64 ans=0;
        while(v%3==0){
            v/=3;
            ans++;
        }
        return ans;
    };
    e1=get2(x1)+get2(y1);
    s1=get3(x1)+get3(y1);
    e1+=s1;
    e2=get2(x2)+get2(y2);
    
    s2=get3(x2)+get3(y2);
    e2+=s2;
    int ans=abs(e1-e2)+abs(s2-s1);
    for(int i=s1;i<s2;i++){
        if(x2%3==0){
            x2/=3;
            x2*=2;
        }
        else if(y2%3==0){
            y2/=3;
            y2*=2;
        }
        s1++;
    }
    for(int i=s2;i<s1;i++){
        if(x1%3==0){
            x1/=3;
            x1*=2;
        }
        else if(y1%3==0){
            y1/=3;
            y1*=2;
        }
        s2++;
    }
    for(int i=e1;i<e2;i++){
        if(x2%2==0){
            x2/=2;
        }
        else if(y2%2==0){
            y2/=2;
        }
        e1++;
    }
    for(int i=e2;i<e1;i++){
        if(x1%2==0){
            x1/=2;
        }
        else if(y1%2==0){
            y1/=2;
        }
        e2++;
    }
    
    if(x1*y1==x2*y2){
    std::cout<<ans<<endl;
    std::cout<<x1<<" "<<y1<<endl;
    std::cout<<x2<<" "<<y2<<endl;
    }
    else{
        std::cout<<-1<<endl;
    }
}
signed main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    solve();
    return 0;
}
