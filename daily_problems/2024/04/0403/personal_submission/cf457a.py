s1 = I()
s2 = I()
def cal(s):
    # (aq + b + c) * q = aq^2 + (b+c)q = (a+b+c)q + a
    a = b = 0
    for c in s:        
        b += int(c)
        ta = a
        a += b
        b = ta
    return a , b
# a >= b
# a1 - a2 >= a2 , b1 - b2 < a2
a1 , b1 = cal(s1)
a2, b2 = cal(s2)
if a1 == a2:
    print("=" if b1 == b2 else ">" if b1 > b2 else "<")
else:
    print(">" if a1 > a2 else "<")
