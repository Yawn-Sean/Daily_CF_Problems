# Submission link: https://codeforces.com/gym/102946/submission/362134165
def main(): 
    def query(i, j):
        print('?', i, j, flush=True)
        return II()
    
    def answer(x):
        print('!', x)
    
    n = II()
    vals = [query(0, i) for i in range(n)]
    
    if min(vals) == n:
        for i in range(n):
            if query(1, i) == n:
                answer(i)
                break
    else:
        idx = vals.index(n)
        to_query = idx - 1 if idx else idx + 1
        for i in range(n):
            if query(i, to_query) == n:
                answer((idx - i) % n)
                break