#include<bits/stdc++.h>
using namespace std;
const int M=1e7;
vector<int>f(M+1);
void build(){
    for(int i=1;i<=M;i++) f[i]=i;
    for(int i=2;1ll*i*i<=M;i++){
        if(f[i]==i){
            for(int j=i*i;j<=M;j+=i) if(f[j]==j) f[j]=i;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    build();
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int g=a[0];
    for(int i=1;i<n;i++){
        g=gcd(g,a[i]);
    }
    vector<int> b(n);
    for(int i=0;i<n;i++) b[i]=a[i]/g;
    vector<bool> v(M+1);
    for(int x:b){
        if(x==1) continue;
        int t=x;
        while(t>1){
            int p=f[t];
            if(v[p]){
                cout<<"NO\n";
                return 0;
            }
            v[p]=1;
            while(t%p==0) t/=p;
        }
    }
    cout<<"YES\n";
}
