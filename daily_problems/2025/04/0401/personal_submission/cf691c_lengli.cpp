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

    if(s.find('.')==-1) s+='.';
    

    while(s.back()=='0') s.pop_back();
    reverse(all(s));
    while(s.back()=='0') s.pop_back();
    reverse(all(s));

    if(s[0]=='.'){
        while(s.back()=='0') s.pop_back();
        int k=1;
        reverse(all(s));
        s.pop_back();
        while(s.back()=='0') s.pop_back(),k++;
        reverse(all(s));
        std::cout<<s[0];
        if(s.size()>1) std::cout<<".";
        for(int i=1;i<s.size();i++) std::cout<<s[i];
        std::cout<<"E-"<<k<<"\n";
    }else if(s.back()=='.'){
        s.pop_back();
        reverse(all(s));
        while(s.back()=='0') s.pop_back();
        reverse(all(s));
        int k=s.size()-1;
        while(s.back()=='0') s.pop_back();
        std::cout<<s[0];
        if(s.size()>1) std::cout<<".";
        for(int i=1;i<s.size();i++) std::cout<<s[i];
        if(k>0) std::cout<<"E"<<k<<"\n";
    }else{
        int k=0;
        for(int i=1;i<s.size();i++){
            if(s[i]=='.'){
                k=i-1;
                break;
            }
        }
        std::cout<<s[0];
        if(s.size()>1) std::cout<<".";
        for(int i=1;i<s.size();i++) if(s[i]!='.') std::cout<<s[i];
        if(k>0) std::cout<<"E"<<k<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
