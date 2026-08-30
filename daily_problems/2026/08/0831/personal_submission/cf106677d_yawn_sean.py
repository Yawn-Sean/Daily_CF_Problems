# Submission link: https://codeforces.com/gym/106677/submission/388873066
def main():
    outs = []
    
    while True:
        s, k = MII()
        if s == 0 and k == 0: break
        
        k -= 1
        
        if s * s <= k:
            k -= s * s
            x, y = divmod(k, 2 * s)
            
            if y % 2 == 0:
                y //= 2
                outs.append(s if y == 0 else y)
            else:
                outs.append(s + 1 + x)
        
        else:
            l, r = 0, s
            
            while l <= r:
                mid = (l + r) // 2
                
                x = 2 * s - 1
                y = x - 2 * (mid - 1)
                
                if (x + y) * mid // 2 > k: r = mid - 1
                else: l = mid + 1
            
            x = 2 * s - 1
            y = x - 2 * (r - 1)
            k -= (x + y) * r // 2
            
            if k == 0: outs.append(s)
            else:
                x, y = divmod(k - 1, 2)
                
                if y == 0: outs.append(r + 1 + x)
                else: outs.append(r + 1)
    
    print('\n'.join(map(str, outs)))