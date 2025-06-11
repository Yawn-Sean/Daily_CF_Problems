# Submission link: https://codeforces.com/contest/86/submission/296223578
def main():
    l, r = MII()
    v = 10 ** len(str(r)) - 1
    mid = v // 2
    
    if mid <= l: print(l * (v - l))
    elif mid >= r: print(r * (v - r))
    else: print(mid * (v - mid))