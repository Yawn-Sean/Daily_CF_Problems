# Submission link: https://codeforces.com/gym/106826/submission/398638184
def main():
    def query(x):
        print('?', x, flush=True)
        return II()
    
    def answer(x):
        print('!', x)
    
    start = 1 if query(2) == 1 else 2
    
    l = 0
    r = (10 ** 9 - start) // 2
    
    while l < r:
        mid = (l + r) // 2
        
        w = start + 2 * mid + 1
        if w % 2 == 0: w += 1
        
        if query(w) == start % 2: r = mid
        else: l = mid + 1
    
    answer(start + 2 * l)