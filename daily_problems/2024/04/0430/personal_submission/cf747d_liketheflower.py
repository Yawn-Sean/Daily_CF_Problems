# https://codeforces.com/contest/747/submission/258954643
import itertools
INF = 1e9
def solve():
    n, k = [int(x) for x in input().split()]
    nums = [int(x) for x in input().split()]
    nums = [1 if x < 0 else 0 for x in nums]
    nums = [0] + nums
    seg_between_winters = []
    winters = 0
    winter_segs = []
    for x, gb in itertools.groupby(nums):
        if x == 0:
            seg_between_winters.append(len(list(gb)))
        else:
            sz = len(list(gb))
            winters += sz
            winter_segs.append(sz)
    if winters > k:
        print(-1)
        return
    number_changes = 2*len(seg_between_winters)
    if len(winter_segs) == 0:
        print(0)
        return
    ans = INF
    def helper(num_changes, segs, K):
        if num_changes < 0 or K < 0:
            return INF
        segs.sort()
        tot = 0
        for seg in segs:
            tot += seg
            if tot <= K:
                num_changes -= 2
            else:
                break
        return num_changes
    number_changes -= 1
    if nums[-1] == 0:
        ans = min(ans, helper(number_changes - 2,  seg_between_winters[1:-1], k - winters - seg_between_winters[-1]))
        ans = min(ans, helper(number_changes - 1 ,  seg_between_winters[1:-1], k - winters))
    if nums[-1] == 1:
        ans = min(ans, helper(number_changes,  seg_between_winters[1:], k - winters))
    print(ans)
solve()
