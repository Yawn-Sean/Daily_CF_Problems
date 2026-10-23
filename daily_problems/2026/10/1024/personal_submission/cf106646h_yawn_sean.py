# Submission link: https://codeforces.com/gym/106646/submission/395672517
def main():
    n = II()
    v1 = LII()
    v2 = LII()
    
    ans = 0
    pq = []
    
    for i in range(2 * n):
        ans -= v2[i]
        heappush(pq, -(v1[i] + v2[i]))
        if i % 2 == 0: ans -= heappop(pq)
    
    print(ans)