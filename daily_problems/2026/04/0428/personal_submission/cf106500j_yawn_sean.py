# Submission link: https://codeforces.com/gym/106500/submission/372683965
def main():
    a = II()
    b = II()
    c = II()
    d = II()
    
    if a == b:
        if c != d: print(0)
        else:
            v = 2 * c // (2 * a + 1)
            print(c - a * v)
    else:
        if (d - c) % (b - a): print(0)
        else:
            v = (d - c) // (b - a)
            if v < 0: print(0)
            elif c - a * v < (v + 1) // 2: print(0)
            else: print(c - a * v)