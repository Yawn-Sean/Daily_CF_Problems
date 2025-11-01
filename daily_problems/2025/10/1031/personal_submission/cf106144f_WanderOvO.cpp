#include <bits/stdc++.h> 

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;
const LL INFLL = 1e15;

/*
我们需要设状态 dp[c1][c2]，表示这个状态能否先手必胜
其如果能走到某个必败态，则说明其为必胜态
其如果只能走到必胜态，说明这个是必败态
dp[c1][c2] 能转移到那些状态？
dp[c1 - 1][c2], dp[c1][c2 - 1], dp[c1 + 1][c2 - 1]
所以应该把 c2 当成阶段才行，定义 dp[c2][c1]
但是这个题数据范围可能开不下这么大的数组，所以还是得猜结论
做一个 DP，然后和手玩猜出来的结论对拍一下就好了
*/

void solve() {
    int c1 = 0, c2 = 0;
    // cin >> c1 >> c2;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        string t;
        if (s[0] == '.' || s[0] == 'x') {
            t = s.substr(0, 3);
        } else {
            t = s.substr(3);
        }
        
        if (t == "xxx") {
            c2++;
        } else if (t == "xx." || t == ".xx") {
            c1++;
        }
    }
    
    if (c2 % 2 == 0) {
        if (c1 % 2 != 0) {
            cout << "Monocarp\n";
        } else {
            cout << "Polycarp\n";
        }
    } else {
        cout << "Monocarp\n";
    }
}
