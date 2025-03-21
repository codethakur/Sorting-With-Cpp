#include<iostream>
#include <utility> // For std::swap
void bubbleSort(int data[], int Size)
{
    for(int steps=0; steps<Size-1; ++steps)
    {
        for(int i=0; i<Size-steps-1; i++)
        {
            if(data[i]>data[i+1]){
                int temp = data[i];
                data[i] = data[i+1];   //  std::swap(data[i], data[i + 1]);
                data[i+1] = temp;
            }
        }
    }
       // Print using range-based for loop
       for (int num : std::span(data, Size))
       {
           std::cout << num << " ";
       }
       std::cout << "\n";
   
}

void bubbleSortImproved(int data[], int Size)
{
    int Swapped=1;
    for(int pass = Size-1; pass>=0 && Swapped; --pass)
    {
        Swapped = 0;
        for(int i=0; i<=pass-1; i++){
            
            if(data[i]>data[i+1]){
                int temp = data[i];
                data[i] = data[i+1];
                data[i+1] = temp;
                Swapped = 1;
            }
        }
    }
    for(int i=0; i<Size; i++){
        std::cout<<data[i]<<" ";
    }
}
int main()
{
    int data[]  = {5, 2, 4, 7, 8};

    bubbleSortImproved(data, 5);

    return 0;
}
