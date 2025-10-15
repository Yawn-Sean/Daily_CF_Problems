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
    int n,k,p;
    cin>>n>>k>>p;
    vector<vector<int>>ans(k+1);
    queue<int>a,b;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x%2==0) a.push(x);
        else b.push(x);
    }
    int x=a.size(),y=b.size();
    // cout<<y<<" "<<k-p<<endl;
    // cout<<(y-(k-p))<<" "<<(x+(y-(k-p))/2)<<endl;
    if((y-(k-p)>=0)&&((x+(y-(k-p))/2)>=p)&&((y-(k-p))%2==0)){
        cout<<"YES"<<endl;
        for(int i=1;i<=p;i++){
            if(!a.empty()){
                ans[i].push_back(a.front());
                a.pop();
            }
            else{
                int xx=b.front();
                b.pop();
                ans[i].push_back(xx);
                int yy=b.front();
                b.pop();
                ans[i].push_back(yy);
            }
        }
        for(int i=p+1;i<=k;i++){
            ans[i].push_back(b.front());
            b.pop();
        }
        while(!a.empty()){
            ans[1].push_back(a.front());
            a.pop();
        }
        while(!b.empty()){
            int xx=b.front();
            b.pop();
            ans[1].push_back(xx);
            int yy=b.front();
            b.pop();
            ans[1].push_back(yy);
        }
        for(int i=1;i<=k;i++){
            cout<<ans[i].size()<<' ';
            for(auto x:ans[i]) cout<<x<<' ';
            cout<<endl;
        }
    }
    else cout<<"NO"<<endl;
}
signed main() {
    fastio;
    int T;
 T = 1;
    // cin>>T;
    while (T--) solve();

    return 0;
}
