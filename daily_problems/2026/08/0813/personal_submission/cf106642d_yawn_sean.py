# Submission link: https://codeforces.com/gym/106642/submission/386683787
def main():
    a, b = MII()
    a += 1
    
    ans = []
    while b:
        ans.append(b % a)
        b //= a
    
    print(len(ans))
    print(' '.join(map(str, ans)))