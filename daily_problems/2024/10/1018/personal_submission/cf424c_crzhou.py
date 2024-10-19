n = II()
nums = LII()

ans = 0

for x in nums:
    ans ^= x

"""
0 1 1 1 1 1
0 0 2 2 2 2
0 1 0 3 3 3
0 0 1 0 4 4
0 1 2 1 0 5
0 0 0 2 1 0
"""

pre = [0] * (n + 1)
for i in range(1, n + 1):
    pre[i] = pre[i - 1] ^ i

for i in range(2, n + 1):
    k, m = divmod(n, i)
    if k % 2:
        ans ^= pre[m] ^ pre[i - 1]
    else:
        ans ^= pre[m]

print(ans)
