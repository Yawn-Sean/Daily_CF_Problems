# 暴力(超时
# n, m = map(int, input().split())
# a = [0] + list(map(int, input().split()))
# res = []
# for _ in range(m):
#     l, r, x = map(int, input().split())
#     for i in range(l, r + 1):
#         if a[i] != x:
#             res.append(i)
#             break
#     else:
#         res.append(-1)
# print(*res, sep='\n')



def main():
    n, m = map(int, input().split())
    nums = list(map(int, input().split()))
    lefts = list(range(n))
    for i in range(1, n):
        if nums[i] == nums[i-1]:
            lefts[i] = lefts[i-1]
    res = []
    for _ in range(m):
        l, r, x = map(int, input().split())
        l -= 1
        r -= 1
        if nums[r] != x:
            res.append(r + 1)
        else:
            res.append(lefts[r] if lefts[r] - 1 >= l else -1)
    print('\n'.join(map(str, res)))

main()
