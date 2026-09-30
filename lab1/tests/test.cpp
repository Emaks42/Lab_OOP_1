#include <gtest/gtest.h>
#include <algorithm>
#include "../include/array_ops.h"

TEST(ArrayCreationTests, ArrayCreationBaseTest)
{
    int* arr = nullptr;
    arr = array_create(10);
    ASSERT_TRUE(arr != nullptr);
    array_delete(arr);
}

TEST(ArrayCreationTests, ArrayCreationZeroSizeTest)
{
    int* arr = nullptr;
    arr = array_create(0);
    ASSERT_TRUE(arr == nullptr);
    array_delete(arr);
}

TEST(ArrayDeleteTests, ArrayDeleteBaseTest)
{
    int* arr = nullptr;
    arr = array_create(10);
    array_delete(arr);
    ASSERT_TRUE(arr == nullptr);
}

TEST(ArrayResizeTests, ArrayResizeDownTest)
{
    int* arr = nullptr;
    std::size_t size = 10;
    arr = array_create(size);
    arr[1] = 10;
    arr[2] = 12;
    arr = array_resize(arr, size, 6);
    ASSERT_EQ(arr[1], 10);
    ASSERT_EQ(arr[2], 12);
    array_delete(arr);
}

TEST(ArrayResizeTests, ArrayResizeUpTest)
{
    int* arr = nullptr;
    std::size_t size = 10;
    arr = array_create(size);
    arr[1] = 10;
    arr[2] = 12;
    arr = array_resize(arr, size, 16);
    arr[15] = 13;
    ASSERT_EQ(arr[1], 10);
    ASSERT_EQ(arr[2], 12);
    ASSERT_EQ(arr[15], 13);
    array_delete(arr);
}

TEST(ArrayResizeTests, ArrayResizeZeroTest)
{
    int* arr = nullptr;
    std::size_t size = 10;
    arr = array_create(size);
    arr[1] = 10;
    arr[2] = 12;
    arr = array_resize(arr, size, 0);
    ASSERT_EQ(arr, nullptr);
    array_delete(arr);
}

TEST(ArrayInsertTests, ArrayInsertBaseTest)
{
    int* arr = nullptr;
    std::size_t size = 10;
    arr = array_create(size);
    arr[1] = 10;
    arr[2] = 12;
    arr = array_insert(arr, size, 4, 2);
    ASSERT_EQ(arr[4], 2);
    ASSERT_EQ(size, 11);
    array_delete(arr);
}

TEST(ArrayInsertTests, ArrayInsertStartTest)
{
    int* arr = nullptr;
    std::size_t size = 10;
    arr = array_create(size);
    arr[1] = 10;
    arr[2] = 12;
    arr = array_insert(arr, size, 0, 2);
    ASSERT_EQ(arr[0], 2);
    ASSERT_EQ(arr[2], 10);
    ASSERT_EQ(arr[3], 12);
    ASSERT_EQ(size, 11);
    array_delete(arr);
}

TEST(ArrayInsertTests, ArrayInsertEndTest)
{
    int* arr = nullptr;
    std::size_t size = 10;
    arr = array_create(size);
    arr[1] = 10;
    arr[2] = 12;
    arr = array_insert(arr, size, 10, 2);
    ASSERT_EQ(arr[10], 2);
    ASSERT_EQ(size, 11);
    array_delete(arr);
}

TEST(ArrayRemoveTests, ArrayRemoveBaseTest)
{
    int* arr = nullptr;
    std::size_t size = 10;
    arr = array_create(size);
    arr[1] = 10;
    arr[2] = 12;
    arr = array_remove(arr, size, 1);
    ASSERT_EQ(arr[1], 12);
    ASSERT_EQ(size, 9);
    array_delete(arr);
}

TEST(ArrayRemoveTests, ArrayRemoveStartTest)
{
    int* arr = nullptr;
    std::size_t size = 10;
    arr = array_create(size);
    arr[1] = 10;
    arr[2] = 12;
    arr = array_remove(arr, size, 0);
    ASSERT_EQ(arr[0], 10);
    ASSERT_EQ(arr[1], 12);
    ASSERT_EQ(size, 9);
    array_delete(arr);
}

