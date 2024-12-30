
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define SZ(a) ((int)a.size())
using namespace std;
void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}
//////////////////////////////////////////////////
const int N = 2e5 + 10;

void solve(int _) 
{
    int n;
    cin >> n;
    int x, y;
    cin >> x >> y;
    vector<PII> group(n);
    for (int i = 1; i < n; i ++ ) {
        cin >> group[i].first >> group[i].second;
    }

    sort(all(group), [&](PII pa, PII pb) {return pa.first > pb.first;});
    int now = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    while (now < n-1 && x < group[now].first) {
        pq.push(group[now].second - group[now].first + 1);
        now ++;
    }
    
    int ans = SZ(pq) + 1;   
    while (!pq.empty() && x >= pq.top()) {
        x -= pq.top(); pq.pop();
        while (now < n-1 && x < group[now].first) {
            pq.push(group[now].second - group[now].first + 1);
            now ++;
        }
        ans = min(ans, SZ(pq) + 1);
    }

    cout << ans << endl;

} 

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    //cin >> T;
    for (int _ = 1; _ <= T; _ ++ ) {
        solve(_);
    }
    return 0;
}