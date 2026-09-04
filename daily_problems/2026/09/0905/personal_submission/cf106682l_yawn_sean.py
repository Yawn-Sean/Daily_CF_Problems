# Submission link: https://codeforces.com/gym/106682/submission/389361866
def main():
    n, m = MII()
    nums = LII()
    
    pos = [[] for _ in range(m + 1)]
    for i in range(n):
        pos[nums[i]].append(i)
    
    target = [i for i in range(m + 1) if pos[i]]
    
    k = len(target)
    start = 0
    ans = 0
    
    while start < k:
        nstart1 = 0
        cur1 = 0
        for j in range(start, k):
            p = bisect.bisect_left(pos[target[j]], cur1)
            if p == len(pos[target[j]]): break
            nstart1 = j
            cur1 = pos[target[j]][p]
        
        nstart2 = 0
        cur2 = n
        for j in range(start, k):
            p = bisect.bisect_left(pos[target[j]], cur2) - 1
            if p == -1: break
            nstart2 = j
            cur2 = pos[target[j]][p]
        
        start = fmax(nstart1, nstart2) + 1
        ans += 1
    
    print(k, ans)