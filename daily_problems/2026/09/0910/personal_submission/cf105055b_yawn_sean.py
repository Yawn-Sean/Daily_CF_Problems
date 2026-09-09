# Submission link: https://codeforces.com/gym/105055/submission/390024506
def main():
    n, k = MII()
    s = [int(c) for c in I()]
    
    cur = 0
    
    for x in s:
        cur = (2 * cur + x) % 3
    
    if cur == 0 or n % 2: print('JULIA')
    else: print('GIOVANA')