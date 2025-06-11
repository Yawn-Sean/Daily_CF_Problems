/*
给一个数列，强制一些数必须是负数，其他位置可能是负数
容易发现幸运数列长度必须是偶数
无论如何，第一个数都必须是正数
使用递归下降法验证数列合法性？
羊神提示：类比括号序列，但是这里有很多种不同的括号
多种不同括号的匹配还是得用栈去模拟，不能简单维护括号个数
可以从右向左去匹配，这样可以避免右括号不够用时不知道转变哪个左括号
*/

int p[N], q[N], n, m;

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int pos;
        cin >> pos;
        q[pos] = 1;
    }
    if (n % 2 != 0) {
        cout << "NO\n";
        return;
    }
    stack<int> stk;
    for (int i = n; i > 0; i--) {
        if (q[i]) {
            stk.push(i);
        } else {
            if (!stk.empty()) {
                if (p[stk.top()] == p[i]) {
                    q[stk.top()] = 1;
                    stk.pop();
                } else {
                    stk.push(i);
                }
            } else {
                stk.push(i);
            }
        }
    }
    if (!stk.empty()) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        cout << (q[i] == 1 ? -p[i] : p[i]) << " ";
    }
}
