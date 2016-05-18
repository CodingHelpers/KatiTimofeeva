#include <iostream>

using namespace std;

struct Order
{
    public:
        double GainAmount, SendAmount, TransferAmount;
};

void swapValues (Order &order1, Order &order2)
{
    Order temp;
    temp = order2;
    order2 = order1;
    order1 = temp;
    delete &temp;
}

double sort (Order orders[], int size)
{
    if (size <= 0)
        cerr << "Invalid size" << endl;

    int temp;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            //temp = orders[j].;
            if ((orders[j].GainAmount + orders[j].SendAmount + orders[j].TransferAmount) < (orders[j + 1].GainAmount + orders[j + 1].SendAmount + orders[j + 1].TransferAmount))
                swapValues(orders[j], orders[j + 1]);
        }
    }
}

void GetCheckValue ()
{

}

int main (int argc, char *argv[])
{
    return 0;
}
