# Submission link: https://codeforces.com/gym/106782/submission/395954205
def main():
    n = II()
    
    def solve(n):
        if n == 0: return []
        tmp = [x + 1 for x in solve(n - 1)] + [1]
        return tmp * 2
    
    ans = solve(n)
    
    print(len(ans))
    print(' '.join(map(str, ans)))