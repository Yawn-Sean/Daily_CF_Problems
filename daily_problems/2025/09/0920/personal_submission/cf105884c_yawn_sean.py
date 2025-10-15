# Submission link: https://codeforces.com/gym/105884/submission/339399378
def main():
    t = II()
    outs = []
    
    def check(x1, y1, x2, y2, x3, y3):
        dx1, dy1 = x2 - x1, y2 - y1
        dx2, dy2 = x3 - x1, y3 - y1
        return dx1 * dy2 < dx2 * dy1
    
    for _ in range(t):
        n = II()
        pts = [tuple(MII()) for _ in range(n)]
        
        cv = convex_hull(pts[:])
        chosen = set(cv)
        
        pos = {v: i for i, v in enumerate(pts)}
        
        if len(cv) == n: outs.append('-1')
        else:
            for idx, pt in enumerate(pts):
                if pt not in chosen:
                    x, y = pt
                    
                    for i in range(2, len(cv)):
                        x1, y1 = cv[0]
                        x2, y2 = cv[i - 1]
                        x3, y3 = cv[i]
                        
                        if check(x1, y1, x2, y2, x, y) and check(x2, y2, x3, y3, x, y) and check(x3, y3, x1, y1, x, y):
                            outs.append(f'{idx + 1} {pos[(x1, y1)] + 1} {pos[(x2, y2)] + 1} {pos[(x3, y3)] + 1}')
                            break
                    break
    
    print('\n'.join(outs))