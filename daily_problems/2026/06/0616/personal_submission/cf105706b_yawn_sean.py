# Submission link: https://codeforces.com/gym/105706/submission/378953548
def main():
    def simplify(tmp):
        ans = []
        
        for l, r in tmp:
            if len(ans) == 0:
                ans.append((l, r))
            else:
                if ans[-1][1] * 2 >= l:
                    vl, vr = ans.pop()
                    ans.append((fmin(l, vl), fmax(r, vr)))
                else:
                    ans.append((l, r))
        
        return ans
    
    def merge(intervals1, intervals2):
        tmp = []
        p1, p2 = 0, 0
        
        while p1 < len(intervals1) and p2 < len(intervals2):
            if intervals1[p1] < intervals2[p2]:
                tmp.append(intervals1[p1])
                p1 += 1
            else:
                tmp.append(intervals2[p2])
                p2 += 1
        
        while p1 < len(intervals1):
            tmp.append(intervals1[p1])
            p1 += 1
        
        while p2 < len(intervals2):
            tmp.append(intervals2[p2])
            p2 += 1
        
        return simplify(tmp)
    
    t = II()
    outs = []
    
    for _ in range(t):
        n, q = MII()
        path = [[] for _ in range(n)]
        
        for _ in range(n - 1):
            u, v, w = MII()
            u -= 1
            v -= 1
            path[u].append(w * n + v)
            path[v].append(w * n + u)
        
        parent = [-1] * n
        que = [0]
        
        for u in que:
            for msk in path[u]:
                v = msk % n
                if parent[u] != v:
                    parent[v] = u
                    que.append(v)
        
        dp = [[(0, 0)] for _ in range(n)]
        
        for u in reversed(que):
            for msk in path[u]:
                w, v = divmod(msk, n)
                if parent[v] == u:
                    dp[u] = merge(dp[u], [(l + w, r + w) for l, r in dp[v]])
        
        rev_dp = [[] for _ in range(n)]
        
        for u in que:
            pre = [[]]
            for msk in path[u]:
                w, v = divmod(msk, n)
                if parent[v] == u:
                    pre.append(merge(pre[-1], [(l + w, r + w) for l, r in dp[v]]))
            
            suf = [[]]
            for msk in reversed(path[u]):
                w, v = divmod(msk, n)
                if parent[v] == u:
                    suf.append(merge(suf[-1], [(l + w, r + w) for l, r in dp[v]]))
            
            pre.reverse()
            suf.pop()
            
            for msk in path[u]:
                w, v = divmod(msk, n)
                if parent[v] == u:
                    rev_dp[v] = merge([(l + w, r + w) for l, r in rev_dp[u]], [(l + w, r + w) for l, r in merge(suf.pop(), pre.pop())])
        
        total_merge = []
        while dp: total_merge = merge(total_merge, dp.pop())
        while rev_dp: total_merge = merge(total_merge, rev_dp.pop())
        
        ans = []
        
        for _ in range(q):
            val = II()
            flg = False
            
            for l, r in total_merge:
                if (l + 1) // 2 <= val <= r:
                    flg = True
            
            ans.append(1 if flg else 0)
        
        outs.append(''.join(map(str, ans)))
    
    print('\n'.join(outs))