TEST(ArrayRemoveTests, ArrayRemoveEndTest)
{
    int* arr = nullptr;
    std::size_t size = 10;
    arr = array_create(size);
    arr[1] = 10;
    arr[2] = 12;
    arr = array_remove(arr, size, 9);
    ASSERT_EQ(size, 9);
    array_delete(arr);
}

TEST(ArrayGnomeSortTests, ArrayGnomeSortBaseTest)
{
    int* arr = new int[10]{3,2,13,4,56,5,2,1,0,6};
    std::size_t size = 10;
    array_gnome_sort(arr, size);
    for (int i = 0; i < (size - 1); ++i) {
        ASSERT_LE(arr[i], arr[i+1]);
    }
    array_delete(arr);
}

TEST(ArrayGnomeSortTests, ArrayGnomeSortAlreadySortedTest)
{
    int* arr = new int[10]{1,2,3,4,5,7,8,10,15,20};
    std::size_t size = 10;
    array_gnome_sort(arr, size);
    for (int i = 0; i < (size - 1); ++i) {
        ASSERT_LE(arr[i], arr[i+1]);
    }
    array_delete(arr);
}

TEST(ArrayGnomeSortTests, ArrayGnomeSortDuplicatesTest)
{
    int* arr = new int[10]{1,34,55,1,1,20,30,10,20,55};
    std::size_t size = 10;
    array_gnome_sort(arr, size);
    for (int i = 0; i < (size - 1); ++i) {
        ASSERT_LE(arr[i], arr[i+1]);
    }
    array_delete(arr);
}

TEST(ArrayGnomeSortTests, ArrayGnomeSortReverseSortedWithNegTest)
{
    int* arr = new int[10]{20,13,12,10,9,7,1,-20,-30,-42};
    std::size_t size = 10;
    array_gnome_sort(arr, size);
    for (int i = 0; i < (size - 1); ++i) {
        ASSERT_LE(arr[i], arr[i+1]);
    }
    array_delete(arr);
}

TEST(ArrayGnomeSortTests, ArrayGnomeSortOneElementTest)
{
    int* arr = new int[1]{42};
    std::size_t size = 1;
    array_gnome_sort(arr, size);
    ASSERT_EQ(arr[0], 42);
    array_delete(arr);
}

TEST(ArrayBinarySearchTests, ArrayBinarySearchBaseTest)
{
    int* arr = new int[10]{1,2,3,4,5,7,8,10,15,20};
    std::size_t size = 10, out_idx{};
    bool find = array_binary_search(arr, size, 4, out_idx);
    ASSERT_TRUE(find);
    ASSERT_EQ(out_idx, 3);
    array_delete(arr);
}

TEST(ArrayBinarySearchTests, ArrayBinarySearchEndTest)
{
    int* arr = new int[10]{1,2,3,4,5,7,8,10,15,20};
    std::size_t size = 10, out_idx{};
    bool find = array_binary_search(arr, size, 20, out_idx);
    ASSERT_TRUE(find);
    ASSERT_EQ(out_idx, 9);
    array_delete(arr);
}

TEST(ArrayBinarySearchTests, ArrayBinarySearchStartTest)
{
    int* arr = new int[10]{1,2,3,4,5,7,8,10,15,20};
    std::size_t size = 10, out_idx{};
    bool find = array_binary_search(arr, size, 1, out_idx);
    ASSERT_TRUE(find);
    ASSERT_EQ(out_idx, 0);
    array_delete(arr);
}

TEST(ArrayBinarySearchTests, ArrayBinarySearchNotFoundTest)
{
    int* arr = new int[10]{1,2,3,4,5,7,8,10,15,20};
    std::size_t size = 10, out_idx{};
    bool find = array_binary_search(arr, size, 11, out_idx);
    ASSERT_FALSE(find);
    array_delete(arr);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}