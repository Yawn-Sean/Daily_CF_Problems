# Submission link: https://codeforces.com/gym/106825/submission/398762274
def main():
    n = II()
    gs = LII()
    ms = LII()
    
    def f(l, r):
        if l == r: return [(0, 10 ** 9, l, 0)]
        
        mid = (l + r) // 2
        vl = f(l, mid)
        vr = f(mid + 1, r)
        
        pl, pr = 0, 0
        
        ans = []
        
        while pl < len(vl) and pr < len(vr):
            dl1, dr1, win1, score1 = vl[pl]
            dl2, dr2, win2, score2 = vr[pr]
            
            dl = fmax(dl1, dl2)
            dr = fmin(dr1, dr2)
            
            if dl <= dr:
                score = score1 + score2 + ms[win1] + ms[win2]
                
                if gs[win1] > gs[win2]:
                    sep = gs[win1] - gs[win2]
                    
                    if dl <= sep <= dr:
                        ans.append((dl, sep, win1, score))
                    
                    if dl <= sep + 1 <= dr:
                        ans.append((sep + 1, dr, win2, score))
                    
                    if sep > dr:
                        ans.append((dl, dr, win1, score))
                    
                    if sep + 1 < dl:
                        ans.append((dl, dr, win2, score))
    
                else:
                    sep = gs[win2] - gs[win1]
                    
                    if dl <= sep <= dr:
                        ans.append((dl, sep, win2, score))
                    
                    if dl <= sep + 1 <= dr:
                        ans.append((sep + 1, dr, win1, score))
                    
                    if sep > dr:
                        ans.append((dl, dr, win2, score))
                    
                    if sep + 1 < dl:
                        ans.append((dl, dr, win1, score))
                
            if dr1 < dr2: pl += 1
            else: pr += 1
        
        return ans
    
    chosen = -1
    ans = -1
    
    for dl, dr, win, score in f(0, (1 << n) - 1):
        if score > ans:
            chosen = dl
            ans = score
    
    print(ans)
    print(chosen)