# Submission link: https://codeforces.com/gym/104017/submission/387738340
def main():
    t = II()
    outs = []
    
    def factors(x):
        for i in range(1, 100000):
            if i * i > x: break
            if x % i == 0:
                yield i
                if x // i != i:
                    yield x // i
    
    for _ in range(t):
        w, l = MII()
        
        ans = {2}
        
        for x in factors(math.gcd(w - 1, l - 1)): ans.add(x)
        for x in factors(math.gcd(w - 2, l)): ans.add(x)
        for x in factors(math.gcd(w, l - 2)): ans.add(x)
        
        ans = sorted(ans)
        
        outs.append(f'{len(ans)} {" ".join(map(str, ans))}')
    
    print('\n'.join(outs))