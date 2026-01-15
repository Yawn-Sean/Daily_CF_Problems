# Submission link: https://codeforces.com/gym/104149/submission/357915954
def main(): 
    a, b = map(float, input().split())
    
    v = 4 * b * b * math.sin(math.pi / 4)
    
    if a >= v: print(v)
    else:
        theta = math.asin(a / 4 / b / b) / 2
        w = b * math.sin(theta)
        print(w * w / math.tan(math.pi / 8) * 8)