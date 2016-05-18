#include <iostream>

using namespace std;

struct Order
{
    double GetOrder, SendOrder, TransferAmount;
};

int sort (int *arr[], int size)
{
    if (size <= 0)
        cerr << "Invalid size" << endl;

    int *newarr = new int[size]; int temp;

    /* Сортировка массива пузырьком */
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = newarr[j];
                arr[j] = arr[j + 1];
                newarr[j + 1] = temp;
            }
        }
    }

    return *newarr;
}

void GetCheckValue ()
{

}

int main (int argc, char *argv[])
{
    return 0;
}
