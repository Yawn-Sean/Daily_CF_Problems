# 26 * 99 + 1 = 2575，大于等于这个数则一定有100个以上相同的字符串
from collections import Counter
s = input()
n = len(s)
cnt = Counter(s)

c, v = cnt.most_common()[0]
if v >= 100:
    print(c * 100)
    exit()

f = [[0] * (n + 1) for _ in range(n + 1)] # f[l][r]表示从s[l-r]中最长回文子序列的长度

for i in range(n):
    f[i][i] = 1

for i in range(2, n + 1): # 回文序列的长度
    for l in range(n - i + 1):
        r = l + i - 1
        f[l][r] = max(f[l + 1][r], f[l][r - 1])
        if s[l] == s[r]:
            f[l][r] = max(f[l][r], f[l + 1][r - 1] + 2)
            

# 构造回文串
ans = []
l, r = 0, n - 1
while l < r:
    if s[l] == s[r]:
        ans.append(s[l])
        l += 1
        r -= 1
    else:
        if f[l][r] == f[l + 1][r]:
            l += 1
        else:
            r -= 1

ans = ''.join(ans)
if len(ans) >= 50: # 大于的话只能取50，然后构成100
    ans = ans[:50]
    print(ans + ans[::-1])
else:
    mid = s[l] if l == r else ''
    print(ans + mid + ans[::-1])