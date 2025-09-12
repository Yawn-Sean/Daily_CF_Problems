# Submission link: https://codeforces.com/gym/101466/submission/338153360
def main():
    s = I()
    t = I()
    cnt = II()
    
    l, r = 1, len(t)
    
    while l <= r:
        mid = (l + r) // 2
        
        if prep(t[:mid] + '#' + s).count(mid) >= cnt:
            l = mid + 1
        else:
            r = mid - 1
    
    print(t[:r] if r else 'IMPOSSIBLE')