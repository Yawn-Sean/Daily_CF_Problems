#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#ifdef __GNUC__
typedef __int128_t lll;
#endif
typedef pair<int,int> pii;
#define mem(a,b) memset(a,b,sizeof(a))
#define x first
#define y second
constexpr ll inf = 1e18;

bool query(int pos, int val) {
    cout << "? " << pos << ' ' << val << endl;
    char c;
    cin >> c;
    return c == '<';
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int cur = 1;
    for (int i = 1; i <= n; i++) {
        while(query(i, cur)) {
            cur++;
        } 
        a[i] = cur;
    }
    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
