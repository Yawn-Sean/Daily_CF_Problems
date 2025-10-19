# Submission link: https://codeforces.com/gym/103886/submission/344617075
def main(): 
    def solve(x):
        if x == 1: return [1]
        even = x // 2
        odd = x - x // 2
        return [x * 2 for x in solve(even)] + [x * 2 - 1 for x in solve(odd)]
    
    n = II()
    print(*solve(n))