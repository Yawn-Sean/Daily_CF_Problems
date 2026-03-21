# Submission link: https://codeforces.com/gym/106433/submission/367356248
def main(): 
    n, k = MII()
    
    vals = []
    weights = []
    
    for _ in range(n):
        v, w = MII()
        vals.append(v)
        weights.append(w)
    
    st_range = sorted(range(n), key=lambda x: vals[x])
    
    acc_total = [0]
    acc_weights = [0]
    
    for i in st_range:
        v = vals[i]
        w = weights[i]
        
        acc_total.append(acc_total[-1] + v * w)
        acc_weights.append(acc_weights[-1] + w)
    
    ans = acc_total[n] / acc_weights[n]
    
    while k:
        l, r = 0, n - 1
        while l <= r:
            mid = (l + r) // 2
            if vals[st_range[mid]] > ans: r = mid - 1
            else: l = mid + 1
        
        cur = l
        prob = acc_weights[cur] / acc_weights[n]
        to_add = (acc_total[n] - acc_total[cur]) / acc_weights[n]
        
        v = to_add / (1 - prob)
        
        l, r = 1, k
        while l <= r:
            mid = (l + r) // 2
            nans = pow(prob, mid) * (ans - v) + v
            if nans > vals[st_range[cur]]: r = mid - 1
            else: l = mid + 1
        
        cur = fmin(l, k)
        k -= cur
        ans = pow(prob, cur) * (ans - v) + v
    
    print(ans)