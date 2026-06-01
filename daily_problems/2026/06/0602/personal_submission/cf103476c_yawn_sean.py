# Submission link: https://codeforces.com/gym/103476/submission/376889113
def main():
    n = II()
    d = Counter()
    
    for i in range(2, 100000):
        while n % i == 0:
            n //= i
            d[i] += 1
        
        if i * i > n: break
    
    if n > 1: d[n] += 1
    
    items = list(d.items())
    items.sort(key=lambda x: (x[1] + 1) % 2)
    
    if len(items) == 1:
        print(2)
        print(1, items[0][0])
    else:
        if items[0][1] % 2:
            x1, y1 = items[0]
            x2, y2 = items[1]
            
            ans = [1, x2]
            for i in range(y1 + 1):
                for j in range(y2 - 1):
                    if i % 2 == 0: ans.append(ans[-1] * x2)
                    else: ans.append(ans[-1] // x2)
                if i < y1:
                    ans.append(ans[-1] * x1)
            
            ans.append(ans[-1] // x2)
            
            for i in range(y1 - 1):
                ans.append(ans[-1] // x1)
            
            for i in range(2, len(items)):
                x, y = items[i]
                
                nans = []
                
                for j in range(len(ans)):
                    tmp = [ans[j]]
                    for _ in range(y):
                        tmp.append(tmp[-1] * x)
                    
                    if j % 2:
                        tmp.reverse()
    
                    nans.extend(tmp)
                
                ans = nans
            
            print(len(ans))
            print(' '.join(map(str, ans)))
        
        else:
            x1, y1 = items[0]
            x2, y2 = items[1]
            
            ans = [x2]
            
            for _ in range(y1 // 2):
                ans.append(ans[-1] * x1)
                ans.append(ans[-1] // x2)
                ans.append(ans[-1] * x1)
                ans.append(ans[-1] * x2)
            
            ans.append(ans[-1] * x2)
            
            for _ in range(y2 // 2 - 1):
                
                for _ in range(y1 - 1):
                    ans.append(ans[-1] // x1)
                
                ans.append(ans[-1] * x2)
                
                for _ in range(y1 - 1):
                    ans.append(ans[-1] * x1)
                
                ans.append(ans[-1] * x2)
            
            for _ in range(y1):
                ans.append(ans[-1] // x1)
            
            for _ in range(y2 - 2):
                ans.append(ans[-1] // x2)
            
            for i in range(2, len(items)):
                x, y = items[i]
                
                nans = []
                
                for j in range(len(ans)):
                    tmp = [ans[j]]
                    
                    for idx in range(y):
                        tmp.append(tmp[-1] * x)
                        
                        if j == 0:
                            if idx % 2 == 0:
                                tmp.append(tmp[-1] // x2)
                            else:
                                tmp.append(tmp[-1] * x2)
                    
                    if j % 2: tmp.reverse()
                    nans.extend(tmp)
                
                ans = nans
            
            print(len(ans))
            print(' '.join(map(str, ans)))