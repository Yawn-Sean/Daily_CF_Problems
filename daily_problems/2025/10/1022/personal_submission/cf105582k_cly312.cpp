#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
    int n;
    cin>>n;
    vector<array<int,2>> a{{0,0}};
    int x=0,y=0;
    for(int i=0;i<n/2-1;i++){
        y+=25;
        a.push_back({x,y});
        x+=25;
        a.push_back({x,y});
    }
    if(n&1){
        x=max(25,x);
        a.push_back({x,0});
        a.push_back({x/25*9,-x/25*12});
    }else a.push_back({x,0});
    int r=5,t=12;
    for(auto [x,y]:a) cout<<x*r+y*t<<' '<<x*(-t)+y*r<<'\n';
}
