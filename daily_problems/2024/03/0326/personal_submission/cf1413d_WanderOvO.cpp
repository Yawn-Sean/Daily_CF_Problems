#include <bits/stdc++.h>
    
#define x first
#define y second
#define ls (k << 1)
#define rs (k << 1 | 1)
#define mp make_pair
#define pb push_back
    
using namespace std; 

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, char> PIC;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
typedef pair<LL, LL> PLL;
typedef pair<PII, PII> PIIII;

const int N = 200010;
const int M = 35;
const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;
const int MOD3 = 240011539;
const int P = 13331;
const LL INF = 2e9;
const double eps = 1e-8;

/*
每个 - val 相当于查找当前的前缀最小值是否为 val，如果不可能则非法，如果可能则删掉 val
如果不 + 而连续询问 - val，则 val 必须单调递增
val 自始至终不能出现重复的

最开始想的是，遇到 + 就插入当前没插入的最大的数，比如第一次插入 n，第二次插入 n - 1...
如果遇到 - val 了，再反悔，但是这样太复杂了

第一次遇到 - val 时，直接把 val 填到前面最近的一个没确定插入什么值的 + 处
这样最可能保证每次拿到的都是最小值
我们这样把所有的数都填进去之后，只需要再模拟一遍 + 和 - 的步骤，看是否对的上即可

看其他题解，发现也可以倒着想
*/

int T;
int n;
stack<int> st;
string op[N];
int val[N];

void solve1() {
    cin >> n;
    int m = 2 * n;
    for (int i = 1; i <= m; i++) {
        cin >> op[i];
        if (op[i] == "-") {
            cin >> val[i];
        }
    }
    vector<int> res;
    for (int i = m; i > 0; i--) {
        if (op[i] == "-") {
            if (!st.empty() && st.top() < val[i]) {
                cout << "NO\n";
                return;
            }
            st.push(val[i]);
        } else {
            if (!st.empty()) {
                res.pb(st.top());
                st.pop();
            } else {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
    for (int i = n - 1; i >= 0; i--) {
        cout << res[i] << " ";
    }
}

void solve2() {
    cin >> n;
    int m = 2 * n;
    for (int i = 1; i <= m; i++) {
        cin >> op[i];
        if (op[i] == "-") {
            cin >> val[i];
        }
    }
    
    vector<int> res(m + 1, -1);
    for (int i = 1; i <= m; i++) {
        if (op[i] == "+") {
            st.push(i);
        } else {
            // 供不应求
            if (st.empty()) {
                cout << "NO\n";
                return;
            }
            res[st.top()] = val[i];
            st.pop();
        }
    }
    
    // 模拟一遍，看是否符合要求
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= m; i++) {
        if (op[i] == "+") {
            q.push(res[i]);
        } else {
            int tp = q.top();
            q.pop();
            if (tp != val[i]) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= m; i++) {
        if (res[i] != -1) {
            cout << res[i] << " ";
        }
    }
}
    
void prepare() {
    
}

void init() {

}
    
void solve() {
    // solve1();
    solve2();
}
    
int main() {
    #ifdef LOCAL_TEST
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    T = 1;
    // cin >> T;
    prepare();
    while (T--) {
        init();
        solve();
    }
    
    return 0;
}