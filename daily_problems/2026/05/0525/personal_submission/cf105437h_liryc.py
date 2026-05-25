'''
https://codeforces.com/gym/105437/submission/375987051
1400
prefix + suffix
'''
def solve(n: int, s: str) -> int:
    sc, ss = [1] * n, [0] * (n + 1)
    ss[-2] = 1
    for i in range(n - 2, -1, -1):
        if s[i] == s[i + 1]:
            sc[i] = sc[i + 1] + 1
        ss[i] = sc[i] * sc[i] + ss[i + sc[i]]
    ans, pc, ps = 0, 0, 0
    for i in range(n - 1):
        a, b = s[i], s[i + 1]
        if a != b:
            x, y = 1, 1
            if i:
                if b == s[i - 1]:
                    x = ps + (pc + 1) ** 2
                else:
                    x = ps + pc * pc + 1
            if i + 1 < n - 1:
                if a == s[i + 2]:
                    y = ss[i + 2] - sc[i + 2] ** 2 + (sc[i + 2] + 1) ** 2
                else:
                    y = ss[i + 2] + 1
            ans = pmax(ans, x + y)
        if i and a == s[i - 1]:
            pc += 1
        else:
            ps += pc * pc
            pc = 1

    return ans
