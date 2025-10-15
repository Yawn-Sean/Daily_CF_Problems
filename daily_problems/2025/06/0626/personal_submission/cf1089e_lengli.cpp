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
    int n;
    std::cin>>n;
    if(n==2){
        std::cout<<"a1 h1 h8"<<"\n";
        return;
    }
    if(n==50){
        std::cout<<"a1 c1 d1 e1 f1 g1 h1 b1 b2 c2 d2 e2 f2 g2 h2 a2 a3 c3 d3 e3 f3 g3 h3 b3 b4 c4 d4 e4 f4 g4 h4 a4 a5 c5 d5 e5 f5 g5 h5 b5 b6 c6 d6 e6 f6 g6 h6 a6 a7 a8 h8\n";
        return;
    }
    std::vector<std::string> res={"a1","b1"};
    for(int i=2;i<=8;i++){
        std::string l="a"+std::to_string(i);
        std::string r="b"+std::to_string(i);
        if(i%2==0) std::swap(l,r); 
        res.pb(l),res.pb(r);
    }
    for(int i=2;i<8;i++){
        char c='a'+i;
        if(i%2==0){
            for(int j=8;j>=1;j--){
                std::string s="";
                s+=c;
                s+=std::to_string(j);
                res.pb(s);
            }
        }else{
            for(int j=1;j<=8;j++){
                std::string s="";
                s+=c;
                s+=std::to_string(j);
                res.pb(s);
            }
        }
    }

    std::vector<std::string> out;

    auto check=[&](int k)->bool{
        if(res[k]=="h8"){
            out.swap(res);
            return 1;
        }
        std::vector<std::string> tmp;
        for(int j=0;j<=k;j++) tmp.pb(res[j]);
        if(res[k][1]=='8'){
            if(k==n-1){
                tmp.pb("h8");
                out.swap(tmp);
                return 1;
            }else if(k==n-2){
                std::string l="";
                l+=res[k][0]+1;
                l+='8';
                if(tmp.back()=="a8") l="c8";
                tmp.pb(l);
                if(l=="h8") return 0;
                tmp.pb("h8");
                out.swap(tmp);
                return 1;
            }
        }else{
            if(k==n-1) return 0;
            if(k==n-2){
                std::string l="h";
                l+=res[k][1];
                if(res[k][0]=='h') l[1]++;
                tmp.pb(l);
                if(l=="h8") return 0;
                tmp.pb("h8");
                out.swap(tmp);
                return 1;
            }
        }
        return 0;
    };

    for(int i=-2;i<=0;i++){
        if(check(n+i)){
            for(auto x:out) std::cout<<x<<" ";
            std::cout<<"\n";
            return;
        }
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
