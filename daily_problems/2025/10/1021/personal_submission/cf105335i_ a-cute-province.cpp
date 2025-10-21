#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  998244353;
const int N = 1e6 + 10;
int fenwick[N]; 
void add(int x){//单点修改
    for(; x < N; x += x&-x){
        fenwick[x]++;
    }
}
void del(int x){
    for(; x < N; x += x&-x){
        fenwick[x]--;
    }
}
int query(int l, int r){//区间查询
    if(r < l)return 0;
    int suml = 0, sumr = 0;
    for(; r!=0; r -= r&-r){
        sumr += fenwick[r];
    }
    l--;
     for(; l!=0; l -= l&-l){
        suml += fenwick[l];
    }
    return sumr - suml;
}

void solve()
{
    long long n;
    cin >> n;
    vector<int> k(n+1);
    for(int i = 1; i <=n; i ++)add(i);
    for(int i = 1; i <=n; i ++){
        int x;
        cin >> x;
        k[i] = query(1, x)-1;
        del(x);
    }
    long long p = (k[2] + n * (n-1)/2);
    k[1] += p / (n - 1);
    k[1] %= n;
    k[2] = p % (n - 1);
    for(int i = 1; i <=n; i ++)add(i);
    for(int i = 1; i <= n; i++){
     
        int l = 1, r = n;
        while(l < r){
            int mid = (l + r)/2;
            if(query(1, mid) < k[i]+1)l = mid + 1;
            else r = mid;
        }
       cout << l << ' ';
        del(l);
    }

}

int cute_prov0nce()
{
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
