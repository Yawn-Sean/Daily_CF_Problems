import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
lii = lambda: list(map(int, input().split()))

min_ = lambda a, b: a if a < b else b

n, k = lii()
nums = lii()
mp = {0: 0}
for x in nums:
    for i in range(1, k+1):
        mp[x*i] = i

def solve():
    target = ii()
    if target < nums[0] or target > k*nums[-1]:
        return -1
    ans = k + 1
    for v, i in mp.items():
        ans = min_(ans, i + mp.get(target-v, k+1))
    return ans if ans <= k else -1

ans = []
for _ in range(ii()):
    ans.append(solve())
print(*ans, sep='\n')