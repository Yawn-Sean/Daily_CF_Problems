# Submission link: https://codeforces.com/gym/106107/submission/350073234
def main(): 
    t = II()
    outs = []
    rnd = random.getrandbits(30)
    
    for _ in range(t):
        n = II()
        v1 = [x ^ rnd for x in MII()]
        v2 = [x ^ rnd for x in MII()]
        
        ans = 0
        
        fen = FenwickTree(n)
        
        cur_status = defaultdict(list)
        last_pos = {}
        
        for i in range(n):
            last_pos[v2[i]] = i
            start = last_pos[v1[i]] + 1 if v1[i] in last_pos else 0
            
            cur_status[v1[i]].append(i)
            while cur_status[v2[i]]:
                fen.add(cur_status[v2[i]].pop(), 1)
            
            ans += fen.rsum(start, i)
    
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))