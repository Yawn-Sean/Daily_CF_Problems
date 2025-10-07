#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        long long a,b;
        cin>>a>>b;
        if((b|a)!=a){
            cout<<-1<<'\n';
            continue;
        }
        if(!a){
            cout<<1<<'\n'<<0<<'\n';
            continue;
        }
        int c=__builtin_popcountll(a);
        if(c==1){
            if(b==a)cout<<2<<'\n'<<0<<' '<<a<<'\n';
            else cout<<-1<<'\n';
            continue;
        }
        vector<int>v;
        if(!b){
            for(int x=0;x<=a;++x) if((x|a)==a)v.push_back(x);
        }else{
            for(int x=0;x<=a;++x) if((x|a)==a&&x!=b)v.push_back(x);
        }
        cout<<v.size()<<'\n';
        for(int i:v) cout<<i<<' ';
        cout<<'\n';
    }
}
