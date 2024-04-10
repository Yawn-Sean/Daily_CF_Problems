from itertools import accumulate
n, A, c_f, c_m, m = map(int, input().split())
level = list(map(int, input().split()))

try_level = sorted(list(range(n)), key = lambda x: level[x], reverse = True)
prefix = list(accumulate([level[i] for i in try_level], initial = 0))

ans_min = 0
ans_max = 0
ans = 0

for i in range(n + 1):
    used_max = i * A - prefix[i]
    if used_max > m:
        break
    left = m - used_max
    l, r = i+1, n
    while l <= r:
        mid = (l + r) // 2
        if level[try_level[mid - 1]] * (n - mid) - prefix[n] + prefix[mid] <= left:
            r = mid - 1
        else:
            l = mid + 1
    now_min = min(A, (level[try_level[l - 1]] + (left - (level[try_level[l - 1]] * (n - l) - prefix[n] + prefix[l])) // (n - l + 1))) if i != n else A
    if i * c_f + now_min * c_m > ans:
        ans_max = i
        ans_min = now_min
        ans = i * c_f + ans_min * c_m

print(ans)
for i in range(ans_max):
    level[try_level[i]] = A
for i in range(n):
    if level[i] < ans_min:
        level[i] = ans_min

print(*level)
