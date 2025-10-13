#include<bits/stdc++.h>
using namespace std;
const long long M=1000000007;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<long long> S(n+1);
    S[0]=1;
    int x=0;
    long long y=0;
    for(int i=0;i<n;i++){
        if(a[i]>a[x]) x=i;
        y=S[x];
        S[i+1]=(S[i]+y)%M;
    }
    cout<<y%M<<'\n';
}
