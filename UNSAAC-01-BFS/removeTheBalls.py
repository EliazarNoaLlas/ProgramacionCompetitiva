from typing import List

class Solution:
    def finLength(self, N: int, color: List[int], radius: List[int]) -> int:
        balls = [] # Lista para representar el arreglo imaginario
        
        for i in range(N):
            print(i, balls)
            # Si la lista de bolas no está vacía y la bola actual tiene el mismo color y tamaño que la última bola en la lista,
            # eliminamos ambas bolas de la lista
            if balls and balls[-1][0] == color[i] and balls[-1][1] == radius[i]:
                balls.pop()
                continue
            
            # Agregamos la bola actual a la lista de bolas
            balls.append((color[i], radius[i]))
        
        # El tamaño final del arreglo imaginario es la longitud de la lista de bolas
        return len(balls)

if __name__ == "__main__":
    # Ejemplo de uso
    obj = Solution()
    N = 4
    color = [1, 3, 3, 1]
    radius = [2, 5, 5, 2]
    result = obj.finLength(N, color, radius)
    print(result)
