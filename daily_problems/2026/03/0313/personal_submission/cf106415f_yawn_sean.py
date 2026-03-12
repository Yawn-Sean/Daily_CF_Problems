# Submission link: https://codeforces.com/gym/106415/submission/366378419
def main(): 
    def query(a, b):
        print('?', a, b, flush=True)
        return int(LI()[1])
    
    def answer(x):
        print('!', x, flush=True)
        return I()
    
    def solve(x):
        if x & -x == x:
            return query(x, x) // 2
        v = 1 << x.bit_length()
        return query(v - x, x) - solve(v - x)
    
    n = II()
    nums = LII()
    
    for x in nums:
        answer(solve(x))