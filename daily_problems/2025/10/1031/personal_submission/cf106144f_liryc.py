'''
https://codeforces.com/gym/106144/submission/346767200
'''
def solve(n: int, sa: list[str]) -> str: 
    c3, c2 = 0, 0
    for s in sa:
        if s == "===xxx" or s == "xxx===":
            c3 ^= 1
        elif s == "xx.===" or s == "===.xx" or s == ".xx===" or s == "===xx.":
            c2 ^= 1
    return "Monocarp" if c3 or c2 else "Polycarp"
