#include <iostream>

using namespace std;

struct Order
{
    public:
        double PayAmount, GainAmount, TransferAmount;
};

double sum(const Order orders[], int index)
{
    return (orders[index].PayAmount + orders[index].GainAmount + orders[index].TransferAmount);
}

void swapValues (Order &order1, Order &order2)
{
    Order temp;
    temp = order2;
    order2 = order1;
    order1 = temp;
    delete &temp;
}

double sort (Order orders[], int size) /* size обычно есть sizeof(order)/sizeof(order[0]) */
{
    if (size <= 0)
        cerr << "Неверный размер" << endl;

    int temp;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (sum(orders[], j) < sum(orders[], j + 1))
                swapValues(orders[j], orders[j + 1]);
        }
    }
}

void GetCheckValue (Order orders[])
{
    int Payment;
    cin >> Payment;
    for (int i = 0; i < (sizeof(orders)/sizeof(orders[0])); i++)
    {
        if (Payment == orders->GainAmount)
            cout << "Совпадение: " << orders->GainAmount << " в счёте №" << i << endl;
    }
}

int main (int argc, char *argv[])
{
    return 0;
}
