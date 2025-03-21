#include <iostream>
#include <vector>
#include <algorithm>

void countingSort(int data[], int Size) {
    // Step 1: Find the maximum element
    int maxElement = *std::max_element(data, data + Size);
    
    #if 0
        int maxElement = data[0]; // Assume first element is max
        for (int i = 1; i < Size; i++) {
            if (data[i] > maxElement) {
                maxElement = data[i]; // Update max if a larger element is found
            }
        }

    #endif

    // Step 2: Create and initialize count array
    std::vector<int> count(maxElement + 1, 0);

    // Step 3: Store count of each element
    for (int i = 0; i < Size; i++) {
        count[data[i]]++;
    }

    // Step 4: Update count array to store cumulative sum
    for (int i = 1; i <= maxElement; i++) {
        count[i] += count[i - 1];
    }

    // Step 5: Build the sorted array
    std::vector<int> output(Size);
    for (int i = Size - 1; i >= 0; i--) {
        output[count[data[i]] - 1] = data[i];
        count[data[i]]--;
    }

    // Step 6: Copy the sorted array back to original array
    for (int i = 0; i < Size; i++) {
        data[i] = output[i];
    }
}

int main() {
    int data[] = {5, 2, 4, 7, 8};
    int Size = sizeof(data) / sizeof(data[0]);

    countingSort(data, Size);

    for (int i = 0; i < Size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
