// #pragma GCC optimize("O2,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define i64 long long
#define db long double
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define ull unsigned long long
#define vi vector<int>
using ll = long long;
using i128 = __int128;
//#define endl '\n'
#define vpii vector<pii>
#define vvpii vector<vector<pii>>
#define vvi vector<vector<int>>
#define pqpii priority_queue<pii, vector<pii>, greater<pii>>
#define pqi priority_queue<int,vector<int>, greater<int>>
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define INF 1e18
#define exp 1e-12
void slove(){
    int n;
    cin>>n;
    int cnt2=0,cnt4=0;
    map<int,int>cnt;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x%4==0) cnt4++;
        else if(x%2==0) cnt2++;
        else cnt[x]++;
    }
    int ans=0;
    for(auto [x,y]:cnt){
       if(cnt.count(x+2)) ans+=y*cnt2*cnt[x+2]*2;
        if(cnt.count(x+4))ans+=y*cnt4*cnt[x+4]*2;
    }
    ans+=cnt2*(cnt2-1)*cnt4;
    ans+=cnt[1]*cnt[3]*cnt4*2;
    ans+=cnt[1]*(cnt[1]-1)*cnt2;
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while (t--) slove();
    return 0;
}
