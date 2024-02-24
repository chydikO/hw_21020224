#include <iostream>
#include <random>

void fillArray(int* arr, int N);
void printArray(const int* arr, int size);
int* removeZeros(const int* arr, int size, int& newSize);

int main() {
    int N;
    std::cout << "---Task 1---" << std::endl;
    std::cout << "Enter the size of the array: ";
    std::cin >> N;

    int* arr = new int[N];
    fillArray(arr, N);

    std::cout << "Array elements: ";
    printArray(arr, N);

    std::cout << "---Task 2---" << std::endl;
    int arrWithZero[] = {10,-3, 0, 3, 0, 5, 0, 7, -15, 20,};
    int size = sizeof(arrWithZero) / sizeof(arrWithZero[0]);


    std::cout << "--Original array---" << std::endl;
    printArray(arrWithZero, size);

    std::cout << "--Modified array---" << std::endl;
    int newSize = 0;
    int* newArr = removeZeros(arrWithZero, size, newSize);

    printArray(newArr, newSize);

    delete[] arr;
    delete[] newArr;
    return 0;
}

void fillArray(int* arr, int N) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 10);

    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            arr[i] = dist(gen) * 2; // Even value
        } else {
            arr[i] = dist(gen) * 2 + 1; // Odd value
        }
    }
}

void printArray(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "size-> " << size;
    std::cout << std::endl;
}

int* removeZeros(const int* arr, int size, int& newSize) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            count++;
        }
    }

    newSize = count;
    int* newArr = new int[newSize];

    int index = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            newArr[index] = arr[i];
            index++;
        }
    }

    return newArr;
}
