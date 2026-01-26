#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

const int N = 1010;
const int M = 5e4 + 10; 
const int mod = 998244353;
const int P = 13331;

/*
对于奇数个的，我们需要从奇数轮开始打，才能打完
对于偶数个的，我们需要从偶数论开始打，才能打完
每打完一个奇数个的，我们的轮数奇偶性就会发生变化，打完偶数个的，轮数不变
羊神的贪心策略：
- 如果当前是奇数轮，优先打剩一个的，没有的话就随便打一个
- 如果当前是偶数轮，除了剩一个的不能打，打其他任何一个都是一样的
*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    vector<int> one;
    vector<int> more;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        if (a[i] > 1) {
            more.push_back(i);
        } else if (a[i] == 1) {
            one.push_back(i);
        }
    }

    vector<int> res;
    int killed = 0;
    for (int rd = 1; ; rd++) {
        if (rd % 2 == 0) {
            if (more.size()) {
                int id = more.back();
                a[id]--;
                killed++;
                res.push_back(id);
                if (a[id] == 1) {
                    more.pop_back();
                    one.push_back(id);
                }
            } else {
                break;
            }
        } else {
            if (one.size()) {
                int id = one.back();
                a[id]--;
                res.push_back(id);
                one.pop_back();
                killed++;
            } else if (more.size()) {
                int id = more.back();
                a[id]--;
                killed++;
                res.push_back(id);
                if (a[id] == 1) {
                    more.pop_back();
                    one.push_back(id);
                }
            } else {
                break;
            }
        }
    }

    if (res.size() == sum) {
        cout << "YES\n";
        for (auto id : res) {
            cout << id << " ";
        }
        cout << "\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    #ifdef LOCAL_TEST
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}
