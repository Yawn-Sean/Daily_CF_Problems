#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    const vector<int>p={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
    const int P=p.size(),F=(1<<P)-1;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int&x:a)cin>>x;
        vector<char>v(1<<P);
        for(int x:a){
            int m=0;
            for(int i=0;i<P;i++)if(x%p[i]==0)m|=1<<i;
            v[m]=1;
        }
        vector<int>c(1<<P);
        for(int i=0;i<1<<P;i++)c[i]=v[i];
        for(int i=0;i<P;i++)
            for(int j=0;j<1<<P;j++)
                if(j>>i&1)c[j]+=c[j^1<<i];
        unsigned long long r=ULLONG_MAX;
        for(int s=1;s<1<<P;s++){
            int m=(~s)&F;
            if(c[m])continue;
            unsigned long long pr=1;
            for(int i=0;i<P;i++)if(s>>i&1)pr*=p[i];
            r=min(r,pr);
        }
        cout<<r<<'\n';
    }
}
