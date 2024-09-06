import random

def gen_ordenado(tamaño, nombre_archivo):
    arreglo = list(range(1, tamaño + 1))
    with open(nombre_archivo, 'w') as f:
        f.write(" ".join(map(str, arreglo)))

def gen_ordenado_inv(tamaño, nombre_archivo):
    arreglo = list(range(tamaño, 0, -1))
    with open(nombre_archivo, 'w') as f:
        f.write(" ".join(map(str, arreglo)))

def gen_semi_ordenado(tamaño, nombre_archivo):
    mitad = tamaño // 2
    primera_mitad = list(range(1, mitad + 1))
    segunda_mitad = random.sample(range(mitad + 1, tamaño + 1), tamaño - mitad)
    arreglo = primera_mitad + segunda_mitad
    with open(nombre_archivo, 'w') as f:
        f.write(" ".join(map(str, arreglo)))

def gen_desordenado(tamaño, nombre_archivo):
    arreglo = random.sample(range(1, tamaño + 1), tamaño)
    with open(nombre_archivo, 'w') as f:
        f.write(" ".join(map(str, arreglo)))

# Ordenados
gen_ordenado(10, 'ordenado_10.txt')
gen_ordenado(100, 'ordenado_100.txt')
gen_ordenado(1000, 'ordenado_1000.txt')
gen_ordenado(10000, 'ordenado_10000.txt')
gen_ordenado(100000, 'ordenado_100000.txt')

# Semi-ordenados (primera mitad ordenada)
gen_semi_ordenado(10, 'semi_ordenado_10.txt')
gen_semi_ordenado(100, 'semi_ordenado_100.txt')
gen_semi_ordenado(1000, 'semi_ordenado_1000.txt')
gen_semi_ordenado(10000, 'semi_ordenado_10000.txt')
gen_semi_ordenado(100000, 'semi_ordenado_100000.txt')

# Desordenados
gen_desordenado(10, 'desordenado_10.txt')
gen_desordenado(100, 'desordenado_100.txt')
gen_desordenado(1000, 'desordenado_1000.txt')
gen_desordenado(10000, 'desordenado_10000.txt')
gen_desordenado(100000, 'desordenado_100000.txt')