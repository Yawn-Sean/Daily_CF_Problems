#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=2*N,mod=1e9+7;
#define int long long
#define uLL unsigned long long
const long long inf=1e18;
typedef pair<int,int> PII;
typedef long long LL;
using node=tuple<int,int,int>;
int n,m,k;
int a[N];
void solve()
{
    cin>>k;
    m=0;
    set<int> st;
    for(int i=1;i<=k;i++) cin>>a[i];
    for(int i=2;i<=k;i++)
    {
        if(a[i]!=a[i-1]+1&&a[i]!=a[i-1]-1)
        {
            m=max(m,abs(a[i]-a[i-1]));
            st.insert(abs(a[i]-a[i-1]));
        }
        if(a[i]==a[i-1]){
            cout<<"NO\n";return ;
        }
    }
   
    if(st.count(0)){
        cout<<"NO\n";return ;
    }
    if(st.size()>1){
        cout<<"NO\n";return ;
    }
    if(st.size()==0){
        cout<<"YES\n";
        cout<<1000000000<<" "<<1<<"\n";return ;
    }
    int x=a[1];
    if(m==0){
        cout<<"YES\n";
        cout<<1<<" "<<1000000000<<"\n";return ;
    }
    for(int i=2;i<=k;i++)
    {
        if(a[i]==x)
        {
            cout<<"NO\n";return ;
        }
        set<int> st;
        vector<int> b;
        if(x-1>=1&&((x-1)%m+m)%m!=0)
        st.insert(x-1);
        if(x-m>=1)
        st.insert(x-m);
        st.insert(x+m);
        if(x%m!=0) st.insert(x+1);
        if(!st.count(a[i])){
            cout<<"NO\n";return ;
        }
        x=a[i];
    }
    cout<<"YES\n";

    cout<<1000000000<<" "<<m<<"\n";
}

signed main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int t=1;
    //init();
   // cin>>t;
    while(t--) solve();
    return 0;
}
