#include<iostream>
void SelectionSort(int data[], int Size)
{
    int min = 0;
   for(int i =0; i<Size-1; i++)
   {
        min = i;
        for(int j = i+1; j<Size; j++){
            if(data[j]<data[min]){
                min=j;
            }
        } 
        int temp = data[min];
        data[min] = data[i];
        data[i] = temp;
   }
   for (int num =0; num<Size; num++)
   {
       std::cout << data[num] << " ";
   }
   std::cout<<"\n";
}

int main()
{
    int data[]  = {5, 2, 4, 7, 8};
    
    int n = sizeof(data) / sizeof(data[0]);
    std::cout<<"n: "<<n<<std::endl;
    SelectionSort(data, 5);
}