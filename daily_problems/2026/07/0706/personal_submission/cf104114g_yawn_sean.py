# Submission link: https://codeforces.com/gym/104114/submission/381336017
def main():
    n = II()
    xs = LII()
    rs = LII()
    
    v_pos = [0]
    v_neg = []
    
    for i in range(1, n):
        if i % 2: v_neg.append(xs[i] - xs[i - 1] - v_pos[-1])
        else: v_pos.append(xs[i] - xs[i - 1] - v_neg[-1])
    
    rs.sort()
    min_r = rs[0]
    
    def check(x):
        tmp = [x]
        for i in range(1, n):
            tmp.append(xs[i] - xs[i - 1] - tmp[-1])
        
        if sorted(tmp) == rs:
            exit(print(' '.join(map(str, tmp))))
    
    v_mi = min(v_pos)
    check(min_r - v_mi)
    
    v_mi = min(v_neg)
    check(v_mi - min_r)