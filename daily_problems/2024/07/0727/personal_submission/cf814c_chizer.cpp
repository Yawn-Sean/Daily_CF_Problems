#include<bits/stdc++.h>
#define rep(i, j ,k) for(int i = (j); i <= (k); ++i)
#define dep(i, j, k) for(int i = (j); i >= (k); --i)
using i64 = int64_t;
using f64 = double_t;
#define pb push_back
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define mod 1000000007
#define inf 0x3f3f3f3f
#define maxn 100005
using namespace std;

int t;
int n, q;
string s;

// 在线 O(nq)
//void solve() {
//    cin >> n >> s >> q;
//    rep(i, 1, q) {
//        int m;
//        char c;
//        cin >> m >> c;
//        int l, r;
//        l = 0, r = 0;
//        int num = 0;    //字符c在窗口中的个数
//        int mc = 0;    //历史字符c在窗口中的最大个数
//        while (r < n) {
//            if(s[r] == c) num++;
//            mc = max(mc, num);
//            if(r - l + 1 - mc > m) {
//                if(s[l] == c) num--;
//                l++;
//            }
//            r++;
//        }
//        cout << r - l << '\n';
//    }
//}

// 离线 O(26*n^2 + q)
void solve() {
    cin >> n >> s >> q;
    int cnt[26][n + 1];
    rep(i, 0, 25) {
        rep(j, 0, n) {
            int num = 0;
            int mc = 0;
            int l = 0, r = 0;
            while (r < n) {
                if(s[r] == 'a' + i) num++;
                mc = max(mc, num);
                if(r - l + 1 - mc > j) {
                    if(s[l] == 'a' + i) num--;
                    l++;
                }
                r++;
            }
            cnt[i][j] = r - l;
        }
    }
    rep(i, 1, q) {
        int m;
        char c;
        cin >> m >> c;
        cout << cnt[c - 'a'][m] << '\n';
    }
}

int main () {
    ios:: sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    t = 1;
//    cin >> t;
    while(t--) solve();
}