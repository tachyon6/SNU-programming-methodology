#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void BubbleSort(int arr[], int size);
void InsertionSort(int arr[], int size);
void SelectionSort(int arr[], int size);


int main() {
    int type, size;

    cin >> type >> size;

    int array[size];

    for (int i=0; i<size; i++){
        cin >> array[i];
    }

    switch (type){
        case 1:
            BubbleSort(array, size);
            break;
        case 2:
            InsertionSort(array, size);
            break;
        case 3:
            SelectionSort(array, size);
            break;
  }
}

//your code starts here (function definition : BubbleSort, InsertionSort, SelectionSort)
void BubbleSort(int arr[], int size) {
    for (int step = 0; step < size - 1; ++step) {
        bool isSwapped = false;
        for (int i = 0; i < size - step - 1; ++i) {
            if (arr[i] < arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                isSwapped = true;
                for (int j = 0; j < size; j++) {
                    cout << arr[j] << (j < size - 1 ? " " : "");
                }
                cout << endl;
            }
        }
        if (!isSwapped)
            break;
    }
}
void InsertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

        if (j != i - 1) { 
            for (int k = 0; k < size; k++) {
                cout << arr[k] << (k < size - 1 ? " " : "");
            }
            cout << endl;
        }
    }
}


void SelectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int max = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] > arr[max]) {
                max = j;
            }
        }
        if (max != i) {
            std::swap(arr[i], arr[max]);

            for (int k = 0; k < size; k++) {
                cout << arr[k] << (k < size - 1 ? " " : "");
            }
            cout << endl;
        }
    }
}
