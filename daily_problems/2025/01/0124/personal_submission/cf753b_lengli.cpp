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
    auto query=[&](std::string s)->std::array<int,2>{
        std::cout<<s<<std::endl;
        int a,b;
        std::cin>>a>>b;
        return {a,b};
    };

    auto print=[&](std::string s){
        std::cout<<s<<std::endl;
        return;
    };

    std::string s="0000";
    auto t=query(s);

    for(int i=t[0];i<4;i++){
        while(s[i]<'9'){
            s[i]++;
            t=query(s);
            if(t[0]+t[1]==i+1){
                break;
            }
        }
    }

    if(t[0]==4){
        print(s);
        return;
    }

    int idx=0;

    for(int i=1;i<4 and t[0]==0;i++){
        std::swap(s[0],s[i]);
        t=query(s);
    }

    char tc='0';
    while(s.find(tc)!=-1) tc++;
    
    for(int i=0;i<4;i++){
        std::string l=s;
        for(int j=0;j<4;j++){
            if(i==j) continue;
            l[j]=tc;
        }
        t=query(l);
        if(t[0]==1){
            idx=i;
            break;
        }
    }
    

    std::string a="";
    for(int i=0;i<4;i++){
        if(i!=idx) a+=s[i];
    }
    sort(all(a));

    do{
        std::string b="";
        for(int i=0,j=0;i<4;i++){
            if(i==idx) b+=s[i];
            else b+=a[j++];
        }
        t=query(b);
        if(t[0]==4){
            print(b);
            return;
        }
    }while(std::next_permutation(all(a)));
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
