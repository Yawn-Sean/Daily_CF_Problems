// https://codeforces.com/contest/917/submission/261872354
string s;
void sol()
{
    cin >> s;
    int n = s.size(), res = 0;
    
    for (int i = 0; i < n; i++) {
        // 处理所有左端点为i的子数组
        // p1 =  '(' 的数量 减去 ')' 数量
        // n1 = 变成 ')' 的 '?'的数量
        int p1 = 0, n1 = 0;
        for (int j = i; j < n; j++) {
            if (s[j] == '(') p1++;
            if (s[j] == ')') p1--;
            if (s[j] == '?') {
                // 有多余左括号，先贪心把?变成右括号，与之配对
                if (p1 > 0) p1--, n1++;
                else p1++;  // p1 <= 0，即左括号与右括号数量相等 或者 比右括号少，需要把?变成（
            }
            // 右括号更多 且 之前把？变成了），此时反悔。把之前的？变成左括号
            // 多了一个左括号，少了一个右括号，p1 += 2, n1 -= 1
            if (p1 < 0 && n1 > 0) p1 += 2, n1--; 
            if (p1 < 0 && n1 <= 0) break;
            if (p1 == 0) res++;
        }
        
    }
    cout << res << '\n';
}
