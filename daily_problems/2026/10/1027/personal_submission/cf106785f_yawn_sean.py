# Submission link: https://codeforces.com/gym/106785/submission/396084972
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n, m = MII()
        p = LII()
        q = LII()
        
        l, r = 0, fmin(n, m)
        
        while l <= r:
            mid = (l + r) // 2
            
            if [x for x in p if x <= mid] == [x for x in q if x <= mid]: l = mid + 1
            else: r = mid - 1
        
        outs.append(n + m - r * 2)
    
    print('\n'.join(map(str, outs)))