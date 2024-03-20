import sys

input = lambda: sys.stdin.readline().rstrip()
# sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())
LGMI = lambda: list(GMI())
YN = lambda x: print('YES' if x else 'NO')
mod = 1000000007
mod2 = 998244353

nums = [1, 6, 8, 9]
goods = [[9, 6, 8, 1], [6, 8, 9, 1], [8, 1, 9, 6], [9, 8, 1, 6], [9, 8, 6, 1], [8, 9, 6, 1], [8, 6, 9, 1], [9, 6, 8, 1],
         [6, 8, 9, 1], [8, 1, 9, 6]]

digits = [int(x) for x in input()]
cnt = [0] * 10
for x in digits:
    cnt[x] += 1

for x in nums:
    cnt[x] -= 1

ret = []
pre = 0
for i in range(1, 10):
    while cnt[i]:
        pre = (pre * 10 + i) % 7
        ret.append(i)
        cnt[i] -= 1
ret.extend(goods[pre])
ret.extend([0] * cnt[0])
print(''.join(str(x) for x in ret))

# for perm in itertools.permutations(nums):
#     # print(perm)
#     v = 0
#     for x in perm:
#         v *= 10
#         v += x
#     print(v)
#     for i in range(10):
#         vt = i * 10 ** 4 + v
#         if vt % 7 == 0:
#             print(vt)
#             rets[i] = perm
# print(rets)
