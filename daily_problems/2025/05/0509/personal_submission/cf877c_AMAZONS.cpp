#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
typedef long long ll;
void solve(){
	int n;cin>>n;int ans=0;
    cout<<n+n/2<<endl;
    for(int i=2;i<=n;i+=2)
    {
        cout<<i<<" ";
    }
    for(int i=1;i<=n;i+=2)
    cout<<i<<" ";
    for(int i=2;i<=n;i+=2)
    {
        cout<<i<<" ";
    }
}
int main(){
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
