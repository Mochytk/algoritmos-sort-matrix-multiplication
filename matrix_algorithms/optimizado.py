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
    A = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ]

    B = [
        [9, 8, 7],
        [6, 5, 4],
        [3, 2, 1]
    ]

    filasA = len(A)
    columnasB = len(B[0])
    C = [[0 for _ in range(columnasB)] for _ in range(filasA)]

    multiplicar_matrices_opti(A, B, C)

    print(C)

if __name__ == "__main__":
    main()