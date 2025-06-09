# Submission link: https://codeforces.com/contest/653/submission/318570298
def main():
    n = II()
    nums = LII()
    
    def check(idx):
        return nums[idx] > nums[idx + 1] if idx & 1 else nums[idx] < nums[idx + 1]
    
    cur = [check(i) for i in range(n - 1)]
    res = sum(cur)
    
    vis = [0] * n
    
    ans = 0
    for i in range(n - 1):
        if not cur[i]:
            
            for u in range(i, i + 2):
                for v in range(n):
                    if u == i and v == i + 1:
                        continue
                    
                    nums[u], nums[v] = nums[v], nums[u]
                    nres = res
                    
                    for nu in range(u - 1, u + 1):
                        if 0 <= nu < n - 1 and not vis[nu]:
                            vis[nu] = 1
                            nres -= cur[nu]
                            nres += check(nu)
                    
                    for nv in range(v - 1, v + 1):
                        if 0 <= nv < n - 1 and not vis[nv]:
                            vis[nv] = 1
                            nres -= cur[nv]
                            nres += check(nv)
                    
                    if nres == n - 1:
                        ans += 1
                    
                    for nu in range(u - 1, u + 1):
                        if 0 <= nu < n - 1:
                            vis[nu] = 0
                    
                    for nv in range(v - 1, v + 1):
                        if 0 <= nv < n - 1:
                            vis[nv] = 0
                    
                    nums[u], nums[v] = nums[v], nums[u]
            
            break
    
    print(ans)