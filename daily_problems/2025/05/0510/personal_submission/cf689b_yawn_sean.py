# Submission link: https://codeforces.com/contest/689/submission/318998746
def main():
    n = II()
    nums = LGMI()
    
    dis = [-1] * n
    dis[0] = 0
    
    que = [0]
    for u in que:
        if u and dis[u - 1] == -1:
            dis[u - 1] = dis[u] + 1
            que.append(u - 1)
        
        if u + 1 < n and dis[u + 1] == -1:
            dis[u + 1] = dis[u] + 1
            que.append(u + 1)
        
        if dis[nums[u]] == -1:
            dis[nums[u]] = dis[u] + 1
            que.append(nums[u])
    
    print(' '.join(map(str, dis)))