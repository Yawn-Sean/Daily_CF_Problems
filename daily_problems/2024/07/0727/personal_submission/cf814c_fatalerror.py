import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())

n = ii()
arr = [ord(ch)-97 for ch in input()]
mp = [[0] * 26 for _ in range(n+1)]
for k in range(1, n+1):
    for target in range(26):
        j = 0
        cur = 0
        res = 0
        for i, x in enumerate(arr):
            cur += x == target
            while i-j+1 - cur > k:
                cur -= arr[j] == target
                j += 1
            res = max(res, i-j+1)
        mp[k][target] = res

ans = []
for _ in range(ii()):
    k, ch = input().split()
    ans.append(mp[int(k)][ord(ch)-97])
print(*ans, sep='\n')