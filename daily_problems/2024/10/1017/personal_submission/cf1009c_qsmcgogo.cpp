#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n,m,h,i,j,k,x,y;
    int p=6;
    cin>>n>>m;
    int su=0;
    while(m--){
        cin>>x>>y;
        su+=x*n;
        if(y>0)su+=n*(n-1)/2*y;
        else {
            int l=n/2,r=n-l-1;
            su+=l*(l+1)/2*y+r*(r+1)/2*y;
        }
    }
    printf("%.8f",1.0*su/n);
}

