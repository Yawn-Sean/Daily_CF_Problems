# Submission link: https://codeforces.com/contest/639/submission/323185972
def main():
    n, k, b, c = MII()
    b = min(b, 5 * c)

    nums = LII()
    nums.sort()

    ans = 10 ** 18

    for i in range(5):
        pq = []
        total = 0
        
        for v in nums:
            cur = 0
            while v % 5 != i:
                v += 1
                cur += c
            
            v = (v - i) // 5
            
            heappush(pq, v * b - cur)
            total += v * b - cur
            
            while len(pq) > k:
                total -= heappop(pq)
            
            if len(pq) == k:
                ans = fmin(ans, v * b * k - total)

    print(ans)