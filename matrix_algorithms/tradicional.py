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

def multiplicar_matrices_tradicional(A, B, C):
    filasA = len(A)
    columnasA = len(A[0])
    columnasB = len(B[0])

    for i in range(filasA):
        for j in range(columnasB):
            C[i][j] = 0
            for k in range(columnasA):
                C[i][j] += A[i][k] * B[k][j]

def main():
    A,B = leer_matrices_desde_archivo("entrada.txt")
    filasA = len(A)
    columnasB = len(B[0])
    # Inicializar la matriz C con ceros
    C = [[0 for _ in range(columnasB)] for _ in range(filasA)]

    # Definir una función wrapper para llamar a multiplicar_matrices_tradicional con argumentos
    def wrapper():
        multiplicar_matrices_tradicional(A, B, C)

    # Medir el tiempo de ejecución
    t_total = timeit.timeit(wrapper, number=1)
    # Imprimir el tiempo total en segundos
    print(f"Tiempo total: {t_total:.6f} segundos")

if __name__ == "__main__":
    main()