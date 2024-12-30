import sys

# sys.setrecursionlimit(int(1e7)) 
# sys.stdin = open('../input.txt', 'r')
input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())

MOD = 10 ** 9 + 7
N = 10 ** 6 + 10

n = II()
a = LMII()
tr = [0] * N

def lowbit(x):
    return x & -x

def add(i, v):
    while i < N:
        tr[i] += v
        i += lowbit(i)

def query(i):
    res = 0
    while i:
        res += tr[i]
        i -= lowbit(i)
    return res

dp = [0] * N
add(1, 1) # tr中的是dp的前缀和，dp只是代表一个值

for x in a:
    # 自己作为一个新序列和减去的重复计算的序列抵消了
    # 所以只剩下中间前缀和的那部分
    pre = (query(x + 1) * x - dp[x]) % MOD
    dp[x] = (dp[x] + pre) % MOD
    add(x + 1, pre) # 只要在原来的基础上更新就行，不需要加dp[x]

print(sum(dp) % MOD)