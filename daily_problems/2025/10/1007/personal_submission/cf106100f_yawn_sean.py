# Submission link: https://codeforces.com/gym/106100/submission/342182404
def main():
    n = II()
    v1 = LII()
    v2 = LII()
    
    for i in range(n):
        v1[i] -= i
        v2[i] -= i
    
    if sorted(v1) != sorted(v2):
        print(-1)
    else:
        rnd = random.getrandbits(30)
        d = defaultdict(list)
        
        for i, v in enumerate(v1):
            d[v ^ rnd].append(i)
        
        for i in range(n - 1, -1, -1):
            v2[i] = d[v2[i] ^ rnd].pop()
        
        fen = FenwickTree(n)
        
        ans = 0
        for i in range(n):
            ans += fen.rsum(v2[i], n - 1)
            fen.add(v2[i], 1)
        
        print(ans)