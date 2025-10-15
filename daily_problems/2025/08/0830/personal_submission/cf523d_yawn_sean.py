# Submission link: https://codeforces.com/contest/523/submission/336133227
def main():
    n, k = MII()
    cur = [0] * k
    
    outs = []
    
    for _ in range(n):
        s, m = MII()
        x = heappop(cur)
        x = fmax(x, s) + m
        
        outs.append(x)
        heappush(cur, x)
    
    print('\n'.join(map(str, outs)))