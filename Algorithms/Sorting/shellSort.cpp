#include <iostream>

void ShellSort(int data[], int Size)
{
    int gap = Size / 2;
    for (gap; gap >= 1; gap /= 2)
    {
        for (int j = gap; j < Size; j++)
        {
            for (int i = j - gap; i >= 0; i -= gap)  //  decrement syntax
            {
                if (data[i] > data[i + gap])  // Corrected comparison
                {
                    int temp = data[i];
                    data[i] = data[i + gap];
                    data[i + gap] = temp; 
                }
                else
                {
                    break;  // Break if elements are in correct order
                }
            }
        }
    }

    for (int i = 0; i < Size; i++)  // Keep your original print loop
    {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";
}

int main()
{
    int data[] = {5, 2, 4, 7, 8};
    ShellSort(data, 5);
    return 0;
}
