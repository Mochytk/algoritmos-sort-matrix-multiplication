def multiplicacion_tradicional(A, B, C):
    d = len(A)
    for i in range(d):
        for j in range(d):
            for k in range(d):
                C[i][j] += A[i][k] * B[k][j]

def dividir_matriz(A, row, col, d):
    return [row[col:col + d] for row in A[row:row + d]]

def unir_matrices(A, B, row, col, d):
    for i in range(d):
        for j in range(d):
            B[row + i][col + j] = A[i][j]

def sumar_matrices(A, B, C):
    d = len(A)
    for i in range(d):
        for j in range(d):
            C[i][j] = A[i][j] + B[i][j]

def restar_matrices(A, B, C):
    d = len(A)
    for i in range(d):
        for j in range(d):
            C[i][j] = A[i][j] - B[i][j]

def strassen(A, B, C, d, crossover):
    # Si la dimensión no es divisible por dos, ajusta las matrices para que lo sea
    if d % 2 != 0:
        d += 1
        A = [row + [0] * (d - len(row)) for row in A] + [[0] * d for _ in range(d - len(A))]
        B = [row + [0] * (d - len(row)) for row in B] + [[0] * d for _ in range(d - len(B))]
        C = [[0] * d for _ in range(d)]

    # Si la dimensión es menor o igual al punto de cruce, utiliza la multiplicación tradicional
    if d <= crossover:
        multiplicacion_tradicional(A, B, C)
        return
    else:
        new_d = d // 2
        A11 = dividir_matriz(A, 0, 0, new_d)
        A12 = dividir_matriz(A, 0, new_d, new_d)
        A21 = dividir_matriz(A, new_d, 0, new_d)
        A22 = dividir_matriz(A, new_d, new_d, new_d)
        B11 = dividir_matriz(B, 0, 0, new_d)
        B12 = dividir_matriz(B, 0, new_d, new_d)
        B21 = dividir_matriz(B, new_d, 0, new_d)
        B22 = dividir_matriz(B, new_d, new_d, new_d)

        M1 = [[0] * new_d for _ in range(new_d)]
        M2 = [[0] * new_d for _ in range(new_d)]
        M3 = [[0] * new_d for _ in range(new_d)]
        M4 = [[0] * new_d for _ in range(new_d)]
        M5 = [[0] * new_d for _ in range(new_d)]
        M6 = [[0] * new_d for _ in range(new_d)]
        M7 = [[0] * new_d for _ in range(new_d)]

        temp1 = [[0] * new_d for _ in range(new_d)]
        temp2 = [[0] * new_d for _ in range(new_d)]

        # M1 = (A11 + A22)(B11 + B22)
        sumar_matrices(A11, A22, temp1)
        sumar_matrices(B11, B22, temp2)
        strassen(temp1, temp2, M1, new_d, crossover)

        # M2 = (A21 + A22) B11
        sumar_matrices(A21, A22, temp1)
        strassen(temp1, B11, M2, new_d, crossover)

        # M3 = A11 (B12 - B22)
        restar_matrices(B12, B22, temp2)
        strassen(A11, temp2, M3, new_d, crossover)

        # M4 = A22 (B21 - B11)
        restar_matrices(B21, B11, temp2)
        strassen(A22, temp2, M4, new_d, crossover)

        # M5 = (A11 + A12) B22
        sumar_matrices(A11, A12, temp1)
        strassen(temp1, B22, M5, new_d, crossover)

        # M6 = (A21 - A11) (B11 + B12)
        restar_matrices(A21, A11, temp1)
        sumar_matrices(B11, B12, temp2)
        strassen(temp1, temp2, M6, new_d, crossover)

        # M7 = (A12 - A22) (B21 + B22)
        restar_matrices(A12, A22, temp1)
        sumar_matrices(B21, B22, temp2)
        strassen(temp1, temp2, M7, new_d, crossover)

        # Calcula las submatrices C11, C12, C21 y C22
        C11 = [[0] * new_d for _ in range(new_d)]
        C12 = [[0] * new_d for _ in range(new_d)]
        C21 = [[0] * new_d for _ in range(new_d)]
        C22 = [[0] * new_d for _ in range(new_d)]

        # C11 = M1 + M4 - M5 + M7
        sumar_matrices(M1, M4, temp1)
        sumar_matrices(temp1, M7, temp2)
        restar_matrices(temp2, M5, C11)

        # C12 = M3 + M5
        sumar_matrices(M3, M5, C12)

        # C21 = M2 + M4
        sumar_matrices(M2, M4, C21)

        # C22 = M1 - M2 + M3 + M6
        restar_matrices(M1, M2, temp1)
        sumar_matrices(M3, M6, temp2)
        sumar_matrices(temp1, temp2, C22)

        # Junta las submatrices C11, C12, C21 y C22 en la matriz resultante C
        unir_matrices(C11, C, 0, 0, new_d)
        unir_matrices(C12, C, 0, new_d, new_d)
        unir_matrices(C21, C, new_d, 0, new_d)
        unir_matrices(C22, C, new_d, new_d, new_d)

def main():
    global dim, crossover
    
    # Leer los valores de entrada (dimensión y crossover)
    with open('input.txt', 'r') as f:
        dim, crossover = map(int, f.readline().split())

    A = np.zeros((dim, dim), dtype=int)
    B = np.zeros((dim, dim), dtype=int)
    C = np.zeros((dim, dim), dtype=int)

    # Leer matriz A
    for i in range(dim):
        A[i] = list(map(int, f.readline().split()))

    # Leer matriz B
    for i in range(dim):
        B[i] = list(map(int, f.readline().split()))

    # Selección de algoritmo
    if dim <= crossover:
        multiplicacion_tradicional(A, B, C, dim)
    else:
        C = strassen(A, B, C, dim)

    # Escribir la diagonal de la matriz C en el archivo de salida
    with open('output.txt', 'w') as f:
        for i in range(dim):
            f.write(str(C[i][i]) + '\n')

if __name__ == "__main__":
    main()