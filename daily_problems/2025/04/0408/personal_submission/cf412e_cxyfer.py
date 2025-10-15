from itertools import pairwise

"""
{pre}@{domain}.{tld}
"""

def check1(ch):
    return 'a' <= ch <= 'z' or '0' <= ch <= '9' or ch == '_'

def check2(ch):
    return 'a' <= ch <= 'z' or '0' <= ch <= '9'

s = input()

ans = 0
for pre, suf in pairwise(s.split('@')):
    cnt_l = cnt_r = 0
    for ch in pre[::-1]:
        if not check1(ch):
            break
        cnt_l += ch.isalpha()

    splits = suf.split('.')
    if len(splits) < 2:
        continue

    domain, tld = splits[0], splits[1]
    if any(not check2(ch) for ch in domain) or len(domain) == 0 or len(tld) == 0:
        continue

    for ch in tld:
        if not ch.isalpha():
            break
        cnt_r += ch.isalpha()
    
    ans += cnt_l * cnt_r

print(ans)
