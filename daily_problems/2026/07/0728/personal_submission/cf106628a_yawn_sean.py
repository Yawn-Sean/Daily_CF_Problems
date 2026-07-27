# Submission link: https://codeforces.com/gym/106628/submission/384457741
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n, q = MII()
        nums = LII()
        
        left = [-1] * n
        stk = [-1]
        
        for i in range(n):
            while stk[-1] != -1 and nums[stk[-1]] <= nums[i]:
                stk.pop()
            left[i] = stk[-1]
            stk.append(i)
        
        right = [n] * n
        stk = [n]
        
        for i in range(n - 1, -1, -1):
            while stk[-1] != n and nums[stk[-1]] <= nums[i]:
                stk.pop()
            right[i] = stk[-1]
            stk.append(i)
        
        updates = [[] for _ in range(n)]
        
        for i in range(n):
            if left[i] >= 0 and right[i] < n:
                updates[left[i]].append(right[i])
        
        queries = [[] for _ in range(n)]
        
        for i in range(q):
            l, r = GMI()
            queries[l].append((i, r))
        
        ans = [0] * q
        
        fen = FenwickTree(n)
        
        for l in range(n - 1, -1, -1):
            for r in updates[l]:
                fen.add(r, 1)
            
            for i, r in queries[l]:
                ans[i] = r - l + 1 - fen.rsum(0, r)
        
        outs.append('\n'.join(map(str, ans)))
    
    print('\n'.join(map(str, outs)))