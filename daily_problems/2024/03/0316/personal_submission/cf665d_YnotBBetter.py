import sys
input = lambda: sys.stdin.readline().strip()

# 除了2，所有的质数都是奇数
# 如果两个正数和为2，则必定为两个1相加，如果集合里都是1，则满足两两和为质数
#   若存在非1的奇数，则与1相加后会得到偶数，为非质数，必定不满足条件；
#   若存在偶数，则可能符合（如2），也可能不符合（如8），可根据结果来判断；
#       假设得到了符合的偶数（如2），此时其他偶数也不再可用，因为必定与已选择的偶数结合得到新的偶数，所以可用的偶数最多只有一个；
# 如果两个正数和为奇数，则必定是一个奇数和一个偶数
#   假设存在3个数 a b c 且最多只有一个1（如果有更多1就是第一种情况），已知 a + b 和 a + c 均为非2的质数（即奇数），则：
#       b 和 c 的奇偶性相同，和必为偶数，且由于最多只有一个1，和必定大于2，为非质数，不满足条件；

is_prime = [True] * (2 * 10 ** 6 + 1)
for v in range(2, 2 * 10 ** 6 + 1):
    if not is_prime[v]:
        continue
    tmp = v * 2
    while tmp < 2 * 10 ** 6 + 1:
        is_prime[tmp] = False
        tmp += v

n = int(input())
nums = list(map(int, input().split()))
ans = [nums[0]]

one_cnt = nums.count(1)
if one_cnt > 1:
    ans = [1] * one_cnt
    for v in nums:
        if v > 1 and is_prime[v + 1]:
            ans.append(v)
            break
else:
    for i in range(n):
        for j in range(i+1, n):
            if is_prime[nums[i] + nums[j]]:
                ans = [nums[i], nums[j]]
                break
        if len(ans) > 1:
            break

print(len(ans))
print(*ans)
