def check(mid, i):
    global n
    cnt = 0
    for j in range(i):
        cnt += mid * pow(2, j)
    cnt += mid * (mid - 1) // 2
    return cnt

n = int(input())
ans = []
for i in range(4 * 18):
    if pow(2, i - 1) > n:
        break
    left = 1
    right = n
    while left < right:
        mid = (left + right) // 2
        p = 2 * mid - 1
        cur = check(p, i)
        if cur > n:
            right = mid - 1
        elif cur < n:
            left = mid + 1
        else:
            left = mid
            right = mid
            break
    left = 2 * left - 1
    if check(left, i) == n:
        
        ans.append(left * 2 ** i)
ans.sort()
if ans:
    for i in ans:
        print(i)
else:
    print(-1)
    
    
