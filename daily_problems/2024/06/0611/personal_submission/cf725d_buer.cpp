#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=2*N,mod=1e8+7;
#define int long long
#define uLL unsigned long long
const long long inf=1e18;
typedef pair<int,int> PII;
typedef long long LL;
using node=tuple<int,int,int>;
int n,m,k;
void solve(){
    cin>>n;
    vector<array<int,3>> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1];
        a[i][2]=i;
    }
    sort(a.begin()+2,a.end());
    int i=n;
    int res=inf;
    priority_queue<int,vector<int>,greater<int>> q;
    
    while(1){
        while(i>=2&&a[i][0]>a[1][0])
        {
            q.emplace(a[i][1]-a[i][0]+1);
            i--;
        } 
        res=min(res,(int)q.size()+1);
        if(q.size()&&a[1][0]>=q.top()){
            a[1][0]-=q.top();
            q.pop();
        }else break;
       
    }
    cout<<res;
}
signed main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int t=1;
  ///  cin>>t;
    while(t--) solve();
}
