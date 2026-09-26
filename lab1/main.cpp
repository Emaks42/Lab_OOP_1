#include <iostream>
#include "array_ops.h"

void dialogue_cycle() {
    bool running = true;
    int inp{};
    int size{};
    int* arr = nullptr;
    while (running) {
        std::cout << "Введите 1 из 9 опций:\n";
        std::cout << "0 - выход из меню\n";
        std::cout << "1 - создать массив\n";
        std::cout << "2 - напечатать массив\n";
        std::cout << "3 - вставить элемент в массив\n";
        std::cout << "4 - удалить элемент из массива\n";
        std::cout << "5 - Изменить размер массива\n";
        std::cout << "6 - вывести конкретный элемент массива\n";
        std::cout << "7 - гномья сортировка массива\n";
        std::cout << "8 - двоичный поиск по массиву\n";
        std::cin >> inp;
        switch (inp)
        {
            case 0:
                running = false;
                break;
            
            case 1:
                std::cout << "введите размер массива:\n";
                std::cin >> size;
                if (size < 0) {
                    std::cout << "некорректный размер массива\n";
                    size = 0;
                    break;
                }
                if (arr != nullptr) {
                    std::cout << "у вас уже есть готовый массив, вы хотите удаить его и создать новый? (0/1)\n";
                    int answer{};
                    std::cin >> answer;
                    if (answer) {
                        array_delete(arr);
                    } else {
                        break;
                    }

                }
                arr = array_create(size);
                if (arr == nullptr) {
                    std::cout << "ошибка при создании массива, рекомендуется уменьшить размер выделяемой памяти\n";
                    size = 0;
                    break;
                }
                std::cout << "успешно создан массив\n";
                break;
            
            case 2:
                if (arr == nullptr) { std::cout << "для того, чтобы вывести массив сначала создайте его\n"; break;}
                array_print(arr, size);
                break;
            
            case 6:
                if (arr == nullptr) { std::cout << "для того, чтобы вывести элемент массива сначала создайте массив\n"; break;}
                int pos{};
                std::cout << "введите индекс элемента:\n";
                std::cin >> pos;
                if ((pos < 0) || (pos >= size)) {
                    std::cout << "некорректный индекс\n";
                    break;
                }
                std::cout << arr[pos] << "\n";
                break;
        
            default:
                std::cout << "неверный номер команды\n";
                break;
        }

    }

}

int main() {
    std::cout << "Hello, world!\n";
    return 0;
}