class Solution():
    
    def maxCoins(self, N, a):
        # Se define la constante MAX_N que es igual a N+2
        MAX_N = N + 2
        # Se crea una matriz de dimensiones MAX_N x MAX_N y se inicializa en cero.
        dp = [[0] * MAX_N for _ in range(MAX_N)]
        a.insert(0, 1)
        a.append(1)
        
        # Se recorren las subsecuencias de la lista a, desde las de longitud 0 hasta las de longitud N-1.
        for longitud in range(0, N - 1 + 1):
            for inicio in range(1, N - longitud + 1):
                fin = inicio + longitud
                maxima_ganancia = 0
                # Se recorre la subsecuencia actual y se calcula la ganancia máxima
                for i in range(inicio, fin + 1):
                    ganancia = (
                        dp[inicio][i - 1]
                        + a[inicio - 1] * a[i] * a[fin + 1]
                        + dp[i + 1][fin]
                    )
                    maxima_ganancia = max(maxima_ganancia, ganancia)
                dp[inicio][fin] = maxima_ganancia

        # Se retorna el valor almacenado en la posición (1, N) de la matriz dp.
        return dp[1][N]

if __name__ == "__main__":
    for _ in range(int(input())):
        n = int(input())
        a = [int(i) for i in input().split()]
        print(Solution().maxCoins(N=n,a=a))