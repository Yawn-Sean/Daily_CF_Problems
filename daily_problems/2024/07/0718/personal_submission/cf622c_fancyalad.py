# submission link: https://codeforces.com/contest/622/submission/271177079

n, m = map(int, input().split())
nums = [0] + list(map(int, input().split()))
left = [0] * (n + 1)
for i in range(1, n + 1):
    if nums[i] == nums[i - 1]:
        left[i] = left[i - 1]
    else:
        left[i] = i
 
while m:
    l, r, x = map(int, input().split())
    if nums[r] != x:
        print(r)
    elif left[r] > l:
        print(left[r] - 1)
    else:
        print(-1)
    m -= 1