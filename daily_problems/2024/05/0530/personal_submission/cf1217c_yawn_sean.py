# Submission link: https://codeforces.com/contest/1217/submission/263193856
def main():
    s = I()
    n = len(s)
    pref_zero = [0]
    for c in s:
        if c == '0': pref_zero.append(pref_zero[-1] + 1)
        else: pref_zero.append(0)
    ans = 0
    for i in range(n):
        cur = 0
        for j in range(i, max(0, i - 18) - 1, -1):
            if s[j] == '1':
                cur |= 1 << i - j
                if pref_zero[j] + i - j + 1 >= cur:
                    ans += 1
    return ans
