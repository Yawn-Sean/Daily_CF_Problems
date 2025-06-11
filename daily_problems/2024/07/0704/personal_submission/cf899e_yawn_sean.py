# Submission Link: https://codeforces.com/contest/899/submission/268691696
def main():
    n = II()
    nums = LII()

    vals = []
    cnts = []

    last_val = 0
    cnt = 0

    for num in nums:
        if num != last_val:
            if cnt:
                vals.append(last_val)
                cnts.append(cnt)
            last_val = num
            cnt = 1
        else:
            cnt += 1

    vals.append(last_val)
    cnts.append(cnt)

    k = len(vals)
    pre = list(range(-1, k - 1))
    nex = list(range(1, k + 1))

    def delete(x):
        cnts[x] = 0
        if pre[x] >= 0:
            nex[pre[x]] = nex[x]
        if nex[x] < k:
            pre[nex[x]] = pre[x]

    hpq = [-cnts[i] * k + i for i in range(k)]
    heapify(hpq)

    ans = 0
    while hpq:
        c, i = divmod(heappop(hpq), k)
        if -cnts[i] != c: continue
        ans += 1
        if pre[i] >= 0 and nex[i] < k and vals[pre[i]] == vals[nex[i]]:
            cnts[pre[i]] += cnts[nex[i]]
            delete(nex[i])
            heappush(hpq, -cnts[pre[i]] * k + pre[i])
        delete(i)

    print(ans)