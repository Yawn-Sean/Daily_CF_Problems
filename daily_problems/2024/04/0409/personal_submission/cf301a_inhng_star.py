import sys
input = sys.stdin.readline
mod = 10 ** 9 + 7 # 998244353

'''
如果 n 为奇数，那么可以通过 3 次操作将一个数乘以 -1
如果 n 为偶数，那么可以通过 2 次操作将一个数乘以 -1
'''

n = int(input())
a = list(map(int, input().split()))
ans = sum(abs(ai) for ai in a)
print(ans if n & 1 or sum(ai < 0 for ai in a) & 1 == 0 else ans - 2 * abs(min(a, key = abs)))
