#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3fll
#define endl "\n"
const int N = 2e5 + 10,mod=1e9+7;
int f[N],inv[N];
void solve()
{
    int n;
    cin>>n;
    int op,a,b,t;int l=0,r=INF;
    while (n--)
    {
        cin>>op>>a>>b;
        if(op==1){
            cin>>t;
            int ll=0,rr;
            if(t>=1)ll=(t-1)*(a-b);
            if(t>=2)ll=max(ll,(t-2)*(a-b)+a);
            ll++;
            rr=(t-1)*(a-b)+a;
            int ml=max(l,ll),mr=min(r,rr);
            if(ml>mr){
                cout<<0<<" ";
            }else{
                l=ml,r=mr;
                cout<<1<<" ";
            }
        }else if(op==2){
            int ll=1,rr=1;
            if(r-l<=a){
                ll+=((l-b-1)/(a-b)<0?0:(l-b-1)/(a-b));
                rr+=((r-b-1)/(a-b)<0?0:(r-b-1)/(a-b));
                if(ll==rr)cout<<ll<<" ";
                else cout<<-1<<" ";
            }else{
                cout<<-1<<" ";
            }
        }
    }
    cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;while(t--)
    solve();
}