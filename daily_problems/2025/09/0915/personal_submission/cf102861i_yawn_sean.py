# Submission link: https://codeforces.com/gym/102861/submission/338617304
def main():
    n = II()
    mod = 10 ** 9 + 7
    
    parent = [-1] + LGMI()
    
    path = [[] for _ in range(n)]
    for i in range(1, n):
        path[parent[i]].append(i)
    
    que = [0]
    for i in que:
        for j in path[i]:
            que.append(j)
    
    que.reverse()
    
    dp0 = [1] * n
    dp1 = [1] * n
    
    for i in que:
        if len(path[i]) == 0:
            continue
        
        v0, v1 = 0, 1
        
        for j in path[i]:
            v0 = (v1 * dp0[j] + v0 * dp1[j]) % mod
            v1 = v1 * dp1[j] % mod
        
        dp0[i] = v0
        dp1[i] = (v0 + v1) % mod
        
    print(dp1[0])