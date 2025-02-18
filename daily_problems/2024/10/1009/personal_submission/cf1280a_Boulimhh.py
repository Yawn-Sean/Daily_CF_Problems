"""
思路：题有点长，实际上是模拟
"""
#python代码：
mod = 10 ** 9 + 7
for i in range(int(input())):
    x = int(input())
    s = list(map(int,input()))
    l = 1
    ans = len(s)
    while l <= x:
        ans = ((ans - l) * s[l - 1] + l) % mod
        r = len(s)
        for j in range(s[l - 1] - 1):
            if len(s) < x:
                s += s[l:r]
            else:
                break
        l += 1
    print(ans)
