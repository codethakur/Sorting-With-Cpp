#include <iostream>

void InsertionSort(int data[], int Size) {
    int key, j;
    for (int i = 1; i <=  Size-1; i++)  // No need for `i <= Size - 1`, just `i < Size`
    
    {
        key = data[i];
        j = i;

        while ( data[j - 1] > key && j >= 1)  //  order of conditions to avoid out-of-bounds
        {
            data[j] = data[j - 1];  // Shift elements
            j--;
        }
        data[j] = key;  // Place `key` in its correct position
    }

    // Print sorted array
    for (int i = 0; i < Size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    int data[] = {5, 2, 4, 7, 8};
    InsertionSort(data, 5);
    return 0;
}
