import sys
input = sys.stdin.readline
n = int(input())
s = input().strip()
q = int(input())
dp = [[0] * (n + 1) for _ in range(26)]
for char_idx in range(26):
    tar = chr(char_idx + ord('a'))
    for m in range(n + 1):
        l = 0
        cnt = 0
        for r in range(n):
            if s[r] != tar:
                cnt += 1
            while cnt > m:
                if s[l] != tar:
                    cnt -= 1
                l += 1
            dp[char_idx][m] = max(dp[char_idx][m], r - l + 1)
out_lines = []
for _ in range(q):
    plan = input().split()
    m = int(plan[0])
    c = plan[1]
    idx = ord(c) - ord('a')
    print(dp[idx][m])