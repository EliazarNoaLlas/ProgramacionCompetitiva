A = [6, 3, -2, 4, -1, 0,-5]
suma = 0
# Construllendo la matriz d esufijos
sufixMatriz = [A[0]]*len(A)
for i in range(1,len(A)):
    sufixMatriz[i]= sufixMatriz[i-1]+A[i]
#Consultas
n = int(input())
for c in range(n):
    i, j = map(int, input().split())
    if i==0:
        print(sufixMatriz[j])
    else:
        print(sufixMatriz[j]-sufixMatriz[i-1])