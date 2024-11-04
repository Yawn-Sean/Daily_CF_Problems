def cz(X1, Y1, X2, Y2, X0, Y0):
    if X1 == X2:
        return (X1, Y0)
    if Y1 == Y2:
        return (X0, Y1)
    
    k = (Y2 - Y1) / (X2 - X1)
    k0 = -1 / k
    b = Y1 - k * X1
    b0 = Y0 - k0 * X0
    
    x = (b0 - b) / (k - k0)
    y = (b0 - b) / (k - k0) * k0 + b0
    return (x, y)

def dis(X1, Y1, X2, Y2):
    return (X1 - X2) ** 2 + (Y1 - Y2) ** 2

n, X0, Y0 = map(int, input().split())
x = [0] * (n + 1)
y = [0] * (n + 1)

for i in range(1, n + 1):
    x[i], y[i] = map(float, input().split())

Min = float('inf')
Max = 0

for i in range(1, n + 1):
    Min = min(Min, dis(X0, Y0, x[i], y[i]))
    Max = max(Max, dis(X0, Y0, x[i], y[i]))

for i in range(1, n + 1):
    pre = n if i == 1 else i - 1
    point = cz(x[pre], y[pre], x[i], y[i], X0, Y0)
    
    if point[0] < min(x[pre], x[i]) or point[0] > max(x[pre], x[i]):
        continue
    if point[1] < min(y[pre], y[i]) or point[1] > max(y[pre], y[i]):
        continue
    
    Min = min(Min, dis(X0, Y0, point[0], point[1]))
    Max = max(Max, dis(X0, Y0, point[0], point[1]))

result = (Max - Min) * math.pi
print(f"{result:.10f}")
