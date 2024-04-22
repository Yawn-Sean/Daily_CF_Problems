oper = list(input().replace('()', '0').replace('->', '+'))
order = []
left = []
for i in oper:
    if i == '(':
        left.append(0)
    elif i == '+':
        left.append(1)
    elif i == '0':
        order.append(0)
    else:
        while left.pop():
            a, b = order.pop(), order.pop()
            order.append(max(a, b+1))

while left:
    a, b = order.pop(), order.pop()
    order.append(max(a, b+1))
    left.pop()
print(order[0])
