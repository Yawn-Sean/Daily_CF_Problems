# Submission link: https://codeforces.com/contest/786/submission/331440514
def main():
    n = II()
    k1, *s1 = MII()
    k2, *s2 = MII()
    
    dp = [[0] * n for _ in range(2)]
    cnt = [[0] * n for _ in range(2)]
    
    def f(person, pos):
        return person * n + pos
    
    dp[0][0] = 2
    dp[1][0] = 2
    
    stk = []
    stk.append(f(0, 0))
    stk.append(f(1, 0))
    
    while stk:
        person, pos = divmod(stk.pop(), n)
        
        if person:
            for step in s1:
                last_pos = (pos - step) % n
                if dp[0][last_pos] == 0:
                    if dp[person][pos] == 2:
                        dp[0][last_pos] = 1
                        stk.append(f(0, last_pos))
                    else:
                        cnt[0][last_pos] += 1
                        if cnt[0][last_pos] == k1:
                            dp[0][last_pos] = 2
                            stk.append(f(0, last_pos))
        else:
            for step in s2:
                last_pos = (pos - step) % n
                if dp[1][last_pos] == 0:
                    if dp[person][pos] == 2:
                        dp[1][last_pos] = 1
                        stk.append(f(1, last_pos))
                    else:
                        cnt[1][last_pos] += 1
                        if cnt[1][last_pos] == k2:
                            dp[1][last_pos] = 2
                            stk.append(f(1, last_pos))
    
    strs = ['Loop', 'Win', 'Lose']
    print(' '.join(strs[dp[0][i]] for i in range(1, n)))
    print(' '.join(strs[dp[1][i]] for i in range(1, n)))