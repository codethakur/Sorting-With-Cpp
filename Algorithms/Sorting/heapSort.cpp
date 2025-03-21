#include<iostream>
#include<utility>
void heapify(int data[],int Size, int root)
{
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    while(left<Size && data[left]>data[largest]){
        largest = left;
    }
    while (right<Size && data[right]>data[largest])
    {
        largest=right;
    }
    if(largest!=root){
        std::swap(data[root], data[largest]);
        heapify(data, Size, largest);

    }

}

void heapSort(int data[], int Size)
{
    // Step 1: Build a max heap
    for(int i = Size/2-1; i>=0; i--){
        heapify(data,Size, i);
    }
    // Step 2: Extract elements from heap one by one
    for(int i=Size-1; i>=0; i--){
        std::swap(data[0], data[i]);
        heapify(data, i, 0);
    }

}

int main()
{
    int data[] = {5, 2, 4, 7, 8};
    int Size = sizeof(data) / sizeof(data[0]);

    heapSort(data, Size);

    for (int i = 0; i < Size; i++)
    {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";

    return 0;
}