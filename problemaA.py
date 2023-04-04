n, q = map(int,input().split())
a = list(map(int,input().split()))
# lista de consultas
dp = []
# leemos las consultas 
for _ in range(q):
    k = int(input())
    dp = dp + [k]
# rellenar la tabla para atomos con numero de neutrones mayor que n
for k in range(len(a)+1,max(dp)+1):
    m = k//2
    min = float("inf")
    for i in range(1,m+1):
        j = k-i
        if a[i-1] + a[j-1] < min:
            min = a[i-1] + a[j-1]
    a = a + [min]
# imprimimos las consultas    
for k in dp:
    print(a[k-1])