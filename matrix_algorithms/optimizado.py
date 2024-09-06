import timeit
def leer_matrices_desde_archivo(nombre_archivo):
    with open(nombre_archivo, 'r') as archivo:
        # Leer dimensiones de la Matriz A
        filasA, columnasA = map(int, archivo.readline().strip().split())
        
        # Leer Matriz A
        matrizA = []
        for _ in range(filasA):
            fila = list(map(int, archivo.readline().strip().split()))
            matrizA.append(fila)
        
        # Leer línea en blanco entre matrices
        archivo.readline()
        
        # Leer dimensiones de la Matriz B
        filasB, columnasB = map(int, archivo.readline().strip().split())
        
        # Leer Matriz B
        matrizB = []
        for _ in range(filasB):
            fila = list(map(int, archivo.readline().strip().split()))
            matrizB.append(fila)
    
    return matrizA, matrizB

def transponer(matriz):
    filas = len(matriz)
    columnas = len(matriz[0])
    mat_transpuesto = [[0 for _ in range(filas)] for _ in range(columnas)]

    for i in range(filas):
        for j in range(columnas):
            mat_transpuesto[j][i] = matriz[i][j]

    return mat_transpuesto

def multiplicar_matrices_opti(A, B, C):
    filasA = len(A)
    columnasA = len(A[0])
    columnasB = len(B[0])

    B_t = transponer(B)

    for i in range(filasA):
        for j in range(columnasB):
            C[i][j] = 0
            for k in range(columnasA):
                C[i][j] += A[i][k] * B_t[j][k]

def main():
    A,B = leer_matrices_desde_archivo("entrada.txt")
    filasA = len(A)
    columnasB = len(B[0])
    C = [[0 for _ in range(columnasB)] for _ in range(filasA)]
    def wrapper():
        multiplicar_matrices_opti(A, B, C)
    multiplicar_matrices_opti(A, B, C)
    t_total = timeit.timeit(wrapper, number=1)
    
    print(t_total)

if __name__ == "__main__":
    main()