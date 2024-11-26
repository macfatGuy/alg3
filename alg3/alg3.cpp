#include <iostream>
#include <vector>
#include <algorithm>


template <typename Iterator>
void merge(Iterator begin, Iterator mid, Iterator end) {
    int n1 = distance(begin, mid);
    int n2 = distance(mid, end);

    std::vector<typename std::iterator_traits<Iterator>::value_type> L(n1);
    std::vector<typename std::iterator_traits<Iterator>::value_type> R(n2);

    std::copy(begin, mid, L.begin());
    std::copy(mid, end, R.begin());


    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            begin[k++] = L[i++];
        }
        else {
            begin[k++] = R[j++];
        }
    }

    while (i < n1) {
        begin[k++] = L[i++];
    }

    while (j < n2) {
        begin[k++] = R[j++];
    }
}



template <typename Iterator>
void merge_sort(Iterator begin, Iterator end) {
    if (distance(begin, end) <= 1) return;

    Iterator mid = begin + distance(begin, end) / 2;
    merge_sort(begin, mid);
    merge_sort(mid, end);
    merge(begin, mid, end);
}


void printArray(const std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << (i == arr.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;
}

int main() {

    setlocale(LC_ALL, "Russian");
    
    std::vector<int> arr1 = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
    std::vector<int> arr2 = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
    std::vector<int> arr3 = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };

    std::cout << "Исходный массив: ";
    printArray(arr1);
    merge_sort(arr1.begin(), arr1.end());
    std::cout << "Отсортированный массив: ";
    printArray(arr1);


    std::cout << "Исходный массив: ";
    printArray(arr2);
    merge_sort(arr2.begin(), arr2.end());
    std::cout << "Отсортированный массив: ";
    printArray(arr2);

    std::cout << "Исходный массив: ";
    printArray(arr3);
    merge_sort(arr3.begin(), arr3.end());
    std::cout << "Отсортированный массив: ";
    printArray(arr3);

    return 0;
}

