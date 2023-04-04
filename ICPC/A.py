def dfs(persona, grafo, visitados, camino, perdedores):
    visitados.add(persona)
    camino.append(persona)

    for vecino in grafo[persona]:
        if vecino not in visitados:
            dfs(vecino, grafo, visitados, camino, perdedores)
        elif vecino in camino:
            # Encontramos un ciclo, marcamos todos los nodos en el camino como perdedores
            for p in camino[camino.index(vecino):]:
                perdedores.add(p)

    camino.pop()

n = int(input())
grafo = {i: [] for i in range(1, n+1)}
for i in range(1, n+1):
    x, y = map(int, input().split())
    grafo[x].append(i)
    grafo[y].append(i)

perdedores = set()
for persona in range(1, n+1):
    if persona not in perdedores:
        visitados = set()
        camino = []
        dfs(persona, grafo, visitados, camino, perdedores)

print(''.join(['Y' if i in perdedores else 'N' for i in range(1, n+1)]))

