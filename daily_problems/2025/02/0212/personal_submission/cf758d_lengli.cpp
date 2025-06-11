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

void solve(){
    i64 n;
    std::string s;
    std::cin>>n>>s;
    int len=s.size();
    i64 res=0;
    i64 b=1,k=0;
    i64 x=n;
    while(x){
        x/=10;
        k++;
    }
    for(int i=len-1;i>=0;){
        i64 num=0,ten=1;
        int j,nk=0;
        for(j=i;j>=0;j--){
            if(nk>k or num+ten*(s[j]-'0')>=n) break;
            else num=num+ten*(s[j]-'0');
            nk++;
            ten*=10;
        }
        while(j+1<i and j+1<len and s[j+1]=='0') j++;
        i=j;
        res+=b*num;
        b*=n;
    }
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
