# Submission link: https://codeforces.com/gym/106511/submission/373413107
def main():
    n = II()
    ans = 0
    
    for i in range(10):
        cur = i if i else 10
        while cur <= n:
            ans += 1
            cur *= 10
            cur += i
    
    print(ans)