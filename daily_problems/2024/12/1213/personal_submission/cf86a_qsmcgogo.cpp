#include<bits/stdc++.h>
using namespace std;
#define int long long

int f(int x){
    string s=to_string(x);
    for(auto &i:s){
        i='9'-i+'0';
    }
    return stoll(s);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _=1;
    int res=0;
    while(_--){
        int l,r,i;
        cin>>l>>r;
        for(i=5000000000;i;i/=10){
            if(r>=i*2)return cout<<r*f(r),0;
            if(i>=l&&i<=r)return cout<<i*f(i),0;
            if(i<l){
                return cout<<l*f(l),0;
            }
        }
        cout<<r*f(r);
    }
}
