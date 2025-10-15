# Submission link: https://codeforces.com/contest/140/submission/322597575
def main():
    n = II()
    nums = LII()

    rnd = random.getrandbits(30)
    cnt = Counter()

    for v in nums:
        cnt[v ^ rnd] += 1

    pq = [(-cnt[x], x ^ rnd) for x in cnt]
    ans = []

    while len(pq) >= 3:
        c1, v1 = heappop(pq)
        c2, v2 = heappop(pq)
        c3, v3 = heappop(pq)
        
        ar = [v1, v2, v3]
        ar.sort(reverse=True)
        ans.append(' '.join(map(str, ar)))

        c1 += 1
        c2 += 1
        c3 += 1
        
        if c1: heappush(pq, (c1, v1))
        if c2: heappush(pq, (c2, v2))
        if c3: heappush(pq, (c3, v3))

    print(len(ans))
    print('\n'.join(ans))