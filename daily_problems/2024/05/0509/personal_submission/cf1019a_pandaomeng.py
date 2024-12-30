# submission: https://codeforces.com/problemset/submission/1019/260255373

def main():
    n, m = MII()
    cnt = Counter()
    other_max = 0
    arr = []
    for _ in range(n):
        p, c = MII()
        cnt[p] += 1
        if p != 1:
            other_max = max(other_max, cnt[p])
            arr.append((c, p))
    
    if cnt[1] > other_max:
        print(0)
        exit()

    if n == 1:
        ans = 0 if 1 in cnt else arr[0][0]
        print(ans)
        exit()
    
    # 枚举 parties 1 需要的票数，最多需要 min(n // 2 + 1, other_max + 1) 张票
    upper = min(n // 2 + 1, other_max + 1)
    arr.sort(reverse=True)
    ans = inf
    for i in range(upper, 1, -1):
        p_cnt = Counter()
        vis = [False] * len(arr)
        cur = cnt[1] # 党派 1 当前的票数
        new_ans = 0
        for j, x in enumerate(arr):
            if p_cnt[x[1]] >= i - 1: # 该党派已经有 i 张票了，需要贿赂
                new_ans += x[0]
                cur += 1
                vis[j] = True
            else:
                p_cnt[x[1]] += 1
        still_need = i - cur
        for j in range(len(arr) - 1, -1, -1):
            if still_need == 0:
                break
            else:
                if not vis[j]:
                    new_ans += arr[j][0]
                    still_need -= 1
        ans = min(ans, new_ans)
    print(ans if ans != inf else 0)
