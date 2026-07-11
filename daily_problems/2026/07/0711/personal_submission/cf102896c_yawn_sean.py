# Submission link: https://codeforces.com/gym/102896/submission/381952637
def main():
    n = II()
    parent = [-1] + LGMI()
    
    path = [[] for _ in range(n)]
    for i in range(1, n):
        path[parent[i]].append(i)
    
    def dfs(x):
        ans = []
        for y in path[x]:
            nans = []
            tmp = dfs(y)
    
            nans.extend(tmp)
            for v in ans:
                tmp.reverse()
                nans.append(v)
                nans.extend(tmp)
            
            ans = nans
        
        if x: ans = [x] + ans
        
        return ans
    
    ans = dfs(0)
    
    print(len(ans))
    print(' '.join(str(x + 1) for x in ans))