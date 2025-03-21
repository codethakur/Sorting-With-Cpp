#include <iostream>

void merge(int data[], int left, int mid, int right);
void mergeSort(int data[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2; 
        mergeSort(data, left, mid);
        mergeSort(data, mid + 1, right);
        merge(data, left, mid, right);
    }
}
void merge(int data[], int left, int mid, int right)
{
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int leftArray[leftSize], rightArray[rightSize];

    for (int i = 0; i < leftSize; i++)
        leftArray[i] = data[left + i];

    for (int i = 0; i < rightSize; i++)
        rightArray[i] = data[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < leftSize && j < rightSize)
    {
        if (leftArray[i] <= rightArray[j])
        {
            data[k] = leftArray[i];
            i++;
        }
        else
        {
            data[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < leftSize)
    {
        data[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < rightSize)
    {
        data[k] = rightArray[j];  
        j++;
        k++;
    }
}

int main()
{
    int data[] = {5, 2, 4, 7, 8};
    int Size = sizeof(data) / sizeof(data[0]);

    mergeSort(data, 0, Size - 1);

    for (int i = 0; i < Size; i++)
    {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
