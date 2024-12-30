import sys
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

n = int(input())
a = list(map(int, input().split()))
for i in range(29, -1, -1):
    ans = []
    cnt = -1
    for ai in a:
        if (ai >> i) & 1:
            ans.append(ai)
            cnt &= ai
    if cnt & -cnt == 1 << i:
        print(len(ans))
        exit(print(*ans))
