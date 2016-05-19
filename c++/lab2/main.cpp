#include <iostream>
#include <string.h>

using namespace std;

struct MARSH
{
    public:
        string Start, End;
        unsigned int Number;
};

void swapValues (MARSH &marsh1, MARSH &marsh2)
{
    MARSH temp;
    temp = marsh2;
    marsh2 = marsh1;
    marsh1 = temp;
    delete &temp;
}

void bubble(char *i, int n)
{
    int a, b;
    char t;
    for(a = 0; a < n; a++)
    {
        for(b = n - 1; b >= a; b--)
        {
            if(i[b - 1] > i[b])
            {
                t = i[b - 1];
                i[b - 1] = i[b];
                i[b] = t;
            }
        }
    }
}

double sort (MARSH marshs[], int size) /* size обычно есть sizeof(order)/sizeof(order[0]) */
{
    if (size <= 0)
        cerr << "Неверный размер" << endl;

    int temp;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            /* if ()
            {

                swapValues(marshs[j], marshs[j + 1]);
            } */
        }
    }
}

/* void GetCheckValue (MARSH marshs[])
{
    string UserInput;
    cin >> UserInput;
    for (int i = 0; i < (sizeof(marshs)/sizeof(marshs[0])); i++)
    {
        if (UserInput == marshs->Start)
            cout << "Совпадение: " << marshs[i]->Start << " в маршруте №" << marshs[i]->Number << endl;
        else if (UserInput == marshs.End)
            cout << "Совпадение: " << marshs[i]->End << " в маршруте №" << marshs[i]->Number << endl;
    }
} */

int main (int argc, char *argv[])
{
    return 0;
}
