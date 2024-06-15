import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

# 偶数操作不会改变0-1的频率，所以只有当1的个数相同时可以用偶数次
# 奇数操作相当于多操作一次，我们要枚举最小的位置
ans = []
for _ in range(II()):
    n = II()
    s, t = I(), I()
    c1, c2 = s.count('1'), t.count('1')
    res = n + 10
    if c1 == c2:
        res = sum(s[i] != t[i] for i in range(n))

    if n - c1 + 1 == c2:
        # 看看是否可以找到一个最小操作位置
        cnt = 0
        f = False
        for i in range(n):
            if s[i] == t[i]:
                cnt += 1
                if t[i] == '1':
                    f = True
        res = min(res, cnt + 2 - 2 * f) # 这个+2是因为这个枚举的位置还需要再画两次变成0，而如果目标就是1的话就可以省掉这个2
    ans.append(res if res < n + 10 else -1)
print(*ans, sep='\n')