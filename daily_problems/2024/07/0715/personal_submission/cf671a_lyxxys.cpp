#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 2050, mod = 1e9 + 7, inf = 1e9;
double eps = 1e-9;

void solve(){
    array<double,2> A, B, T;
    int n;
    cin >> A[0] >> A[1] >> B[0] >> B[1] >> T[0] >> T[1];
    cin >> n;
    vector<array<double,2>> dots(n+1);
    auto todis = [&](array<double,2> a, array<double,2> b)->double{
        return hypot(a[0]-b[0], a[1]-b[1]);
    };
    double ans = 0;
    vector<double> Adis(n+1), Bdis(n+1);
    /*
        逆向考虑，先统一算 T 到 每个点的距离，再将 A 和 B 调整进来，至少要调整一个。
    */
    for (int i = 1; i <= n; ++ i){
        cin >> dots[i][0] >> dots[i][1];
        double to1 = todis(A, dots[i]), to2 = todis(B, dots[i]), to = todis(T, dots[i]);
        Adis[i] = to1-to, Bdis[i] = to2-to;
        ans += 2*to;
    }
    auto it1 = min_element(Adis.begin()+1, Adis.end());
    auto it2 = min_element(Bdis.begin()+1, Bdis.end());
    int p1 = it1-Adis.begin(), p2 = it2-Bdis.begin();

    /*
        讨论p1 和 p2, 若p1和p2相等的话，要分别从两两的 最小和次小 相加取最小
    */
    if (p1 != p2){
        ans += min(*it1, *it2);
        if (max(*it1,*it2) < 0) ans += max(*it1, *it2); 
    } else {
        double min1 = 0, min2 = 0;
        for (int i = 1; i <= n; ++ i)
            if (i != p1){
                min1 = min(min1, Adis[i]);
                min2 = min(min2, Bdis[i]);
            }
        ans += min(*it1+min2, *it2+min1);
    }
    cout << ans << "\n";
}


int main(){
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#else
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    cout << fixed << setprecision(12);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
