def solve(x, k):
    ans = (x - 1) * x // 2
    ans += x * (lg[k] - 1)
    return ans

def binary_search(l, r, k):
    while l + 1 < r:
        mid = l + (r - l + 1) // 2
        x = solve(mid, k)
        if x <= n:
            l = mid
        else:
            r = mid
    return l

lg = [1] * 62
for i in range(1, 62):
    lg[i] = lg[i - 1] * 2

n = int(input())
found = False

for k in range(62):
    r1 = int(math.sqrt(n * 2))
    r2 = n // max(1, lg[k] - 1)
    ans = binary_search(0, min(r1, r2) + 2, k)
    
    if solve(ans, k) == n and ans % 2 == 1:
        found = True
        print(ans * lg[k])
        

if not found:
    print(-1)
