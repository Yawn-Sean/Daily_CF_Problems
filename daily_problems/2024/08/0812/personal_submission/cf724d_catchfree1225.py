import sys
input = lambda: sys.stdin.readline().strip()

def solve():
    n = len(s)
    for max_chr in range(26): # 湊最大子母，到尾距離應<=m
        sub_max_idx = -1
        for i in range(n):
            if s[i] <= max_chr:
                sub_max_idx = i
            elif i - sub_max_idx >= m: # 不是最大字母
                break
        else:
            cnt = [0] * 26
            cur = nxt = -1
            for i in range(n):
                if s[i] < max_chr: # 比max_chr小的都會拿完，再額外特判max_chr
                    cur = i
                    cnt[s[cur]] += 1
                elif s[i] == max_chr: # 是max_chr, 不一定選
                    nxt = i
                    
                if i - cur == m:
                    cur = nxt
                    cnt[s[cur]] += 1
            print(''.join(chr(i + 97) * cnt[i] for i in range(26)))
            return
               
for _ in range(1):
    m = int(input())
    s = [ord(c) - 97 for c in input()]
    solve()