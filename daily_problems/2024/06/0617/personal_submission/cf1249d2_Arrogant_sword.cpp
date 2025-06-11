
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
    int n, k;
    cin >> n >> k;
    // l, r, id.
    vector<array<int, 3>> segs(n+1);
    vector<int> a(N);
    for (int i = 1; i <= n; i ++ ) {
        cin >> segs[i][0] >> segs[i][1];
        segs[i][2] = i;
        a[segs[i][0]] ++; a[segs[i][1] + 1] --;
    }
    sort(segs.begin() + 1, segs.end());
    
    auto cmp = [&](array<int, 3> ta, array<int,3> tb) {return ta[1] < tb[1];};
    priority_queue<array<int, 3>, vector<array<int, 3>>, decltype(cmp)> pq(cmp);
    vector<int> ans;
    int j = 1;
    for (int i = 1; i < N; i ++ ) {
        while (j <= n && segs[j][0] <= i) {
            pq.emplace(segs[j]);
            j ++;
        }
        a[i] += a[i-1];
        while (a[i] > k) {
            auto t = pq.top(); pq.pop();
            a[i] --; a[t[1] + 1] ++;
            ans.push_back(t[2]);
        }
    }

    cout << SZ(ans) << endl;
    print(ans);

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