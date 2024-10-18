# submission url: https://codeforces.com/contest/873/submission/279408039
def main():
    n, k = map(int, input().split()) 

    if k & 1 == 0: 
        print(-1)
        exit() 
    k -= 1
    ans = list(range(1, n + 1))
    
    def dfs(l, r): 
        global k 
        if k == 0 or l + 1 == r: 
            return 
        k -= 2
        mid = l + r >> 1 
        ans[mid], ans[mid - 1] = ans[mid - 1], ans[mid]
        dfs(l, mid)
        dfs(mid, r)
    
    dfs(0, n)
    
    print(*ans if k == 0 else [-1])
