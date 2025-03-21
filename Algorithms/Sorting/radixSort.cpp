#include <iostream>
#include <vector>
#include <cmath>

// Function to perform Counting Sort for a specific digit place
void countingSort(int data[], int Size, int place) {
    const int base = 10; // Decimal system
    std::vector<int> output(Size);
    int count[base] = {0};

    // Step 1: Count occurrences of each digit at 'place'
    for (int i = 0; i < Size; i++) {
        int digit = (data[i] / place) % base;
        count[digit]++;
    }

    // Step 2: Convert count array to cumulative count
    for (int i = 1; i < base; i++) {
        count[i] += count[i - 1];
    }

    // Step 3: Place elements in sorted order
    for (int i = Size - 1; i >= 0; i--) {
        int digit = (data[i] / place) % base;
        output[count[digit] - 1] = data[i];
        count[digit]--;
    }

    // Step 4: Copy sorted values back to original array
    for (int i = 0; i < Size; i++) {
        data[i] = output[i];
    }
}

// Function to perform Radix Sort
void radixSort(int data[], int Size) {
    // Find the maximum number to know the number of digits
    int maxElement = *std::max_element(data, data + Size);

    // Apply Counting Sort for each digit (unit, tens, hundreds, ...)
    for (int place = 1; maxElement / place > 0; place *= 10) {
        countingSort(data, Size, place);
    }
}

// Driver code
int main() {
    int data[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int Size = sizeof(data) / sizeof(data[0]);

    radixSort(data, Size);

    std::cout << "Sorted array: ";
    for (int i = 0; i < Size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
