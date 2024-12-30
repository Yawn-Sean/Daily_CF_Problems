#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=2*N,mod=1e9+7;
 #define int long long
#define uLL unsigned long long
const long long inf=1e18;
typedef pair<int,int> PII;
typedef long long LL;
using node=tuple<int,int,int,int>;
int n,m,k;
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int a[N];
int b[N],c[N];
void solve()
{
    cin>>n;
    int mx=0;
    
    for(int i=1;i<=n;i++) cin>>a[i];
    set<int> st;
    for(int i=1;i<=n;i++){
       if(st.empty()||a[i]>*st.rbegin()) c[i]--;
        if(st.size()&&a[i]<*st.rbegin()){
            auto it=st.upper_bound(a[i]);
            if(*it==*st.rbegin()) b[*it]++;
        }
        st.insert(a[i]);
    }
    int now=-inf,mn=1;
    for(int i=1;i<=n;i++){
        if(b[a[i]]+c[i]>now){
            now=b[a[i]]+c[i];
            mn=a[i];
        }else if(b[a[i]]+c[i]==now) mn=min(mn,a[i]);
    }
    // for(int i=1;i<=n;i++){
    //     cout<<b[a[i]]+c[i]<<"\n";
    // }
    cout<<mn;
}   

signed main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int t=1;
   // cin>>t;
    while(t--) solve();
    return 0;
}
