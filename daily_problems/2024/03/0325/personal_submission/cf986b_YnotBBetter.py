import sys
input = lambda: sys.stdin.readline().strip()

# 随机选择两个元素交换位置，Petr 交换 3n 次，Alex 交换 7n + 1 次
# 显然这两种交换次数的奇偶性不同，如果能证明给定排列无法同时交换奇数次和偶数次得到，就可以通过恢复排列来区分交换方法
#   （羊）考虑排列中逆序对数量，即 i < j 且 xi > xj，初始数量为 0
#   给定某个排列 x1 x2 ... xi ... xj ... xn，假设 xi 到 xj 之间共有 k 个元素x满足 xi < x < xj
#   我们交换 xi 和 xj，以 xj 为左元素的逆序对增加 k + 1 个，以中间 k 个元素为左元素的逆序对各增加 1 个，总计 2k + 1 个
#   因此，单次交换行为会让排列中的逆序对数量增加或减少一个奇数
#   如果交换奇数次，最终排列中的逆序对数量为奇数；如果交换偶数次，最终排列中的逆序对数量为偶数；
#   因此，给定排列不可能同时通过交换奇数次和偶数次得到
# 我们从前往后逐个将元素恢复到原本的位置，而后可以通过任意交换两个元素再恢复的方式增加交换次数且不改变排列和交换次数的奇偶性

n = int(input())
nums = list(map(lambda x: int(x) - 1, input().split()))

seen = [-1] * n
for i, v in enumerate(nums):
    seen[v] = i

cnt = 0
for i in range(n):
    if nums[i] == i:
        continue
    cnt += 1
    idx = seen[i]
    nums[idx] = nums[i]
    seen[nums[idx]] = idx

print("Petr" if cnt & 1 == n & 1 else "Um_nik")
