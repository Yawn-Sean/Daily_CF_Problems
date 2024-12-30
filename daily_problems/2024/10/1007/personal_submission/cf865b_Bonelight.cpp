/*
    Bonelight * V *
    20241007: 放假的懒惰之日 
    No Coding, No Bug 
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define endl '\n'
#define pii pair<int, int>
#define INF (int)2e14
void solve()
{
    int n,k; cin >> n >> k;
    vector<pii> sa(n),sb(n);
    int cnta = 0, cntb = 0, ans = 0;
    while(n --){
        int s,a,b; cin >> s >> a >> b;
        if(a >= b){
            ans += a * s;
            sa.emplace_back(a - b, s);
            cnta += s;
        } else {
            ans += b * s;
            sb.emplace_back(b - a, s);
            cntb += s;
        }
    }

    if((cnta + k - 1) / k + (cntb + k - 1) / k <= (cnta + cntb + k - 1) / k){
        cout << ans << endl;
    } else {
        sort(begin(sa), end(sa));
        sort(begin(sb), end(sb));
        int atob = ans;
        int lva = cnta % k; 
        for(auto &[d,num]:sa){
            int ch = min(num, lva);
            lva -= ch;
            atob -= d * ch;
        }

        int btoa = ans;
        int lvb = cntb % k; 
        for(auto &[d,num]:sb){
            int ch = min(num, lvb);
            lvb -= ch;
            btoa -= d * ch;
        }

        cout << max(atob, btoa);
    }
}   

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while(T --){
        solve();
    }
}
