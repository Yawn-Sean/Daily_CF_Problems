import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

# 计算每两个数字运算后的和
# 更长的部分先打印，然后剩下的a和b交替打印
n = II()
nums = LMII()

ans = 0
cnt = [0] * 11
mod = 998244353

for x in nums:
    cnt[len(str(x))] += 1

for x in nums:
    a, b, power = x, 0, 1
    for i in range(1, 11):
        b = (b + a % 10 * power) % mod
        a //= 10
        ans += (a * 10 * power % mod + b) * cnt[i] * 10 % mod
        ans += (a * 100 * power % mod + b) * cnt[i] % mod
        ans %= mod
        power = power * 100 % mod

print(ans)