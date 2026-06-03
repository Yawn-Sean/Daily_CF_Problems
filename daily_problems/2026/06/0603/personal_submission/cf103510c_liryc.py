'''
https://codeforces.com/gym/103150/submission/377072405
string
'''
def solve(s: str) -> bool:
    s = ''.join(c for c in s if c in "ezpc")
    return s in ["ezpc", "zepc", "zpec"]
