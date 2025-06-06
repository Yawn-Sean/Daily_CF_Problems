#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define int long long
#define all(v) v.begin(), v.end()
//#define x first
//#define y second

using namespace std;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int>a(n+1);
    vector<vector<int>>p(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        p[a[i]].push_back(i);
    }
    if(p[0].size()>=2||p[0].size()==0){
        cout<<-1<<endl;
        return;
    }

    bool st=0;
    queue<int>q;
    q.push(p[0][0]);
    vector<PII>ans;
    for(int i=1;i<n;i++){
        if(!p[i].size()){
            st=1;
        }
        else{
            if(st||(i>=2&&k==1)){
                cout<<-1<<endl;
                return;
            }
        }
        queue<int>qq;
        int t=0;
        for(auto v:p[i]){
            if(q.empty()){
                cout<<-1<<endl;
                return;
            }
            qq.push(v);
            t++;
            ans.push_back({q.front(),v});
            if(i==1&&t==k) q.pop(),t=0;
            else if(i!=1&&t==k-1) q.pop(),t=0;
        }
        q=qq;
    }
    cout<<ans.size()<<endl;
    for(auto [x,y]:ans) cout<<x<<' '<<y<<endl;
}
signed main() {
    fastio;
    int T;
 T = 1;
    // cin>>T;
    while (T--) solve();

    return 0;
}
