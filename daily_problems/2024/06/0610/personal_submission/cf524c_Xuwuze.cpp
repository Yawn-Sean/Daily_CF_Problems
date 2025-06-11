#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define SZ(a) ((int)a.size())
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using PLI = pair<ll, int>;
using PLL = pair<ll, ll>;
using PSI = pair<string, int>;
using PSS = pair<string, string>;
using PDD = pair<double, double>;
template <typename T> using max_heap = priority_queue<T>;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<>>;

const int N = 2e5 + 10;
const int mod = 1e9 + 7;

void solution(){
    int n, k;
    cin >> n >> k;

    map<int, int> hashtable;

    for (int i = 0; i < n; i ++) {
        int cash;
        cin >> cash;
        for (int j = 0; j <= k; j ++)
            hashtable[cash * j] = j;
    }

    int q;
    cin >> q;

    while (q --) {
        int x;
        int ans = k + 1;;
        cin >> x;
        for (auto &[k, val]: hashtable) {
            if (hashtable.find(x - k) != hashtable.end()) ans = min(ans, hashtable[x-k] + val);
        }
        if(ans>k) ans = -1;
        cout<<ans<<endl;
    }

    return;
}
signed main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;t = 1;
    while(t--) solution();
    return 0;
}
