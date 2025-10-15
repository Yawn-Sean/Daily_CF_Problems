# Submission link: https://codeforces.com/contest/1970/submission/334664564
def main():
    n = II()
    
    calc = [[0] * n for _ in range(n)]
    while True:
        tmp_strs = []
        
        for _ in range(n):
            length = random.randint(10, 30)
            s = ''.join(random.choice('OX') for _ in range(length))
            tmp_strs.append(s)
        
        total_vals = set()
        
        for i in range(n):
            for j in range(n):
                s = tmp_strs[i] + tmp_strs[j]
                k = len(s)
                
                vis = set()
                for x in range(k):
                    for y in range(x, k):
                        vis.add(s[x:y + 1])
                
                calc[i][j] = len(vis)
                total_vals.add(len(vis))
        
        if len(total_vals) == n * n:
            print('\n'.join(tmp_strs), flush=True)
            break
    
    q = II()
    for _ in range(q):
        target = II()
        
        for i in range(n):
            for j in range(n):
                if calc[i][j] == target:
                    print(i + 1, j + 1, flush=True)