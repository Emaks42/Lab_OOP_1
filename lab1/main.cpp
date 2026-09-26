#include <iostream>
#include "include/array_ops.h"

bool is_arr_sorted(int* arr, std::size_t size) {
    for (std::size_t i = 0; i < (size - 1); ++i) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

void dialogue_cycle() {
    bool running = true;
    int inp{}, value{};
    std::size_t size{};
    std::size_t pos{};
    std::size_t size_{};
    int answer{};
    int* arr = nullptr;
    int target{};
    int test{};
    std::size_t out_idx{};
    bool res{};
    while (running) {
        std::cout << "Введите 1 из 9 опций:\n";
        std::cout << "0 - выход из меню\n";
        std::cout << "1 - создать массив\n";
        std::cout << "2 - напечатать массив\n";
        std::cout << "3 - вставить элемент в массив\n";
        std::cout << "4 - удалить элемент из массива\n";
        std::cout << "5 - изменить размер массива\n";
        std::cout << "6 - удалить массив\n";
        std::cout << "7 - гномья сортировка массива\n";
        std::cout << "8 - двоичный поиск по массиву\n";
        std::cin >> inp;
        switch (inp)
        {
            case 0:
                std::cout << "работа завершена, спасибо, что выбираете нас\n";
                running = false;
                array_delete(arr);
                break;
            
            case 1:
                std::cout << "введите размер массива:\n";
                std::cin >> size;
                if (size <= 0) {
                    std::cout << "некорректный размер массива\n";
                    size = 0;
                    break;
                }
                if (arr != nullptr) {
                    std::cout << "у вас уже есть готовый массив, вы хотите удаить его и создать новый? (0/1)\n";
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
            
            case 3:
                if (arr == nullptr) { std::cout << "для того, чтобы вставить элемент в массив создайте массив\n"; break;} 
                std::cout << "введите число для вставки в массив:\n";
                std::cin >> value;
                std::cout << "введите индекс элемента:\n";
                std::cin >> pos;
                if ((pos < 0) || (pos >= size)) {
                    std::cout << "некорректный индекс\n";
                    break;
                }
                arr = array_insert(arr, size, pos, value);
                break;
            
            case 4:
                if (arr == nullptr) { std::cout << "для того, чтобы удалить элемент массива сначала создайте массив\n"; break;}
                std::cout << "введите индекс элемента:\n";
                std::cin >> pos;
                if ((pos < 0) || (pos >= size)) {
                    std::cout << "некорректный индекс\n";
                    break;
                }
                arr = array_remove(arr, size, pos);
                break;
            
            case 5:
                if (arr == nullptr) { std::cout << "для того, чтобы изменть размер массива сначала создайте его\n"; break;}
                std::cout << "введите новый размер:\n";
                std::cin >> size_;
                if (size > size_) {
                    std::cout << "новый размер массива меньше исходного, вы уверены, что ввели всё правильно? (0/1)\n";
                    std::cin >> test;
                    if (test) { break; }
                }
                arr = array_resize(arr, size, size_);
                break;
            
            case 6:
                if (arr == nullptr) { std::cout << "для того, чтобы вывести элемент массива сначала создайте массив\n"; break;}
                std::cout << "введите индекс элемента:\n";
                std::cin >> pos;
                if ((pos < 0) || (pos >= size)) {
                    std::cout << "некорректный индекс\n";
                    break;
                }
                std::cout << arr[pos] << "\n";
                break;
            
            case 7:
                if (arr == nullptr) { std::cout << "для того, чтобы отсортировать массив надо его создать\n"; break;}
                array_gnome_sort(arr, size);
            
            case 8:
                if (arr == nullptr) { std::cout << "для того, чтобы использовать двоичный поиск надо созвдть массив\n"; break;}
                if (!is_arr_sorted(arr, size)) { std::cout << "массив не является отсортированным, двоичный поиск может (и скорее всего будет) работать некорректно\n"; }
                std::cout << "введите индекс элемента:\n";
                std::cin >> pos;
                if ((pos < 0) || (pos >= size)) {
                    std::cout << "некорректный индекс\n";
                    break;
                }
                std::cout << "введите искомый элемент:\n";
                std::cin >> target;
                res = array_binary_search(arr, size, target, out_idx);
                if (res) {
                    std::cout << "элемент успешно найден на позиции "  << out_idx << "\n";
                } else {
                    std::cout << "элемент не найден\n";
                }
        
            default:
                std::cout << "неверный номер команды\n";
                break;
        }

    }

}

int main() {
    std::cout << "Добро пожаловать в интерактивное меню взаимодействия с массивом!\n";
    dialogue_cycle();
    return 0;
}