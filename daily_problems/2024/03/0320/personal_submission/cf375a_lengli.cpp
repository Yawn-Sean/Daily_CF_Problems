/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pb push_back

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=100010;

void solve(){
    string s;
    cin>>s;
    vector<int> cnt(10,0);
    for(auto x:s) cnt[x-'0']++;
    string str="";
    for(int i=9;i>=0;i--){
        if(i==9) for(int j=1;j<cnt[i];j++) str+='9';
        else if(i==8) for(int j=1;j<cnt[i];j++) str+='8';
        else if(i==6) for(int j=1;j<cnt[i];j++) str+='6';
        else if(i==1) for(int j=1;j<cnt[i];j++) str+='1';
        else for(int j=1;j<=cnt[i];j++) str+=i+'0';
    }
    if(cnt[0]==s.size()-4) {
        cout<<"1869"<<str;
        return;
    }
    int m=0;
    for(int i=(int)str.size()-1,j=10000;i>=0;i--){
        int t=str[i]-'0';
        m+=(t*j)%7;
        m%=7;
        j*=10,j%=7;
    }
    if(m==0) str+="1869";
    else if(m==1) str+="1896";
    else if(m==2) str+="1986";
    else if(m==3) str+="1698";
    else if(m==4) str+="6198";
    else if(m==5) str+="1689";
    else if(m==6) str+="1968";
    cout<<str;
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
