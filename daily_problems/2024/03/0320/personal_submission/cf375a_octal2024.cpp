#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define endl '\n'
typedef long long ll;
inline void solve()
{
    string s;
    cin >> s;
    string t, p;
    set<int> st;
    for(auto x: s) {
        if((x == '6' || x == '1' || x == '8' || x == '9') && !st.count(x)) {
            st.insert(x);
        } else if(x == '0') p += x;
        else t += x;
    }
    vector<int> d = {1689, 1698, 1869, 1896, 1986, 1968, 6198, 6189, 6891, 6819, 6918, 6981,
    8169, 8196, 8619, 8691, 8916, 8961, 9168, 9186, 9861, 9816, 9618, 9681};
    int cnt = 0, n = t.size();
    for(int i=0; i<n; i++) {
        cnt = (cnt*10 + t[i]-'0') % 7;
    }
    for(int i=0; i<24; i++) {
        if((cnt*10000 + d[i]) % 7 == 0) {
            cout << t << d[i] << p << endl;
            return;
        }
    }
}
int main()
{
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    while(t --)
        solve();
    return 0;
}
