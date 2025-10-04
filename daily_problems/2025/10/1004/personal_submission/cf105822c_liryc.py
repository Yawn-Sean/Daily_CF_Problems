'''
https://codeforces.com/gym/105822/submission/341825607
'''
def solve(n: int, s: str) -> list[str]:
    ans = []
    if (n & 1) == (s.count('O') & 1):
        ans.append("YES")
        odd, even = 1, 2
        for c in s:
            if c == 'O':
                ans.append(f"{odd} {even}")
                odd += 2
                even += 2
            elif odd < even:
                ans.append(f"{odd} {odd + 2}")
                odd += 4
            else:
                ans.append(f"{even} {even + 2}")
                even += 4
    else:
        ans.append("NO")
    return ans
