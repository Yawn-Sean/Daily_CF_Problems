'''
https://codeforces.com/gym/105271/submission/341428098
'''
def query(i: int, x: int) -> int:
    print(f"? {i + 1} {x}", flush=True)
    c = input()
    return -1 if c == '<' else 1 if c == '>' else 0

def solve(n: int):
    ans = [0] * n
    x = 1
    for i in range(n):
        while True:
            r = query(i, x)
            if r < 0:
                x += 1
            elif r > 0:
                x -= 1
            else:
                ans[i] = x
                break
    return ans
