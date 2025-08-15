# Submission link: https://codeforces.com/contest/1913/submission/334075754
def main():
    n, m = MII()
    grid = [LII() for _ in range(n)]
    
    nums1 = LII()
    nums2 = LII()
    
    mcf = MCFGraph(n + m + 2)
    
    src = n + m
    dst = n + m + 1
    
    cur = sum(sum(x) for x in grid)
    
    for i in range(n):
        for j in range(m):
            if grid[i][j]:
                mcf.add_edge(i, j + n, 1, 0)
            else:
                mcf.add_edge(i, j + n, 1, 2)
    
    for i in range(n):
        mcf.add_edge(src, i, nums1[i], 0)
    
    for i in range(m):
        mcf.add_edge(n + i, dst, nums2[i], 0)
    
    mf, mc = mcf.flow(src, dst)
    
    if mf == sum(nums1) == sum(nums2):
        print(mc + (cur - sum(nums1)))
    else:
        print(-1)