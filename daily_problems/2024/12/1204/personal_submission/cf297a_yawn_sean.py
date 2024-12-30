# Submission link: https://codeforces.com/contest/297/submission/294699004
def main():
    c1 = I().count('1')
    c2 = I().count('1')
    print('YES' if c1 >= c2 or (c1 % 2 and c1 + 1 == c2) else 'NO')