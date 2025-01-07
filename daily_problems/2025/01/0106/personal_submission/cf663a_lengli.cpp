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
    std::getline(std::cin,s);

    std::vector<char> q={'+'};

    int up=0,down=0;

    int target=0,res=1;

    for(int i=0;i<s.size();i++){
        char c=s[i];
        if(c==' ' or c=='?' or c=='=') continue;
        if(std::isdigit(c)){
            target*=10;
            target+=c-'0';
            continue;
        }
        if(c=='+') up++,res++;
        else if(c=='-') down++,res--;
        q.pb(c);
    }

    if(q.size()==1){
        std::cout<<"Possible"<<"\n";
        std::cout<<target<<" = "<<target<<"\n";
        return;
    }

    std::vector<int> num;

    for(int i=0;i<q.size();i++){
        if(q[i]=='+'){ 
            int st=1;
            while(res<target and st<target) st++,res++;
            while(res>target and st>1) st--,res--;
            num.pb(st);
        }else{
            int st=1;
            while(res>target and st<target) st++,res--;
            while(res<target and st>1) st--,res--;
            num.pb(st);
        }
    }

    if(target!=res){
        std::cout<<"Impossible"<<"\n";
        return;
    }

    std::cout<<"Possible"<<"\n";
    std::cout<<num[0]<<" ";
    for(int i=1;i<q.size();i++){
        std::cout<<q[i]<<" "<<num[i]<<" ";
    }
    std::cout<<"= "<<target<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
