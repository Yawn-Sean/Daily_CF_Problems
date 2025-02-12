'''
https://codeforces.com/problemset/submission/518/302821296
'''
# 直接构造s1的下一个字符串
def solve(s1: str, s2: str) -> str:
    a = [ord(c) - 97 for c in s1]
    for i in range(len(a) - 1, -1, -1):
        if a[i] == 25:
            a[i] = 0
        else:
            a[i] += 1
            break
    s3 = ''.join(chr(x + 97) for x in a)
    return s3 if s3 < s2 else "No such string"
