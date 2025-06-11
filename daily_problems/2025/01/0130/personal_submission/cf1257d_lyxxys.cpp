#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using f64 = long double;
using u64 = unsigned long long;
const f64 eps = 1e-12;
const i64 inf_i64 = 4e18;
const int inf_int = 2e9;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}
template <class T> void print(vector <T> &A){
    int n = A.size();
    for (int i = 0; i < n; ++ i){
        if (i) cout << " ";
        cout << A[i];
    }
    cout << "\n";
}
int jgs(f64 x){
    return x < -eps ? -1 : x > eps;
}

void solve(){
    int ma_monster = -inf_int, ma_hero = -inf_int;

    int n;
    cin >> n;
    vector <int> A(n);
    for (auto &x : A){
        cin >> x;
        fmax(ma_monster, x);
    }

    int m;
    cin >> m;
    vector <array<int,2>> heros(m), chose;
    for (auto &it : heros){
        cin >> it[0] >> it[1];
        fmax(ma_hero, it[0]);
    }

    if (ma_monster > ma_hero){
        cout << -1 << "\n";
        return;
    }

    sort(heros.begin(), heros.end(), [&](auto &u, auto &v){
        return u[0] == v[0] ? u[1] < v[1] : u[0] < v[0];
    });

    for (int i = m-1, ma = 0; i >= 0; -- i){
        if (i < m-1 && heros[i][0] == heros[i+1][0]) continue;
        if (ma > heros[i][1]) continue;
        chose.push_back(heros[i]);
        ma = heros[i][1];
    }
    reverse(chose.begin(), chose.end());
    int L = chose.size();
    // power 从小到大，endurance 从大到小
    auto find = [&](int x)->int{  // 找到 power 大于 x 的最小的下标
        int lo = 0, hi = L-1;
        while (lo < hi){
            int mid = (lo+hi) >> 1;
            if (chose[mid][0] >= x) hi = mid;
            else lo = mid+1;
        }
        return lo;
    };
    int res = 0;
    {
        int i = 0, j = -1, k, ma;
        while (i < n){
            res += 1, ma = -inf_int;
            while (j+1 < n){
                if (A[j+1] > ma) k = find(A[j+1]), ma = A[j+1];
                if (j-i+2 > chose[k][1]) break;  // 大于 满足条件的最大 的 endurance，无法增长
                j += 1;
            }
            i = j+1;
        }
    }

    cout << res << "\n";
}

int main(){
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
#else
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    int _ = 1;
    cin >> _;
    while (_--) solve();
    return 0;
}
