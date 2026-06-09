import sys

input = lambda: sys.stdin.readline().rstrip()


n = int(input())
a = list(map(int, input().split()))

c0 = a.count(0)
ans = [0] * n
if c0 == 0:
    ans = [(1 << x) if d == 1 else (-(1 << x)) for x, d in enumerate(a)]
else:
    i, j = 0, c0
    for x, d in enumerate(a):
        if d == 0:
            ans[x] = 1 << i
            i += 1
        else:
            ans[x] = (1 << j) if d == 1 else (-(1 << j))
            j += 1

print((1 << n) - (1 << c0))
print(' '.join(map(str, ans)))


"""
考虑 m := (1<<n)-1
对于 1 和 -1, 分别附上每一位 bit 即可
最后一个的 1 或者 -1, 带上 0 对应的 bit
0 用来占位低位的 bit

---

但是这种构造会在 c0 > 0 且 (n-c0) > 1 时出错
比如对于 a=[0, -1, 1], 会输出 m=7, x=[1, -3, 4]
此时有 1 - (-3) == 4, 会构造出 0, 因此失败
究其原因, 是因为有 1, 会跟下一项合并成 2 的次幂, 导致冲突
那怎么处理呢? 把要构造的 m 从 (1<<n)-1 变成去掉低位的值即可
"""
