import sys

# region fastio
input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))
# endregion fastio

# MOD = 998_244_353
# MOD = 10 ** 9 + 7
# DIR4 = ((-1, 0), (0, 1), (1, 0), (0, -1)) #URDL
# DIR8 = ((-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1))

def solve() -> None:
    n = sint()
    nums = ints()
    idx = sorted(range(n), key = lambda x: nums[x])
    
    pre, ans, x = nums[idx[0]], idx[0], nums[idx[1]] - nums[idx[0]]
    for i in range(1, n):
        if nums[idx[i]] - pre != x:
            if ans != idx[0]:
                ans = -1
                break
            ans = idx[i]
        else:
            pre = nums[idx[i]]
    if ans != -1:
        print(ans + 1)
        return
    
    pre, ans, x = nums[idx[-1]], idx[-1], nums[idx[-2]] - nums[idx[-1]]
    for i in range(n - 1, -1, -1):
        if nums[idx[i]] - pre != x:
            if ans != idx[-1]:
                ans = -1
                break
            ans = idx[i]
        else:
            pre = nums[idx[i]]
            
    print(ans + 1 if ans != -1 else ans)

solve()
