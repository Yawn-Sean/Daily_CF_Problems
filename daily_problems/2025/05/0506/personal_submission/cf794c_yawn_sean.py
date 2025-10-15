# Submission link: https://codeforces.com/contest/794/submission/318569493
def main():
    s1 = I()
    s2 = I()

    c1 = [0] * 26
    for c in s1:
        c1[ord(c) - ord('a')] += 1

    c2 = [0] * 26
    for c in s2:
        c2[ord(c) - ord('a')] += 1

    v1 = []
    for i in range(26):
        v1.extend(i for _ in range(c1[i]))

    v2 = []
    for i in range(25, -1, -1):
        v2.extend(i for _ in range(c2[i]))

    n = len(s1)
    ans = [0] * n

    l = 0
    r = n - 1

    cnt1 = (n + 1) // 2
    cnt2 = n // 2

    p1 = 0
    p2 = 0

    for idx in range(n):
        if idx % 2 == 0:
            if v1[p1] < v2[p2]:
                ans[l] = v1[p1]
                l += 1
                p1 += 1
            else:
                ans[r] = v1[p1 + cnt1 - 1]
                r -= 1
            cnt1 -= 1
        else:
            if v1[p1] < v2[p2]:
                ans[l] = v2[p2]
                l += 1
                p2 += 1
            else:
                ans[r] = v2[p2 + cnt2 - 1]
                r -= 1
            cnt2 -= 1

    print(''.join(chr(ord('a')  + v) for v in ans))