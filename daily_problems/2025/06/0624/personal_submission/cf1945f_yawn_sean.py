# Submission link: https://codeforces.com/contest/1945/submission/325846915
def main():
    t = II()
    outs = []

    for _ in range(t):
        n = II()
        nums = LII()
        perm = LGMI()
        
        ans, chosen = 0, 0
        pq = []
        
        for i in range(n - 1, -1, -1):
            heappush(pq, nums[perm[i]])
            while len(pq) > i + 1: heappop(pq)
            if len(pq) == i + 1 and pq[0] * len(pq) >= ans:
                ans = pq[0] * len(pq)
                chosen = len(pq)
        
        outs.append(f'{ans} {chosen}')

    print('\n'.join(outs))