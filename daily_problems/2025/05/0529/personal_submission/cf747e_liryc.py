'''
https://codeforces.com/problemset/submission/747/321939831
'''
# parser, tree
def solve(s: str) -> list[list[str]]:
    a = list(s.split(','))
    ans = []
    token_stk = []
    count_stk = []
    for i in range(0, len(a), 2):
        t, n = a[i], int(a[i + 1])
        while count_stk and count_stk[-1] == 0:
            count_stk.pop()
            token_stk.pop()
        if count_stk:
            count_stk[-1] -= 1
        token_stk.append(t)
        count_stk.append(n)
        if len(token_stk) > len(ans):
            ans.append([])
        ans[len(token_stk) - 1].append(t)
    return ans
