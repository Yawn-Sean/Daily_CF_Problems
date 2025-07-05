# Submission link: https://codeforces.com/contest/313/submission/327458973
def main():
    n, m = MII()
    nums1 = LII()
    nums2 = LII()

    c1 = [0] * m
    c2 = [0] * m

    for x in nums1: c1[x] += 1
    for x in nums2: c2[x] += 1

    ans = []
    stk = []

    for i in range(m):
        stk.extend(i for _ in range(c1[i]))
        
        while c2[m - i - 1] and stk:
            c2[m - i - 1] -= 1
            ans.append(stk.pop() + m - i - 1)

    for i in range(m - 1, -1, -1):
        while c2[i]:
            c2[i] -= 1
            ans.append(stk.pop() + i - m)

    ans.sort(reverse=True)

    print(' '.join(map(str, ans)))