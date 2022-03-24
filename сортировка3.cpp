// сортировки3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <ctime>
using namespace std;
#define N 8

int arr[N];

void Rand()
{
    srand(time(NULL));
    for (int i = 0; i < N; i++)
    {
        arr[i] = rand() % 201 - 100;
    }
    cout << "BEFORE: " << endl;
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}
void Quicksort(int *a, int size)
{
    int size2 = size;
    int k = 0;
    int d = a[size / 2];
    while (k <= size) {
        while (a[k] < d) k++;
        while (a[size] > d) size--;
        if (k <= size) {
            swap(a[k], a[size]);
            k++; size--;
        }
    }
    if (size > 0) Quicksort(a, size);
    if (size2>k)  Quicksort(a+k, size2-k);
}


   
void Output()
{
    cout << "AFTER: " << endl;
    for (int i = 0; i < N; i++)
        cout << arr[i] << "\t";
}

int main()
{
    setlocale(LC_ALL, "rus");
    Rand();
    Quicksort(arr,N);
    

    Output();
}
