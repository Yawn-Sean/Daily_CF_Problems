# submission link: https://codeforces.com/problemset/submission/798/272248345
# gcd(x-y,x+y)=gcd(x-y,(x+y)-(x-y))=gcd(x-y,2y)
# gcd(x-y,x+y)=gcd(x-y,(x+y)+(x-y))=gcd(x-y,2x)
# (x, y)->(x-y, x+y)->((x+y)-(x-y), (x+y)+(x-y))=(2x, 2y)

import sys
import math
input = lambda: sys.stdin.readline().strip()

n = int(input())
nums = list(map(int, input().split()))

print("YES")
if math.gcd(*nums) > 1:
    print(0)
else:
    ans = cnt1 = 0
    for x in nums:
        if x % 2:
            cnt1 += 1
        else:
            # 如果是一奇一偶相邻，比如 3 和 4，进行一次操作变成 1，7，第二次变成 6，8，在又变成 2，14
            # 如果两个奇数，比如 3 和 5，第一次 2，8，第二次 6，10
            ans += cnt1 // 2 + cnt1 % 2 * 2
            cnt1 = 0
    ans += cnt1 // 2 + cnt1 % 2 * 2
    print(ans)

