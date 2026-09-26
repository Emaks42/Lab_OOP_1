#include <iostream>

int* array_create(std::size_t size) {
    int* arr = new int[size]{};
    return arr;
}
void array_delete(int*& arr) {
    delete[] arr;
    arr = nullptr;
}
int* array_resize(int* arr, std::size_t size, std::size_t new_size) {
    int* new_arr = new int[size]{};
    for (std::size_t i = 0; i < new_size; ++i) {
        new_arr[i] = arr[i];
    }
    delete[] arr;
    arr = nullptr;
    return new_arr;
}
int* array_insert(int* arr, std::size_t& size, std::size_t pos, int value) {
    size++;
    int* new_arr = new int[size]{};
    std::size_t i = 0;
    for (; i < pos; ++i) {
        new_arr[i] = arr[i];
    }
    new_arr[i] = value;
    i++;
    for (; i < size; ++i) {
        new_arr[i] = arr[i];
    }
    delete[] arr;
    arr = nullptr;
    return new_arr;
}
int* array_remove(int* arr, std::size_t& size, std::size_t pos) {
    int* new_arr = new int[size-1]{};
    for (std::size_t i = 0, new_i = 0; i < size; i++, new_i++) {
        if (i == pos) {
            i++;
        }
        new_arr[new_i] = arr[i];
    }
    delete[] arr;
    arr = nullptr;
    size--;
    return new_arr;
}
void array_print(int* arr, std::size_t size) {
    for (std::size_t i = 0; i < size; ++i) { std::cout << arr[i] << " "; }
    std::cout << "\n";
}
void array_gnome_sort(int* arr, std::size_t size) {
    std::size_t i = 0;
    while (i < size) {
        if (i == 0) { i++; }
        if (arr[i] < arr[i-1]) {
            int sav = arr[i];
            arr[i] = arr[i-1];
            arr[i-1] = sav;
            i--;
        }
    }
}

bool array_binary_search(const int* arr, std::size_t size, int target, std::size_t& out_index) {
    std::size_t lo = 0;
    std::size_t hi = size;
    std::size_t index = size / 2;
    while ((hi - lo) > 1)
    {
        index = lo + (hi - lo) / 2;
        if (arr[index] < target) {
            hi = index;
        } else {
            lo = index;
        }
    }
    out_index = lo;
    if (arr[lo] == target) {
        return true;
    }
    return false;
}