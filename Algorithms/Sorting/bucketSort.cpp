#include <iostream>
#include <vector>
#include <algorithm> // for sort()

void insertionSort(std::vector<float>& bucket) {
    int Size = bucket.size();
    for (int i = 1; i < Size; i++) {
        float key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

void bucketSort(float data[], int Size) {
    // Step 1: Create Buckets
    std::vector<float> buckets[Size];

    // Step 2: Distribute Elements into Buckets
    for (int i = 0; i < Size; i++) {
        int index = Size * data[i];  // Get bucket index
        buckets[index].push_back(data[i]);
    }

    // Step 3: Sort Each Bucket
    #if 0
    for (int i = 0; i < Size; i++) {
        std::sort(buckets[i].begin(), buckets[i].end());
    }
    #endif
    for (int i = 0; i < Size; i++) {
        insertionSort(buckets[i]);
    }


    // Step 4: Merge Buckets
    int index = 0;
    for (int i = 0; i < Size; i++) {
        for (float num : buckets[i]) {
            data[index++] = num;
        }
    }
}

int main() {
    float data[] = {0.42, 0.32, 0.33, 0.52, 0.25, 0.47, 0.51};
    int Size = sizeof(data) / sizeof(data[0]);

    bucketSort(data, Size);

    std::cout << "Sorted array: ";
    for (int i = 0; i < Size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
