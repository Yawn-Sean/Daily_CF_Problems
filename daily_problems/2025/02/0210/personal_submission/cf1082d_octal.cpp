#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define debug(x) cerr << #x << ": " << x << '\n';
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
inline void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    int sum = 0;
    for(int i=1; i<=n; i++)
        cin >> a[i], sum += a[i];
    if(sum < (n-1)*2) {
        cout << "NO" << endl;
        return;
    }
    vector<int> q, qq;
    for(int i=1; i<=n; i++) {
        if(a[i] == 1) q.push_back(i);
        else qq.push_back(i);
    }
    int sz = qq.size();

    cout << "YES" << " ";
    if(q.size() == 0) {
        cout << n-1 << endl;
        cout << n-1 << endl;
    } else if(q.size() == 1) {
        cout << n-1 << endl;
        cout << n-1 << endl;
        cout << q[0] << " " << qq[0] << endl;
        a[qq[0]] --;
    } else if(q.size() >= 2) {
        cout << sz+1 << endl;
        cout << n-1 << endl;
        cout << q[0] << " " << qq[0] << endl;
        a[qq[0]] --;
        cout << q.back() << " " << qq.back() << endl;
        a[qq.back()] --;
    }
    for(int i=0; i+1<sz; i++) {
        cout << qq[i] << " " << qq[i+1] << endl;
        a[qq[i]] --;
        a[qq[i+1]] --;
    }
    int j = 0;
    for(int i=1; i<(int)q.size()-1; i++) {
        while(j < sz && !a[qq[j]]) {
            j ++;
        }
        cout << q[i] << " " << qq[j] << endl;
        a[qq[j]] --;
    }
}
