#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _=1;
    while(_--){
        int k,n,x,y,i,j,m,d;
        string s;
        cin>>n>>s;
        if(s.size()%n!=0){
            int len=0;
            while(len<=s.size()){
                cout<<1;
                for(i=1;i<n;i++)cout<<0;
                len+=n;
            }
        }
        else{
            string t=s;
            for(i=0;i<s.size();i++)t[i]=s[i%n];
            if(t>s){cout<<t<<'\n';continue;}
            t[n-1]++;
            for(i=n-2;i>=0;i--){
                if(t[i+1]>'9')t[i+1]-=10,t[i]++;
            }
            if(t[0]<='9'){
                for(i=0;i<s.size();i++)t[i]=t[i%n];
                cout<<t<<'\n';
            }
            else{
                int len=0;
                while(len<=s.size()){
                    cout<<1;
                    for(i=1;i<n;i++)cout<<0;
                    len+=n;
                }
            }
        }
    }
}
