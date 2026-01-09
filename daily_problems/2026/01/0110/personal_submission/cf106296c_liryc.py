'''
Docstring for daily_problems.2026.01.0110.personal_submission.cf106296c_liryc
'''
# ref, binary search 
from bisect import bisect_left

def solve(n: int) -> list[int]:
    def ask(a, b):
        print(a, b, flush=True)
        return input()

    def check(m):
        return m and ask(2, (m << 1) - 1) != ask(1, m << 1)
    
    f = bisect_left(range(n + 3 >> 1), True, key=check)
    return [3, (f << 1) - 1, f << 1 | 1]

if __name__ == '__main__':
    for _ in range(int(input())):
        n = int(input())
        ans = solve(n)
        print(*ans, flush=True)