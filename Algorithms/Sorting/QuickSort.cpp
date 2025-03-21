#include<iostream>

int partition(int data[], int start, int end){
    int index = start-1;
    int pivot = data[end];

    for(int i=start; i<end; i++)
    {
        if(data[i] <= pivot){
            index++;
            std::swap(data[index], data[i]);
        }
    }
    
    index++;
    std::swap(data[index], data[end]); 
    return index;
}
void quickSort(int data[], int start, int end)
{

    if(start<end)
    {
        int pivotIndex = partition(data, start, end);

        quickSort(data, start, pivotIndex-1);
        quickSort(data, pivotIndex+1, end);
    }
}

int main()
{
    int data[] = {5, 2, 4, 7, 8};
    int Size = sizeof(data) / sizeof(data[0]);

    quickSort(data, 0, Size-1);

    for (int i = 0; i < Size; i++)
    {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";

    return 0;
}