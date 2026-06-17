# Submission link: https://codeforces.com/gym/105079/submission/379197220
def main():
    n = II()
    nums = LII()
    
    pq = [-x for x in nums]
    heapify(pq)
    lazy = 0
    
    for v in MII():
        lazy += v
        val = -heappop(pq) + lazy
        val -= val // 2
        heappush(pq, -(val - lazy))
    
    print(sum(-x + lazy for x in pq))