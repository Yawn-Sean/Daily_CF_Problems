n = int(input())
nums = list(map(int, input().split()))
mn = min(nums)
cnt = [0] * 3
for x in nums:
    cnt[x-mn] += 1
if not cnt[0] or not cnt[2]:
    print(n)
    print(*nums)
else:
    diff02 = min(cnt[0], cnt[2]) * 2
    diff1 = cnt[1] // 2 * 2
    if diff02 > diff1:
        print(n-diff02)
        cnt[0] -= diff02 // 2
        cnt[2] -= diff02 // 2
        cnt[1] += diff02
    else:
        print(n-diff1)
        cnt[1] -= diff1
        cnt[0] += diff1 // 2
        cnt[2] += diff1 // 2
    ans = []
    for x in range(3):
        ans.extend([mn+x] * cnt[x])
    print(*ans)
