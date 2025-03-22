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
using i64=long long;
void slove(){
    i64 n,x1,y1,x2,y2;
    cin>>n>>x1>>y1>>x2>>y2;
    i64 x,y;
    i64 minr=0;
    i64 minl=0;
    vector<pair<i64,i64>> a;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        i64 r1=(x-x1)*(x-x1)+(y-y1)*(y-y1);
        i64 r2=(x-x2)*(x-x2)+(y-y2)*(y-y2);
        a.push_back({r1,r2});
    }
    i64 ans=INT64_MAX;
    for(int i=0;i<n;i++){
        i64 m=0;
        for(int j=0;j<n;j++){
            if(a[i].first<a[j].first){
                m=max(m,a[j].second);
            }
        }
        ans=min(ans,a[i].first+m);
    }
    i64 w=0;
    for(int i=0;i<n;i++){
        w=max(w,a[i].second);
    }
    ans=min(ans,w);
    cout<<ans<<endl;
}
int main() {
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios::sync_with_stdio(false);
    int t=1;
    //cin>>t;
    while(t--){
        slove();
    }
    return 0;
}
