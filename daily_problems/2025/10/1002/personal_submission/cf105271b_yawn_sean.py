# Submission link: https://codeforces.com/gym/105271/submission/341263231
def main():
    def query(i, x):
        print('?', i + 1, x, flush=True)
        c = I()
        return 1 if c == '<' else 0
    
    def answer(ans):
        print('!', *ans)
    
    n = II()
    ans = [0] * n
    
    cur = 1
    for i in range(n):
        while query(i, cur):
            cur += 1
        ans[i] = cur
    
    answer(ans)