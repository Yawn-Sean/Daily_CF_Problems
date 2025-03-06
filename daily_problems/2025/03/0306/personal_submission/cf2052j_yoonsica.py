from math import inf

x = 1

for _ in range(200000):
    print(x * 10)
    x = x * 10
    
print(x)