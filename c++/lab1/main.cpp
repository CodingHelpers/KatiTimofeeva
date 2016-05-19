#include <iostream>
#include <cstring>

// Структура Order
struct Order {
public:
    int InputAccount,   // расчетный счет плательщика
        OutputAccount,  // расчетный счет получателя
        Sum;            // перечисляемая сумма в рублях
};

// Обмен значениями между двумя заказами
void swap(Order &order1, Order &order2) {
    Order temp;
    temp = order1;
    order1 = order2;
    order2 = temp;
}

// Сортировка массива заказов по убыванию суммы
void sort(Order orders[], uint size) {
    for (uint i = 0; i < size; i++) {
        for (uint j = 0; j < size - 1; j++) {
            if (orders[j].Sum < orders[j+1].Sum) {
                swap(orders[j], orders[j+1]);
            }
        }
    }
}

// Вывод заказа на экран
void print(const Order& order, uint n) {
    std::cout << "Order #" << n << ": "
              << order.InputAccount << "->" << order.OutputAccount << " "
              << order.Sum << std::endl;
}

// Поиск заказов по счету плательщика и вывод на экран
void GetCheck (Order orders[], uint size) {
    // Ввод номера счета плательщика
    int AccountNum;
    std::cout << "Input Account Number: ";
    std::cin >> AccountNum;

    // Поиск в массиве заказов с введенным номером счета плательщика
    bool found = false;
    for(uint i = 0; i < size; i++) {
        if(AccountNum == orders[i].InputAccount) {
            found = true;
            print(orders[i], i);
        }
    }

    if(!found) {
        std::cout << "No orders found\n";
    }
}

int main () {
    // Создание нового массива структур
    Order orders[5] = {
        {1, 2, 30}, // 1 -- номер плательика, 2 - номер получателя, 30 -- сумма
        {2, 3, 20},
        {1, 5, 50},
        {1, 10, 5},
        {2, 4, 100}
    };

    // Вывод массива структур
    std::cout << "Orders:\n";
    for(uint i = 0; i < 5; i++) {
        print(orders[i], i);
    }

    // Сортировка массива структур и вывод на экран
    std::cout << "\nSorted Orders:\n";
    sort(orders, 5);
    for(uint i = 0; i < 5; i++) {
        print(orders[i], i);
    }

    // Поиск в массиве структур
    std::cout << std::endl;
    GetCheck(orders, 5);

    return 0;
}
