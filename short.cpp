#include <iostream>
using namespace std;

// Fungsi untuk melakukan Shell Sort
void shellSort(int arr[], int n) {
    // Mulai dengan gap besar, kemudian kurangi gap-nya
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Lakukan insertion sort untuk setiap gap
        for (int i = gap; i < n; i++) {
            // Simpan nilai saat ini dan lokasi terakhirnya
            int temp = arr[i];
            int j;
            // Geser elemen-elemen yang lebih besar dari nilai saat ini ke depan
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            // Tempatkan nilai saat ini di posisi yang sesuai
            arr[j] = temp;
        }
    }
}

// Fungsi untuk menampilkan array
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Fungsi utama
int main() {
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array sebelum sorting: \n";
    displayArray(arr, n);

    shellSort(arr, n);

    cout << "Array setelah sorting: \n";
    displayArray(arr, n);
    return 0;
}