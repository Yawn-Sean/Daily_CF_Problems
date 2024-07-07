def solve(testcase):
    n, m = MI()
    
    cure, curo = 2, 1
    
    res = []
    
    for i in range(n):
        tmp = [curo, curo + 2, curo + 4]
        curo += 6
        
        while True:
            flag = True
            for val in tmp:
                if gcd(val, cure) != 1:
                    flag = False
                    break
            if flag:
                break
            else:
                cure += 2
        
        tmp.append(cure)
        cure += 2
        
        res.append(tmp)
    
    curo -= 2
    cure -= 2
    cur = max(curo, cure)
    print(cur * m)
    for a, b, c, d in res:
        print(a * m, b * m, c * m, d * m)
    

for testcase in range(1):
    solve(testcase)
