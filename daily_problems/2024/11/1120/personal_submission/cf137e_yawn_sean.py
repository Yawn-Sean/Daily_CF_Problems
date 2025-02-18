# Submission link: https://codeforces.com/contest/137/submission/292402621
def main():
    s = I()
    vowels = set('aeiouAEIOU')

    n = len(s)

    ans, cnt = 0, 0
    d = Counter()
    d[0] = -1
    d[1] = -1

    cur = 0
    for i in range(n):
        v = -1 if s[i] in vowels else 2
        cur += v
        if cur not in d:
            if v < 0:
                d[cur] = i
            else:
                d[cur - 1] = d[cur - 2]
                d[cur] = d[cur - 2]
        
        v = i
        for j in range(3):
            if cur - j in d:
                v = fmin(v, d[cur - j])
        
        v = i - v
        if v == ans:
            cnt += 1
        elif v > ans:
            ans = v
            cnt = 1

    if ans: print(ans, cnt)
    else: print('No solution')