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
    std::vector<int> la(26,-1);
    int n=s.size();

    char c='*';
    int len=-1,idx=-1;

    for(int i=0;i<n;i++){
        int p=s[i]-'A';
        if(la[p]==-1) la[p]=i;
        else{
            c=s[i];
            len=i-la[p]-1;
            idx=la[p];
            la[p]=i;
            break;
        }
    }
    if(!len){
        std::cout<<"Impossible"<<"\n";
        return;
    }
    std::vector<std::vector<char>> res(2,std::vector<char>(13));
    int st=len/2;
    for(int i=st;i>=0;i--){
        res[0][i]=s[idx];
        idx++;
    }
    for(int i=0;idx<la[c-'A'];i++){
        res[1][i]=s[idx];
        idx++;
    }

    int k=0,fx=1;
    idx++;

    while(idx<n){
        st+=fx;
        if(st==13){
            fx=-1,k=1;
            st=12;
        }
        res[k][st]=s[idx];
        idx++;
    }

    for(int i=0;s[i]!=c;i++){
        st+=fx;
        if(st==13){
            fx=-1,k=1;
            st=12;
        }
        res[k][st]=s[i];
    }

    for(auto x:res){
        for(auto y:x) std::cout<<y;
        std::cout<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
