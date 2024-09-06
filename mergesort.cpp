#include <bits/stdc++.h>
#include <chrono>
using namespace std;

void fastio(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(4);
}

void merge(vector<int>& vec, int izq, int med, int der){
    int t1 = med - izq + 1;
    int t2 = der - med;

    vector<int> I(t1), D(t2);

    for (int i = 0; i < t1; i++){
        I[i] = vec[izq+i];
    }
    for (int j = 0; j < t2; j++){
        D[j] = vec[med + 1 + j];
    }

    int i = 0, j = 0;
    int k = izq;

    while (i < t1 && j < t2){
        if (I[i] <= D[j]){
        vec[k] = I[i];
        i++;
	}
        else {
        vec[k] = D[j];
        j++;
	}
        k++;
    }
}

void mergeSort(vector<int>& vec, int izq, int der){
    if (izq >= der){
	return;
    }

    int med = izq + (der - izq) / 2;
    mergeSort(vec, izq, med);
    mergeSort(vec, med + 1, der);
    merge(vec, izq, med, der);
}

void tomar_tiempo(vector<int>& vec){
    int tam = vec.size();
    auto start = chrono::high_resolution_clock::now();
    mergeSort(vec, 0, tam - 1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << duration.count() << endl;
}

typedef long long ll;

int main(){
    fastio();
    vector<int> num_ord;
    vector<int> num_inv;
    vector<int> num_semi_ord;
    vector<int> num_des;

    // Pruebas ordenado
    ifstream arch_ord_10("ordenado_10.txt");
    if (!arch_ord_10) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }
    int n;
    arch_ord_10 >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        arch_ord_10 >> num;
        num_ord.push_back(num);
    }
    cout << "Tiempo ordenado 10" << endl;
    tomar_tiempo(num_ord);
    num_ord.clear();
    arch_ord_10.close();

    ifstream arch_ord_100("ordenado_100.txt");
    if (!arch_ord_100) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }
    n = 0;
    arch_ord_100 >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        arch_ord_100 >> num;
        num_ord.push_back(num);
    }
    cout << "Tiempo ordenado 100" << endl;
    tomar_tiempo(num_ord);  
    num_ord.clear();
    arch_ord_100.close();

    ifstream arch_ord_1000("ordenado_1000.txt");
    if (!arch_ord_1000) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }
    n = 0;
    arch_ord_1000 >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        arch_ord_1000 >> num;
        num_ord.push_back(num);
    }
    cout << "Tiempo ordenado 1000" << endl;
    tomar_tiempo(num_ord);
    num_ord.clear();
    arch_ord_1000.close();

    ifstream arch_ord_10000("ordenado_10000.txt");
    if (!arch_ord_10000) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }
    n = 0;
    arch_ord_10000 >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        arch_ord_10000 >> num;
        num_ord.push_back(num);
    }
    cout << "Tiempo ordenado 10000" << endl;
    tomar_tiempo(num_ord);
    num_ord.clear();
    arch_ord_10000.close();

    ifstream arch_ord_100000("ordenado_100000.txt");
    if (!arch_ord_100000) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }
    n = 0;
    arch_ord_100000 >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        arch_ord_100000 >> num;
        num_ord.push_back(num);
    }
    cout << "Tiempo ordenado 100000" << endl;
    tomar_tiempo(num_ord);
    num_ord.clear();
    arch_ord_100000.close();

    // Pruebas Semiordenado
    ifstream arch_semi_ord_10("semi_ordenado_10.txt");
    if (!arch_semi_ord_10) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }
    n = 0;
    arch_semi_ord_10 >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        arch_semi_ord_10 >> num;
        num_semi_ord.push_back(num);
    }
    cout << "Tiempo semi ordenado 10" << endl;
    tomar_tiempo(num_semi_ord);
    num_semi_ord.clear();
    arch_semi_ord_10.close();

    ifstream arch_semi_ord_100("semi_ordenado_100.txt");
    if (!arch_semi_ord_100) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }
    n = 0;
    arch_semi_ord_100 >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        arch_semi_ord_100 >> num;
        num_semi_ord.push_back(num);
    }
    cout << "Tiempo semi ordenado 100" << endl;
    tomar_tiempo(num_semi_ord);
    num_semi_ord.clear();
    arch_semi_ord_100.close();

    ifstream arch_semi_ord_1000("semi_ordenado_1000.txt");
    if (!arch_semi_ord_1000) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }
    n = 0;
    arch_semi_ord_1000 >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        arch_semi_ord_1000 >> num;
        num_semi_ord.push_back(num);
    }
    cout << "Tiempo semi ordenado 1000" << endl;
    tomar_tiempo(num_semi_ord);
    num_semi_ord.clear();
    arch_semi_ord_1000.close();

    ifstream arch_semi_ord_10000("semi_ordenado_10000.txt");
    if (!arch_semi_ord_10000) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }
    n = 0;
    arch_semi_ord_10000 >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        arch_semi_ord_10000 >> num;
        num_semi_ord.push_back(num);
    }
    cout << "Tiempo semi ordenado 10000" << endl;
    tomar_tiempo(num_semi_ord);
    num_semi_ord.clear();
    arch_semi_ord_10000.close();

    ifstream arch_semi_ord_100000("semi_ordenado_100000.txt");
    if (!arch_semi_ord_100000) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }
    n = 0;
    arch_semi_ord_100000 >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        arch_semi_ord_100000 >> num;
        num_semi_ord.push_back(num);
    }
    cout << "Tiempo semi ordenado 100000" << endl;
    tomar_tiempo(num_semi_ord);
    num_semi_ord.clear();
    arch_semi_ord_100000.close();

    // Pruebas Desordenado
    ifstream arch_des_10("desordenado_10.txt");
    if (!arch_des_10) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }
    n = 0;
    arch_des_10 >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        arch_des_10 >> num;
        num_des.push_back(num);
    }
    cout << "Tiempo desordenado 10" << endl;
    tomar_tiempo(num_des);
    num_des.clear();
    arch_des_10.close();

    ifstream arch_des_100("desordenado_100.txt");
    if (!arch_des_100) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }
    n = 0;
    arch_des_100 >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        arch_des_100 >> num;
        num_des.push_back(num);
    }
    cout << "Tiempo desordenado 100" << endl;
    tomar_tiempo(num_des);
    num_des.clear();
    arch_des_100.close();

    ifstream arch_des_1000("desordenado_1000.txt");
    if (!arch_des_1000) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }
    n = 0;
    arch_des_1000 >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        arch_des_1000 >> num;
        num_des.push_back(num);
    }
    cout << "Tiempo desordenado 1000" << endl;
    tomar_tiempo(num_des);
    num_des.clear();
    arch_des_1000.close();

    ifstream arch_des_10000("desordenado_10000.txt");
    if (!arch_des_10000) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }
    n = 0;
    arch_des_10000 >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        arch_des_10000 >> num;
        num_des.push_back(num);
    }
    cout << "Tiempo desordenado 10000" << endl;
    tomar_tiempo(num_des);
    num_des.clear();
    arch_des_10000.close();

    ifstream arch_des_100000("desordenado_100000.txt");
    if (!arch_des_100000) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }
    n = 0;
    arch_des_100000 >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        arch_des_100000 >> num;
        num_des.push_back(num);
    }
    cout << "Tiempo desordenado 100000" << endl;
    tomar_tiempo(num_des);
    num_des.clear();
    arch_des_100000.close();
    return 0;
}