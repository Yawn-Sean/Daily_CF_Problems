# Submission link: https://codeforces.com/gym/106642/submission/386774872
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n, k, x = MII()
    
        acc = [0] * (n + 1)
        
        for i in range(1, n + 1):
            l, r = fmax(-(n - i) * k, acc[i - 1] - k), fmax(0, acc[i - 1] + k)
            
            while l <= r:
                mid = (l + r) // 2
                
                start = -mid
                step = start // k
                
                if (start + start + step * (-k)) * (step + 1) // 2 <= x:
                    r = mid - 1
                else:
                    l = mid + 1
            
            acc[i] = l
            x += l
        
        outs.append(' '.join(str(acc[i + 1] - acc[i]) for i in range(n)))
    
    print('\n'.join(outs))