#include <iostream>
#include <fstream>
#include <string.h>


// Структура Марш
struct Marsh {
    public:
        char StartPoint[64];
        char EndPoint[64];
        uint Number;
};

// Вывод маршрута на экран
void print(const Marsh& marsh) {
    std::cout << "Marsh #" << marsh.Number << ": " << marsh.StartPoint << "-> " << marsh.EndPoint << std::endl;
}

// Обмен значениями между структурами
void swap (Marsh &marsh1, Marsh &marsh2) {
    Marsh temp;
    temp = marsh2;
    marsh2 = marsh1;
    marsh1 = temp;
}

// Сортировка массива ы алфовитном порядке
void sort(Marsh marshs[], uint size) {
    for (uint i = 0; i < size; i++) {
        for (uint j = 0; j < size - 1; j++) {
            if (strcmp(marshs[j].EndPoint, marshs[j+1].EndPoint) < 0) {
                swap(marshs[j], marshs[j+1]);
            }
        }
    }
}

// Поиск структур
void find(Marsh marshs[], uint size, char* name) {
    bool found = false;
    for(int i = 0; i < size; i++) {
        if(strcmp(name, marshs[i].StartPoint) == 0
        || strcmp(name, marshs[i].EndPoint) == 0) {
            print(marshs[i]);
            found = true;
        }
    }

    if(!found) {
        std::cout << "Nothing found\n";
    }
}

// filename -- имя файла откуда нужно прочитать струкртуры
// output_buffer -- массив, куда нужно записать считанные мтруктуры
// size -- максимальный размер буффера вывода
// функция возвращает количество прочитаных структур
int loadC(const char* filename, Marsh* output_buffer, uint size) {
    // Открываем файл
    FILE* file = fopen(filename, "r");

    // Проверяем открыт ли файл
    if(!file) {
        return -1;
    }

    // Размер массива
    int n = 0;

    // Читаем файл строка-за-строкой
    char buffer[256];
    while(fgets(buffer, 256, file) != NULL) {
        // Ищем указатели на элементы массива в строке
        char* sp = buffer;
        char* ep = strchr(buffer, ' ') + 1;
        char* N  = strchr(ep, ' ') + 1;

        // Если хоть один указатель NULL, то файл неверный
        if(!sp || !ep || !N) {
            return -1;
        }

        // Создаем новый Машрут
        Marsh temp;

        // Копируем строки
        strncpy(temp.StartPoint, sp, ep - sp);
        strncpy(temp.EndPoint, ep, N - ep);
        temp.Number = atoi(N);

        // Добавляем в массив
        output_buffer[n++] = temp;

        if(n == (int) size) {
            break;
        }

        // Зануляем temp
        memset(&temp, '\0', sizeof(Marsh));
    }

    return n;
}

// filename -- имя файла откуда нужно прочитать струкртуры
// output_buffer -- массив, куда нужно записать считанные мтруктуры
// size -- максимальный размер буффера вывода
// функция возвращает количество прочитаных структур
int loadCPP(const std::string& filename, Marsh* output_buffer, uint size) {
    // Открываем файл
    std::ifstream filestream(filename);

    // Проверяем открыт ли файл
    if(!filestream.is_open()) {
        return -1;
    }

    // Размер массива
    int n = 0;

    // Создаем новый Машрут
    Marsh temp;

    // Читаем файл
    while(filestream >> temp.StartPoint >> temp.EndPoint >> temp.Number) {
        // Добавляем в массив
        output_buffer[n++] = temp;

        if(n == (int) size) {
            break;
        }
    }
    return n;
}

int main() {
    // Файл с маршрутами
    const char* filename_c = "marshfile.txt";
    const std::string filename_cpp(filename_c);

    int mcnt = 0;
    Marsh marshs[10];

    // Загрузка файла механизмами Си
    mcnt = loadC(filename_c, marshs, 10);

    if(mcnt < 0) {
        std::cout << "Error loading file\n";
        return 1;
    }

    // Вывод
    std::cout << "C-style loading:\n";
    for(uint i = 0; i < mcnt; i++) {
        print(marshs[i]);
    }

    // Сортировка и вывод
    std::cout << "\nSorted:\n";
    sort(marshs, mcnt);
    for(uint i = 0; i < mcnt; i++) {
        print(marshs[i]);
    }

    mcnt = loadCPP(filename_cpp, marshs, 10);
    if(mcnt < 0) {
        std::cout << "Error loading file\n";
        return 1;
    }

    // Вывод
    std::cout << "\nC++ style loading:\n";
    for(uint i = 0; i < mcnt; i++) {
        print(marshs[i]);
    }

    // Ввод искомого имени
    char name[64];
    std::cout << "\nEnter name to find: ";
    std::cin >> name;

    // Поиск и вывод
    find(marshs, mcnt, name);

    return 0;
}
