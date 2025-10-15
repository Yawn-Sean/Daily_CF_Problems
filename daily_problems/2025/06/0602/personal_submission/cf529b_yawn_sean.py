# Submission link: https://codeforces.com/contest/529/submission/322457634
def main():
    n = II()
    ws = []
    hs = []

    for _ in range(n):
        w, h = MII()
        ws.append(w)
        hs.append(h)

    st_range = sorted(range(n), key=lambda x: hs[x] - ws[x])

    ans = 10 ** 9 * 2
    used = [0] * n

    cur = sum(ws)

    for h in range(1, 1001):
        flg = True
        cnt = 0
        cur_w = cur
        
        for i in st_range:
            if hs[i] > h:
                if ws[i] > h:
                    flg = False
                    break
                else:
                    used[i] = 1
                    cnt += 1
                    cur_w += hs[i] - ws[i]
            else:
                used[i] = 0
        
        if cnt * 2 > n or not flg: continue
        
        for i in st_range:
            if not used[i] and cnt < n // 2 and ws[i] <= h and hs[i] - ws[i] < 0:
                cnt += 1
                cur_w += hs[i] - ws[i]

        ans = fmin(ans, cur_w * h)

    print(ans)