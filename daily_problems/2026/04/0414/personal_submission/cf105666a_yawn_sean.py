# Submission link: https://codeforces.com/gym/105666/submission/370923005
def main(): 
    possible_vals = [1]
    bound = II()
    
    for x in [2, 3, 5, 7]:
        for i in range(len(possible_vals)):
            cur = possible_vals[i]
            while cur * x <= bound:
                cur *= x
                possible_vals.append(cur)
    
    k = len(possible_vals)
    d = {v: i for i, v in enumerate(possible_vals)}
    
    dp = [0] * k
    dp[0] = 1
    
    for i in range(k):
        if dp[i]:
            for x in range(2, 10):
                if possible_vals[i] * x <= bound and str(x) in str(possible_vals[i] * x):
                    dp[d[possible_vals[i] * x]] = 1
    
    print(sum(dp))