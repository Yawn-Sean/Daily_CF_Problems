# Submission link: https://codeforces.com/contest/316/submission/328387401
def main():
    n, pos = MII()
    pos -= 1

    prev = LGMI()
    note = [1] * n

    for i in range(n):
        if prev[i] >= 0:
            note[prev[i]] = 0

    tmp = []
    relative_pos = -1

    for i in range(n):
        if note[i]:
            cur = i
            cnt = 0
            flg = False
            
            while cur >= 0:
                cnt += 1
                if cur == pos:
                    flg = True
                    relative_pos = cnt
                cur = prev[cur]
            
            if flg: relative_pos = cnt + 1 - relative_pos
            else: tmp.append(cnt)

    dp = [0] * (n + 1)
    dp[0] = 1

    for x in tmp:
        for i in range(n, x - 1, -1):
            if dp[i - x]:
                dp[i] = 1

    print('\n'.join(str(i + relative_pos) for i in range(n + 1) if dp[i]))