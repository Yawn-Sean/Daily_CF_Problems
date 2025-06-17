/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

void solve(){
    std::string s;
    std::cin>>s;
    std::vector<int> a(10),b(10),num(10);
    for(auto x:s) num[x-'0']++;
    std::string s1,s2;
    int mx=0;
    for(int i=1;i<10;i++){
        for(int j=0;j<10;j++){
            a[j]=num[j];
            b[j]=num[j];
        }
        std::string t1,t2;
        int cnt=0,mi=1000000000;
        if(a[i] and b[10-i]){
            cnt++;
            t1+=std::to_string(i);
            t2+=std::to_string(10-i);
            a[i]--;b[10-i]--;
            for(int j=0;j<10;j++){
                mi=std::min(a[j],b[9-j]);
                a[j]-=mi,b[9-j]-=mi;
                cnt+=mi;
                t1=std::string(mi,j+'0')+t1;
                t2=std::string(mi,9-j+'0')+t2;
            }
        }
        mi=std::min(a[0],b[0]);
        a[0]-=mi,b[0]-=mi;
        cnt+=mi;
        t1+=std::string(mi,'0');
        t2+=std::string(mi,'0');
        for(int j=0;j<10;j++){
            t1=std::string(a[j],j+'0')+t1;
            t2=std::string(b[j],j+'0')+t2;
        }
        if(cnt>=mx){
            mx=cnt;
            s1=t1,s2=t2;
        }
    }
    std::cout<<s1<<"\n"<<s2<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
