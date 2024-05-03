#include <iostream>
using namespace std;

// Fungsi untuk menukar nilai dua elemen
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi untuk memilih pivot (menggunakan elemen terakhir sebagai pivot)
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivot
    int i = (low - 1); // Indeks elemen yang lebih kecil

    for (int j = low; j <= high - 1; j++) {
        // Jika elemen saat ini lebih kecil dari atau sama dengan pivot
        if (arr[j] <= pivot) {
            i++; // Tingkatkan indeks dari elemen yang lebih kecil
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Fungsi utama yang mengimplementasikan QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi adalah indeks pembagi, arr[pi] sekarang berada di posisi yang tepat
        int pi = partition(arr, low, high);

        // Pisahkan elemen sebelum dan setelah pembagi, kemudian lakukan rekursif
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Fungsi untuk menampilkan array
void displayArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Fungsi utama
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Array sebelum sorting: \n";
    displayArray(arr, n);
    
    quickSort(arr, 0, n - 1);
    
    cout << "Array setelah sorting: \n";
    displayArray(arr, n);
    
    return 0;
}