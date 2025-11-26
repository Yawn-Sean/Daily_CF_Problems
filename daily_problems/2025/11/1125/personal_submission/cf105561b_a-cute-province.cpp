#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e6 + 10;
int p[N], v1[N], v2[N];
vector<int> pri;
bool not_prime[N];
void pre(int n) {
	n--;
  for (int i = 2; i <= n; ++i) {
    if (!not_prime[i]) {
      pri.push_back(i);
    }
    for (int pri_j : pri) {
      if (i * pri_j > n) break;
      not_prime[i * pri_j] = true;
      if (i % pri_j == 0) {

        break;
      }
    }
  }
}
int qpow(int a, int b, int mod){
    int res = 1;
    while(b){
        if(b &1) res = res * a %mod;
        b >>= 1;
        a = a * a %mod;
    }
    return res;
}
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a;
    int cnt = 0;
    for(int i = 1; i <= n;i ++){
        int x;
        cin >> x;
        v2[x] = 1;
        if(x == 1)cnt++;
        a.emplace_back(x);
    }
    sort(a.begin(), a.end());
    for(int i = 1; i <N; i ++){
        for(int j = i; j < N; j += i){
            if(v2[j]){
                v1[i] = 1;
                break;
            }
        }
    }
    if(cnt == n-1){
        while(q--){
            int x;
            cin >> x;
            if(a[n-1]%x == 0)cout << "Yes\n";
            else cout << "No\n";
        }
    }
    else if(n == 2){
        while(q--){
            int x;
            cin >> x;
            int vv1 = qpow(a[0], a[1], x), vv2 = qpow(a[1], a[0], x);
            if(vv1 == 0 || vv2 == 0)cout << "Yes\n";
            else cout << "No\n";
        }
    }
    else if(n == 3){
        auto work =[&](int x, int y, int z, int mod)->bool{
            int i = x, j = y, k = z;
            i = qpow(i, j, mod);
            if(j == 1)j = 1;
            else{
                int sum = 1;
                while(k){
                    sum*=j;
                    k--;
                    if(sum >= 20)break;
                }
                j = sum;
            }
            if(qpow(i, j, mod) == 0)return true;
            int c = y;
            y = qpow(y, z, mod);
            if(x == 1)x = 1;
            else{
                int sum = 1;
                while(c){
                    sum*=x;
                    c--;
                    if(sum >= 20)break;
                }
                x = sum;
            }
            if(qpow(y, x, mod) == 0)return true;
            return false;
        };
        while(q--){
            int m;
            cin >> m;
            if(work(a[0], a[1], a[2], m))cout << "Yes\n";
            else if(work(a[0], a[2], a[1], m))cout << "Yes\n";
            else if(work(a[1], a[0], a[2], m))cout << "Yes\n";
            else if(work(a[1], a[2], a[0], m))cout << "Yes\n";
            else if(work(a[2], a[1], a[0], m))cout << "Yes\n";
            else if(work(a[2], a[0], a[1], m))cout << "Yes\n";
            else cout << "No\n";
        }

    }
    else{
        while(q--){
            int m;
            cin >> m;
            set<int> st;
            while(m > 1){
                st.insert(p[m]);
                m /= p[m];
            }
            int val = 1;
            for(auto u : st)val *= u;
            if(v1[val])cout << "Yes\n";
            else cout << "No\n";
        }
    }
}
signed cute_prov0nce()
{
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    pre(N);
    for(int i = 1; i < N ;i ++){
        if(not_prime[i])continue;
        for(int j = i; j < N; j +=i)p[j] = i;
    }
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
