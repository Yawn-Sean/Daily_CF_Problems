'''
https://codeforces.com/gym/104013/submission/362843052
'''
def query(i, j):
    print(i, j, flush=True)
    return input()

def solve(n: int) -> None: 
    for _ in range(n):
        for i in range(1, n):
            if query(i, i + 1) == 'WIN':
                return
        for i in range(n - 1, 0, -1):
            if query(i, i + 1) == 'WIN':
                return
