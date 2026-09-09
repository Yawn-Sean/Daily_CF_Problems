# Submission link: https://codeforces.com/gym/102894/submission/390005339
def main():
    n, k = MII()
    
    caps = LII()
    nums = LII()
    pays = LII()
    
    caps.sort(reverse=True)
    
    pt = 0
    total = 0
    pq = []
    
    for i in sorted(range(k), key=lambda x: -nums[x]):
        while pt < n and caps[pt] >= nums[i]:
            pt += 1
        
        heappush(pq, pays[i])
        total += pays[i]
        
        if len(pq) > pt:
            total -= heappop(pq)
    
    print(total)