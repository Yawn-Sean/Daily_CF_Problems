# Submission link: https://codeforces.com/gym/106642/submission/386683934
def main():
    n = II()
    rs = LII()
    
    if 0 not in rs or 2 not in rs: print('NO')
    else:
        for i in range(n):
            if rs[i] == rs[i - 1] != 1:
                print('NO')
                break
        else:
            print('YES')