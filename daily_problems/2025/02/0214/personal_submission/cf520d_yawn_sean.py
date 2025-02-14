# Submission link: https://codeforces.com/contest/520/submission/306019001
def main():
    n = II()

    pts = []
    for _ in range(n):
        x, y = MII()
        pts.append((x, y))

    d = {v: i for i, v in enumerate(pts)}

    used = [0] * n
    pq1 = []
    pq2 = []

    def find_support(x, y):
        cnt = 0
        for dx in range(-1, 2):
            if (x + dx, y - 1) in d:
                cnt += 1
        return cnt

    def check(x, y):
        if (x, y) not in d: return False
        for dx in range(-1, 2):
            if (x + dx, y + 1) in d and find_support(x + dx, y + 1) == 1:
                return False
        return True

    for i in range(n):
        if check(pts[i][0], pts[i][1]):
            pq1.append(-i)
            pq2.append(i)

    heapify(pq1)
    heapify(pq2)

    ans = 0
    mod = 10 ** 9 + 9

    for i in range(n):
        while True:
            if i % 2 == 0:
                while used[-pq1[0]]:
                    heappop(pq1)
                u = -heappop(pq1)
            else:
                while used[pq2[0]]:
                    heappop(pq2)
                u = heappop(pq2)
            
            x, y = pts[u][0], pts[u][1]
            
            if check(x, y):
                ans = (ans * n + u) % mod
                used[u] = 1
                del d[(x, y)]
                
                for dx in range(-1, 2):
                    if check(x + dx, y - 1):
                        heappush(pq1, -d[(x + dx, y - 1)])
                        heappush(pq2, d[(x + dx, y - 1)])
                break

    print(ans)