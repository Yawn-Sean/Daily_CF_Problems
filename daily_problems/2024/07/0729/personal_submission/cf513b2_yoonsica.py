# https://codeforces.com/contest/513/submission/273294566
n, m = RII()
m -= 1
l, r = 0, n - 1
ans = [0]*n
for i in range(1, n):
    if m >> (n - 1 - i) & 1:
        # 奇数在后半段
        ans[r] = i
        r -= 1
    else:
        ans[l] = i
        l += 1
ans[r] = n
print(' '.join(map(str, ans)))