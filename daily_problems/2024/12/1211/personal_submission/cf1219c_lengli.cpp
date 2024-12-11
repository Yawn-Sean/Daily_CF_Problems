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
    int L;
    std::string s;
    std::cin>>L>>s;
    if(s.size()<L){
        std::string res="1";
        res+=std::string(L-1,'0');
        std::cout<<res<<"\n";
        return;
    }else if(s.size()==L){
        int idx=-1;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!='9'){
                idx=i;
                break;
            }
        }
        if(idx==-1){
            std::string res="1";
            res+=std::string(L-1,'0');
            std::cout<<res+res<<"\n";
            return;
        }
        s[idx]++;
        for(int i=idx+1;i<s.size();i++) s[i]='0';
        std::cout<<s<<"\n";
    }else if(s.size()%L){
        int len=s.size()/L+1;
        std::string res="",str="1";
        str+=std::string(L-1,'0');
        while(len--) res+=str;
        std::cout<<res<<"\n";
    }else{
        std::string res="",str=s.substr(0,L);
        int len=s.size()/L;
        for(int i=0;i<len;i++) res+=str;
        if(res>s){
            std::cout<<res<<"\n";
            return;
        }
        if(str==std::string(L,'9')){
            str="1";
            str+=std::string(L-1,'0');
            res="";
            for(int i=0;i<=len;i++) res+=str;
            std::cout<<res<<"\n";
            return;
        }
        int idx=-1;
        for(int i=L-1;i>=0;i--){
            if(s[i]!='9'){
                idx=i;
                break;
            }
        }
        s[idx]++;
        for(int i=idx+1;i<L;i++) s[i]='0';
        res="";
        str=s.substr(0,L);
        for(int i=0;i<len;i++) res+=str;
        std::cout<<res<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
