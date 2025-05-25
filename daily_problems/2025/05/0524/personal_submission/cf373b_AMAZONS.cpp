#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
#define int long long
int w,m,k,cur=0,gap=0,l,r,mid;
void solve(){
	cin>>w>>m>>k;
    w/=k;
    cur=to_string(m).size();
    gap=pow(10,cur)-m;
    int maxi=gap*cur,ans=0;
    while(maxi<=w){
        w-=maxi;
        ans+=gap;
        cur++;
        gap=pow(10,cur)-pow(10,cur-1);
        maxi=gap*cur;
    }
    if(w){
        ans+=w/cur;

    }
    cout<<ans<<endl;
}
signed main(){
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
