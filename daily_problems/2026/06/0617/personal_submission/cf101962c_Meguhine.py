import sys

input = lambda: sys.stdin.readline().rstrip()
MOD = 10**9 + 7


def solve() -> str:
    n = int(input())
    ans = pow(2, n, MOD) * (n - 3) + n + 3
    return str(ans % MOD)


print('\n'.join(solve() for _ in range(int(input()))))


"""
显然 max 和 min 可以拆开
s_max(i) := i * 2**(i-1)
s_min(i) := i * 2**(n-i)
然后就是数列求和了, 经典高中题目
s_max:
 S = 1*2**0 + 2*2**1 + 3*2**2 + 4*2**3 + ... + n*2**(n-1)
2S =          1*2**1 + 2*2**2 + 3*2**3 + ... + (n-1)*2**(n-1) + n*2**n
 S = - (2**0 + 2**1 + 2**2 + ... + 2**(n-1)) + n*2**n
   = n*2**n - 2**n + 1 = (n-1)*2**n + 1
s_min:
 S = n*2**0 + (n-1)*2**1 + (n-2)*2**2 + ... + 1*2**(n-1)
2S =              n*2**1 + (n-1)*2**2 + ... + 2*2**(n-1) + 1*2**n
 S = -n + (2**1 + 2**2 + ... + 2**(n-1) + 2**n)
   = 2**(n+1) - (n+2)
ans:
 S = (n-1)*2**n + 1 - 2**(n+1) + (n+2)
   = (n-3)*2**n + (n+3)
"""
