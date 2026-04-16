# Submission link: https://codeforces.com/gym/105501/submission/371337573
def main():
    def prep(p):
        pi = [0] * len(p)
        j = 0
        for i in range(1, len(p)):
            while j != 0 and p[j] != p[i]:
                j = pi[j - 1]
            if p[j] == p[i]:
                j += 1
            pi[i] = j
        return pi
    
    n, m = MII()
    nums = LII()
    
    for i in range(1, n + 1):
        if m in prep(LII() + [-1] + nums + nums):
            print(i)
            break
    else:
        print(-1)