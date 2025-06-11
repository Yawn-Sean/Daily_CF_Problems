if __name__ == '__main__':
    n = int(input())
    actions = []
    ALL = 2 ** 26 - 1
    for i in range(n):
        action = input().split(" ")
        x = 0
        for ch in action[1]:
            x = x | (2 ** (ord(ch) - ord('a')))
        actions.append((action[0], x))
    
    ans = 0
    todo = ALL - actions[-1][1]
    for i in range(n - 1):
        if actions[i][0] == '!':
            if todo == 0:
                ans += 1
            todo = todo & (actions[i][1] - actions[-1][1])
        elif actions[i][0] == '.':
            todo = todo & (ALL - actions[i][1])
        else:
            if todo == 0:
                ans += 1
            todo = todo & (ALL - actions[i][1])
    
    print(ans)