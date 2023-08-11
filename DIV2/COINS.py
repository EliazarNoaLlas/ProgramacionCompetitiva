def Coins(n, k):
    x = 0
    while 2*x<=n:
        y = 0
        while 2*x + k*y <= n:
            #print(x,y)
            #print(2*x + k*y)
            if 2*x + k*y == n:
                return True
            y+=1
        x+=1
    return False

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    if Coins(n, k): 
        print("YES")
    else:
         print("NO")
    