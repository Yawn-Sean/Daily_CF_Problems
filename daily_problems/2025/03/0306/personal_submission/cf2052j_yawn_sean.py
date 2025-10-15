# Submission link: https://codeforces.com/contest/2052/submission/309144933
def main():
    t = II()
    outs = []

    for _ in range(t):
        n, m, q = MII()
        time = LII()
        deadline = LII()
        
        to_watch = LII()
        queries = LII()
        
        st_range = sorted(range(n), key=lambda x: deadline[x])

        acc = [0] * n
        saved = [0] * n

        for i in range(n):
            u = st_range[i]
            acc[i] = time[u]
            if i: acc[i] += acc[i - 1]
            saved[i] = deadline[u] - acc[i]
        
        for i in range(n - 2, -1, -1):
            saved[i] = fmin(saved[i], saved[i + 1])
        
        for i in range(1, m):
            to_watch[i] += to_watch[i - 1]
        
        deadline.sort()
        
        res = [0] * q
        for i in range(q):
            p = bisect.bisect_left(deadline, queries[i])
            v = queries[i]
            if p < n: v = fmin(v, saved[p])
            if p: v = fmin(v, queries[i] - acc[p - 1])
            res[i] = bisect.bisect_right(to_watch, v)
        
        outs.append(' '.join(map(str, res)))

    print('\n'.join(outs))