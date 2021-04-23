#include <stdlib.h>
#include <iostream>
#include <fstream>
#include<algorithm>
#include<time.h>
using namespace std;
int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}
void quickSort(float arr[], int l, int r)
{
    if (l <= r)
    {
        float key = arr[rand() % (r - l) + l];
        int i = l;
        int j = r;
        while (i <= j)
        {
            while (arr[i] < key)
                i++;
            while (arr[j] > key)
                j--;
            if (i <= j)
            {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }
        if (l < j)
            quickSort(arr, l, j);
        if (r > i)
            quickSort(arr, i, r);
    }
}
void heapify(float arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2; 
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(float arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
int main()
{
    float a[1000000];
    clock_t start;
    ////////////////////////////////////////////////////////////////////////////////////////Qsort C
    ifstream out("C:\\Users\\ANH\\Desktop\\KT\\Input\\10.txt");
    for (int i = 0; i < 1000000; i++)
    {
        out >> a[i];
    }
    out.close();
    start = clock();
    qsort(a, 1000000, sizeof(float), compare);
    start = clock() - start;
    cout <<"qSort C:"<< start<<endl;
    ofstream QsortC("C:\\Users\\ANH\\Desktop\\KT\\qSortC\\10.txt");
    for (int i = 0; i < 1000000; i++)
    {
        QsortC << a[i] << ' ';
    }
    QsortC.close();

    ////////////////////////////////////////////////////////////////////////////////////////Sort C
    for (int i = 0; i < 1000000; i++)
    {
        out >> a[i];
    }
    out.close();
    start = clock();
    sort(a, a+1000000);
    start = clock()-start;
    cout <<"Sort C:"<< start<<endl;
    ofstream sort("C:\\Users\\ANH\\Desktop\\KT\\SortC\\10.txt");
    for (int i = 0; i < 1000000; i++)
    {
        sort << a[i] << ' ';
    }
    sort.close();

    ///////////////////////////////////////////////////////////////////////////////////Quicksort
    for (int i = 0; i < 1000000; i++)
    {
        out >> a[i];
    }
    out.close();
    start = clock();
    quickSort(a, 0, 999999);
    start = clock() - start;
    cout <<"qSort:"<< start << endl;
    ofstream Qsort("C:\\Users\\ANH\\Desktop\\KT\\qSort\\10.txt");
    for (int i = 0; i < 1000000; i++)
    {
        Qsort << a[i] << ' ';
    }
    Qsort.close();

    ///////////////////////////////////////////////////////////////////////////////Heapsort
    for (int i = 0; i < 1000000; i++)
    {
        out >> a[i];
    }
    out.close();
    start = clock();
    heapSort(a,999999);
    start = clock() - start;
    cout <<"Heap Sort:"<< start << endl;
    ofstream Heapsort("C:\\Users\\ANH\\Desktop\\KT\\Heapsort\\10.txt");
    for (int i = 0; i < 1000000; i++)
    {
        Heapsort << a[i] << ' ';
    }
    Heapsort.close();

    return 0;
}