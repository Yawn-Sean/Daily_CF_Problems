#include<bits/stdc++.h>
using namespace std;
const int N =1e5 + 10;
const int mod=1e9+7;
typedef long long ll;
vector <int> v(N);
void solve(){
	int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>v[i];
    vector<int> tmp=v;
    sort(tmp.begin()+1,tmp.begin()+1+n);
    int ans=0;map<int,int> mp;
    ll pre1=0,pre2=0;
    for(int i=1;i<=n;i++)
    {
        pre1+=v[i];
        pre2+=tmp[i];
        if(pre1==pre2)ans++;
    }
    cout<<ans<<endl;
}
int main(){
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
