# Submission link: https://codeforces.com/contest/220/submission/330359256
def main():
    inf = 2 * n
    
    v1 = [inf]
    v2 = [inf]
    
    vis1 = [0] * (3 * n + 5)
    vis2 = [0] * (3 * n + 5)
    
    ans = [0] * n
    
    for i in range(n):
        for x in updates1_add[i]:
            heappush(v1, x)
        
        for x in updates1_remove[i]:
            vis1[x] += 1
        
        while v1[0] < inf and vis1[v1[0]]:
            vis1[v1[0]] -= 1
            heappop(v1)
        
        for x in updates2_add[i]:
            heappush(v2, x)
        
        for x in updates2_remove[i]:
            vis2[x] += 1
        
        while v2[0] < inf and vis2[v2[0]]:
            vis2[v2[0]] -= 1
            heappop(v2)
        
        ans[i] = fmin(v1[0] - i, v2[0] + i)
    
    print(*ans, sep='\n')