# Submission link: https://codeforces.com/gym/106097/submission/389066451
def main():
    def query(x):
        print(x, flush=True)
        return I()
    
    def answer(x1, x2):
        print('!', x1, x2)
    
    def search(l, r):
        while l <= r:
            mid = (l + r) // 2
            res = query(mid)
            
            if res == '=': return mid
            
            if res == '<': r = mid - 1
            else: l = mid + 1
        
        return -1
    
    n = II()
    find1 = search(1, n)
    find2 = fmax(search(1, find1 - 1), search(find1 + 1, n))
    
    if find1 > find2: find1, find2 = find2, find1
    answer(find1, find2)