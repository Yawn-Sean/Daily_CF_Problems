// #pragma GCC optimize("O2,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define int long long
using i64 = long long;
#define double long double
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define ull unsigned long long
#define f first
#define s second
#define pqi priority_queue<int,vector<int>,greater<int>>
#define pqpii priority_queue<pii,vector<pii>,greater<pii>>
//#define endl '\n'
#define vi vector<int>
#define vii vector<vector<int>>
#define vc vector
#define vpii vector<pair<int, int>>
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define INF 1e18
#define exp 1e-12
string a[3]={"OXO","XOOOO","XOXO"};
int s(const string &s) {
    set<string> st;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        string t = "";
        for (int j = i; j < n; j++) {
            t += s[j];
            st.insert(t);
        }
    }
    return st.size();
}
map<int,vpii> m;
void slove(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<a[i%3]<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            m[s(a[i]+a[j])].pb({i,j});
        }
    }
    // for(auto &[x,y]:m){
    //     cout<<x<<":";
    //     for(auto &[a,b]:y){
    //         cout<<"("<<a<<","<<b<<")";
    //     }
    //     cout<<endl;
    // }
    int q;
    cin>>q;
    while(q--){
        int x;
        cin>>x;
        cout<<m[x][0].f+1<<" "<<m[x][0].s+1<<endl;
    }
}
signed main(){
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
    int t = 1;
    //cin>>t;
    while (t--){
        slove();
    }
    return 0;
}
