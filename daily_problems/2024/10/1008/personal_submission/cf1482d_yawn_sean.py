# Submission link: https://codeforces.com/contest/1482/submission/284852422
def main():
    t = II()
    outs = []

    def delete_node(x):
        deleted[x] = 1
        prev[suff[x]] = prev[x]
        suff[prev[x]] = suff[x]

    for _ in range(t):
        n = II()
        nums = LII()
        
        prev = [(i - 1) % n for i in range(n)]
        suff = [(i + 1) % n for i in range(n)]
        
        deleted = [0] * n
        
        ans = []
        dq = deque(list(range(n)))
        
        while dq:
            u = dq.popleft()
            if deleted[u]: continue
            v = suff[u]
            if math.gcd(nums[u], nums[v]) == 1:
                ans.append(v)
                delete_node(v)
                dq.append(u)
        
        outs.append(str(len(ans)) + ' ' + ' '.join(str(x + 1) for x in ans))

    print('\n'.join(outs))