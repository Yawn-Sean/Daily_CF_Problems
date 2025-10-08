#include<bits/stdc++.h>
using namespace std;
const int M=1e7;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<bool> f(M+1,1);
    f[0]=f[1]=0;
    for(int i=2;i*i<=M;i++) if(f[i]) for(int j=i*i;j<=M;j+=i) f[j]=0;
    vector<int> p(M+1);
    for(int i=1;i<=M;i++) p[i]=p[i-1]+f[i];
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int X=p[n]-p[n/2];
        cout<<(X==n-1?X-1:X)<<'\n';
    }
}
