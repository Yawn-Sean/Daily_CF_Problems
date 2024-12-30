#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
#define int long long
typedef pair<int,int>PII;
#define x first
#define y second

void solve(){
    int n;cin>>n;
    std::vector<PII> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i].x>>v[i].y;
    }
    int t=v[1].x,w=v[1].y;
    sort(v.begin()+2,v.end());
    
    int ans=1e18;
    priority_queue<int,vector<int>,greater<int>>q;
    int i=n;
    while(1){
        for(;i>=2&&v[i].x>t;i--){
            q.push(v[i].y-v[i].x+1);//需要花费这么多
        }
        //cerr<<t<<" "<<q.size()<<"\n";
        ans=min(ans,(int)q.size()+1);
        if(q.size()&&t>=q.top()){
            t-=q.top();
            q.pop();
        }
        else{
            cout<<ans<<"\n";return;
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
