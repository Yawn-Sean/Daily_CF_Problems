# Submission link: https://codeforces.com/gym/104669/submission/365085772
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        a, b = MII()
        total = (2 * a + b - 1) * b // 2
        
        def check(x):
            for i in range(1, b):
                l = a * i + i * (i - 1) // 2
                r = a * i + (2 * b - 1 - i) * i // 2
                if r // x * x >= l: return True
            return False
        
        ans = 0
        for i in range(1, 10 ** 5 * 2):
            if i * i > total: break
            if total % i == 0:
                if check(i): ans = fmax(ans, i)
                if check(total // i): ans = fmax(ans, total // i)
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))