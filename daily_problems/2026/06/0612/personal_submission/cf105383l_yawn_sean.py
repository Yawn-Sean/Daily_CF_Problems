# Submission link: https://codeforces.com/gym/105383/submission/378146695
def main():
    mod = 10 ** 9 + 7
    
    n, m, s, t, x, k = MII()
    s -= 1
    t -= 1
    
    inf = 10 ** 9
    
    def f(x, y):
        return x * n + y
    
    def merge_path(msk1, order1, msk2, order2, len2):
        pw = pow(x, len2, mod)
    
        msk = [-1] * (n * n)
        notes = [(inf, inf) for _ in range(n * n)]
        
        for u in range(n):
            for v in range(n):
                for w in range(n):
                    if msk1[f(u, v)] == -1 or msk2[f(v, w)] == -1:
                        continue
                    
                    new_path = (order1[f(u, v)], order2[f(v, w)])
                    if new_path < notes[f(u, w)]:
                        notes[f(u, w)] = new_path
                        msk[f(u, w)] = (msk1[f(u, v)] * pw + msk2[f(v, w)]) % mod
        
        st_range = sorted(range(n * n), key=lambda x: notes[x])
        order = [0] * (n * n)
        
        for i in range(1, n * n):
            if notes[st_range[i]] == notes[st_range[i - 1]]:
                order[st_range[i]] = order[st_range[i - 1]]
            else:
                order[st_range[i]] = order[st_range[i - 1]] + 1
        
        return msk, order
    
    msk = [-1] * (n * n)
    order = [0] * (n * n)
    
    msk[f(s, s)] = 0
    
    tmp_msk = [-1] * (n * n)
    tmp_order = [0] * (n * n)
    
    edges = []
    
    for _ in range(m):
        u, v, w = MII()
        u -= 1
        v -= 1
        edges.append((u, v, w))
    
    edges.sort(key=lambda x: x[2])
    
    for u, v, w in edges:
        tmp_msk[f(u, v)] = w
    
    for i in range(1, m):
        u1, v1, w1 = edges[i - 1]
        u2, v2, w2 = edges[i]
        
        if w1 < w2:
            tmp_order[f(u2, v2)] = tmp_order[f(u1, v1)] + 1
        else:
            tmp_order[f(u2, v2)] = tmp_order[f(u1, v1)]
    
    for i in range(30):
        if k >> i & 1:
            msk, order = merge_path(msk, order, tmp_msk, tmp_order, 1 << i)
        tmp_msk, tmp_order = merge_path(tmp_msk, tmp_order, tmp_msk, tmp_order, 1 << i)
    
    print(msk[f(s, t)])