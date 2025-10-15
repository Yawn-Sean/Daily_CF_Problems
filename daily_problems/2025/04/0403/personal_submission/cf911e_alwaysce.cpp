#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> perm(k);
    for (int i = 0; i < k; i++) {
        cin >> perm[i];
    }

    /*
        (5,1,3)
        (5,3,4)
        - 遇到一个更大的数字的时候一定要离开栈了

        先对于前k项进行尝试
        栈里面的状态=[a1,a2,...,ak]
     */

    vector<int> stk = {n + 1};
    int cur = 1;
    for (int i = 0; i < k; i++) {
        stk.push_back(perm[i]);
        while (!stk.empty() && stk.back() == cur) {
            stk.pop_back();
            cur++;
        }
    }
    stk.push_back(cur - 1);

    // 现在栈里面的元素={a1,a2,...,ak}
    // 栈顶=a1 能往里面放哪些元素? (<a1的部分)
    // [cur, a1-1]
    // cur->a1+1
    
    for (int i = (int)stk.size() - 1; i >= 1; i--) {
        if (stk[i] > stk[i - 1]) {
            cout << -1;
            return 0;
        }

        for (int j = stk[i - 1] - 1; j > stk[i]; j--) {
            perm.push_back(j);
        }
    }

    for (auto&x: perm) {
        cout << x << " ";
    }
    return 0;
}
