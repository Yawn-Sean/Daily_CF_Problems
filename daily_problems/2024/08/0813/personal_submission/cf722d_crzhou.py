def main():
    n = int(input())
    nums = list(map(int, input().split()))
    
    pq = []
    used = set()
    
    for x in nums:
        heapq.heappush(pq, -x) 
        used.add(x)

    while True:
        mx = -heapq.heappop(pq) 
        tmp = mx
        while mx > 0 and mx in used:
            mx //= 2
        
        if mx == 0:
            heapq.heappush(pq, -tmp)
            break
        
        used.remove(tmp)
        used.add(mx)
        heapq.heappush(pq, -mx) 
    
    result = []
    while pq:
        result.append(-heapq.heappop(pq))
    
    print(' '.join(map(str, result)))

if __name__ == "__main__":
    main()
