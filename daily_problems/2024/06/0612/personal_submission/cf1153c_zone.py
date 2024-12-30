"""
贪心: 题目要求最终字符串合法，且前缀子串不合法。能填'('时，就填'('; 否则填')'。
      若存在合法方案，这样做最终一定能得到合法方案，且能最大程度避免前缀子串形成合法方案。
      假设第i个位置填了'('，现在换成')'，则前缀子串s1...si相比于原来的方案更有可能变成合法方案。
"""

def main(ac=FastIO()):
    """
    question:   https://codeforces.com/problemset/problem/1153/C
    submission: https://codeforces.com/contest/1153/submission/265440042
    """
    n = ac.read_int()
    s = list(ac.read_str())
    cnt_a = n // 2 - sum(x == '(' for x in s)
    cnt_b = n // 2 - sum(x == ')' for x in s)
    if n & 1 or cnt_a < 0 or cnt_b < 0: 
        ac.st(':(')
        return 
    ss = 0
    for i, x in enumerate(s):
        if x == '?':
            if cnt_a: 
                cnt_a -= 1 
                s[i] = '('
            elif cnt_b: 
                cnt_b -= 1 
                s[i] = ')'
        ss += 1 if s[i] == ')' else -1
        if ss > 0 or (i != n - 1 and ss == 0):
            ac.st(':(')
            return 
    ac.st(''.join(s))
