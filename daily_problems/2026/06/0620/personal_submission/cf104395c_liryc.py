'''
https://codeforces.com/gym/104395/submission/379595970
string sorting
'''
def solve(n: int, k: int, s: str) -> str:
    a = [s[0]]
    for i in range(1, n, 2):
        a.append(s[i:i + 2])
    ans = ''.join(w * k for w in sorted(a))

    a = []
    for i in range(0, n, 2):
        a.append(s[i:i + 2])
    ans = min(ans, ''.join(w * k for w in sorted(a)))
    
    return ans
