#include <iostream>
#include <chrono>
#include <random>
#include <thread>

using namespace std;

void cocktailSort(int arr[], int n) {
    bool flag = true;
    int start = 0, end = n - 1;

    while (flag) {
        flag = false;
        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                flag = true;
            }
        }
        if (!flag) {
            break;
        }
        flag = false;
        end--;
        // Slow down and display array after each iteration
        this_thread::sleep_for(chrono::seconds(30));
        cout << "Array being sorted: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        for (int i = end - 1; i >= start; i--) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                flag = true;
            }
        }
        start++;

        // Slow down and display array after each iteration
        this_thread::sleep_for(chrono::seconds(30));


        cout << "Array being sorted: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

void displayArray(int arr[], int n) {
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void randomizeArray(int arr[], int n) {
    random_device rd;
    mt19937 generator(rd());

    for (int i = 0; i < n; i++) {
        arr[i] = generator() % 100; // Random numbers between 0 and 99
    }
}

void manualInputArray(int arr[], int n) {
    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int data[size];

    char choice;
    cout << "Do you want to randomize the numbers in the array? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        randomizeArray(data, size);
    } else {
        manualInputArray(data, size);
    }

    displayArray(data, size);

    int n = sizeof(data) / sizeof(data[0]);

    auto start = chrono::high_resolution_clock::now();
    cocktailSort(data, n);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);

    cout << "Sorted Sequence: ";
    displayArray(data, size);

    cout << "Time taken by function: " << duration.count() << " nanoseconds" << endl;

    return 0;
}
