#include <iostream>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<queue>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;
#define endl '\n'

void slove(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int ans=a/2;
    a=a%2;
    ans+=b/2;
    b=b%2;
    ans+=c/2;
    c=c%2;
    ans+=d/2;
    d=d%2;
    ans+=min(min(a,b),c);
    cout<<ans<<endl;
}
int main() {
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios::sync_with_stdio(false);
    int t=1;
    cin>>t;
    while(t--){
        slove();
    }
    return 0;
}
