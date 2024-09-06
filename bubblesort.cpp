#include <bits/stdc++.h>
#include <chrono>
using namespace std;

void fastio(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(4);
}
void bubblesort(vector<int>& vec){
    int n = vec.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void tomar_tiempo(vector<int>& vec){
    auto start = chrono::high_resolution_clock::now();
    bubblesort(vec);
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