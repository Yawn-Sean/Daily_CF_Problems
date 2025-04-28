# Submission link: https://codeforces.com/problemset/submission/845/317522422#
def main():
    t = II()

    ans = 0

    speed_limit = []
    speed = 0

    forbidden_overtake = 0

    for _ in range(t):
        query = LII()
        
        if query[0] == 1:
            speed = query[1]
            
            while speed_limit and speed_limit[-1] < speed:
                ans += 1
                speed_limit.pop()

        elif query[0] == 2:
            ans += forbidden_overtake
            forbidden_overtake = 0

        elif query[0] == 3:
            if query[1] < speed: ans += 1
            else: speed_limit.append(query[1])
        
        elif query[0] == 4:
            forbidden_overtake = 0
        
        elif query[0] == 5:
            speed_limit.clear()
        
        else:
            forbidden_overtake += 1

    print(ans)