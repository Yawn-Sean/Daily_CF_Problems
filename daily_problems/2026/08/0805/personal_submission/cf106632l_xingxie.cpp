#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
using i128 = __int128_t;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvll = vector<vector<long long>>;
using vvvt = vector<vector<vector<int>>>;
using vvvll = vector<vector<vector<long long>>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<double,double>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vpdd = vector<pair<double,double>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
using tri = tuple<int,int,int>;
using trl = tuple<ll,ll,ll>;
using vtri = vector<tuple<int,int,int>>;
using vtrl = vector<tuple<ll,ll,ll>>;
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n,m,k;
    cin >> n >> m >> k;
    vvt a(n,vt(2));
    vt rr(n);
    for (int i = 0;i < n;i++) cin >> a[i][0] >> a[i][1];
    for (int i = 0;i < k;i++) 
    {
        int x;
        cin >> x;
        x--;
        rr[x] = 1;
    }
    map<int,int> pos;
    set<int> st1,st0;
    vt p(2 * n);
    int l = n - 1,r = n;
    int f = 0;
    for (int i = 0;i < n;i++)
    {
        int id = a[i][0],state = a[i][1];
        if (pos.count(id))
        {
            if (!f) 
            {
                p[pos[id]] = -1;
                p[r] = id;
                if (st1.find(pos[id]) != st1.end()) st1.erase(pos[id]);
                if (st0.find(pos[id]) != st0.end()) st0.erase(pos[id]);
                if (state) st1.insert(r);
                else st0.insert(r);
                pos[id] = r++;
            }
            else 
            {
                p[pos[id]] = -1;
                p[l] = id;
                if (st1.find(pos[id]) != st1.end()) st1.erase(pos[id]);
                if (st0.find(pos[id]) != st0.end()) st0.erase(pos[id]);
                if (state) st1.insert(l);
                else st0.insert(l);
                pos[id] = l--;
            }
        }
        else if (pos.size() < m) 
        {
            if (!f) 
            {
                p[r] = id;
                if (state) st1.insert(r);
                else st0.insert(r);
                pos[id] = r++;
            }
            else 
            {
                p[l] = id;
                if (state) st1.insert(l);
                else st0.insert(l);
                pos[id] = l--;
            }
        }
        else if (!st0.empty())
        {
            if (!f) 
            {
                int j = *st0.begin();
                st0.erase(st0.begin());
                int idj = p[j];
                p[j] = -1;
                pos.erase(idj);
                if (state) st1.insert(r);
                else st0.insert(r);
                p[r] = id;
                pos[id] = r++;
            }
            else 
            {
                int j = *(--st0.end());
                st0.erase(--st0.end());
                int idj = p[j];
                p[j] = -1;
                pos.erase(idj);
                if (state) st1.insert(l);
                else st0.insert(l);
                p[l] = id;
                pos[id] = l--;
            }
        }
        else if (state == 1)
        {
            if (!f) 
            {
                int j = *st1.begin();
                st1.erase(st1.begin());
                int idj = p[j];
                p[j] = -1;
                pos.erase(idj);
                if (state) st1.insert(r);
                else st0.insert(r);
                p[r] = id;
                pos[id] = r++;
            }
            else 
            {
                int j = *(--st1.end());
                st1.erase(--st1.end());
                int idj = p[j];
                p[j] = -1;
                pos.erase(idj);
                if (state) st1.insert(l);
                else st0.insert(l);
                p[l] = id;
                pos[id] = l--;
            }
        }
        else {}
        f ^= rr[i];
    }
    int cnt = 0;
    if (f) ranges::reverse(p);
    for (int x : p) 
    {
        if (x != -1 && x != 0) 
        {
            cnt++;
            // if (cnt == m) break;
        }
    }
    cout << cnt << endl;
    for (int x : p) 
    {
        if (x != -1 && x != 0) 
        {
            cout << x << " ";
            // cnt--;
            // if (!cnt) break;
        }
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);
    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}