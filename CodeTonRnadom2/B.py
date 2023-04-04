t= int(input())
for i in range(t):
    n = int(input())
    if (n%2 == 0):
        print(-1)
        continue
    ans = []
    cont =  0
    n //= 2
    while(n):
        cont +=1
        if(n%2 == 1):
            ans.append(2)
        else:
            ans.append(1)
        n//=2
    if(cont>40):
        print(-1)
        continue
    print(cont)
    print(str(ans[::-1])[1:-1].replace(","," "))