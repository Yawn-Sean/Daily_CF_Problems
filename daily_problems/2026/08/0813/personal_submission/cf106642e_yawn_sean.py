# Submission link: https://codeforces.com/gym/106642/submission/386768065
def main():
    n = II()
    rs = LII()

    if 0 not in rs or 2 not in rs: print('NO')
    else:
        rs = [r for r in rs if r != 1]
        print('NO' if len(rs) % 2 or any(rs[i - 1] == rs[i] for i in range(1, len(rs))) else 'YES')