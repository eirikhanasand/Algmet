#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>

void shellSort(std::string& arr, const int n);
void swap(char& charOne, char& charTwo);
int  partition(std::string& arr, const int left, const int right);
void quickSort(std::string& arr, const int left, const int right);
void downHeap(std::string& arr, const int ant, int keyNr);
void heapSort(std::string& arr, int n);
void insertAndWriteHeap(std::vector<int>& heap, std::vector<int>& insert);
void insertAndWriteForEach(std::vector<int>& heap, int i);
void printHeap(std::vector<int> heap);
void printHeap(std::string text, std::vector<int> heap);

int main() {
    std::string taskOne = "DISTRIBUSJON";
    std::string taskTwo = "KOMPLIKASJON";
    std::vector<int> taskThree = {94, 91, 86, 77, 52, 71, 82, 52, 33, 41, 47, 54, 29, 38};
    std::vector<int> taskThreeInsert = {89, 88, 0, 0, -24};
    std::string taskFour = "HEAPSORTING";

    const int one = taskOne.length();
    const int two = taskTwo.length() - 1;
    const int four = taskFour.length();

    std::cout << "Before shellsort:\t" << taskOne << "\n";
    shellSort(taskOne, one);
    std::cout << "After shellsort:\t" << taskOne << "\n";

    std::cout << "\nBefore quicksort:\t" << taskTwo << "\n";
    quickSort(taskTwo, 0, two);
    std::cout << "After quicksort:\t" << taskTwo << "\n";
    
    printHeap("\nBefore heap:\t\t", taskThree);
    insertAndWriteHeap(taskThree, taskThreeInsert);
    printHeap("After heap:\t\t", taskThree);
    
    std::cout << "\nBefore heapsort:\t" << taskFour << "\n";
    heapSort(taskFour, four);
    std::cout << "After heapsort:\t\t" << taskFour << "\n";

    return 0;
}

void shellSort(std::string& arr, const int n) {
    int  i, j, h;
    char value;

    for (h = 1;  h <= n / 9;  h = 3 * h + 1);

    while (h > 0)  {
        for (i = h + 1;  i < n;  i++) {
            value = arr[i];
            j = i;

            while (j >= h  &&  arr[j - h] > value) {
                arr[j] = arr[j-h];
                j -= h;
            }

            arr[j] = value;
            std::cout << "\t\t\t" << arr << " h: " << h << " i: " << i << '\n';
        }

        h /= 3;
    }
}

void swap(char& charOne, char& charTwo) {
    char temp = charOne;
    charOne = charTwo;
    charTwo = temp;
}

int partition(std::string& arr, const int left, const int right) {
    if (right > left) {
        int i, j;
        char partitionElement;

        partitionElement = arr[right];
        i = left-1;
        j = right;
        while (true) {

            while (arr[++i] < partitionElement);
            while (arr[--j] > partitionElement);
            if (i >= j)  break;
            swap(arr[i], arr[j]);
        }

        swap(arr[i], arr[right]);

        return i;
    }
    return 0;
}

void quickSort(std::string& arr, const int left, const int right)  {
    if (right > left) {
        int i = partition(arr, left, right);
        quickSort(arr, left, i - 1);
        quickSort(arr, i + 1, right);
        std::cout << "\t\t\t" << arr << "\n";
    }
}

void downHeap(std::string& arr, const int ant, int keyNr) {
    char value = arr[keyNr];

    while (keyNr < ant / 2) {
        int j = 2 * keyNr + 1;

        if (j + 1 < ant && arr[j] < arr[j + 1]) {
            j++;
        }

        if (value >= arr[j]) {
            break;
        }

        arr[keyNr] = arr[j];
        keyNr = j;
    }

    arr[keyNr] = value;
}

void heapSort(std::string& arr, int n) {
    for (int keyNr = n / 2 - 1; keyNr >= 0; keyNr--) {
        downHeap(arr, n, keyNr);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        downHeap(arr, i, 0);
        std::cout << "\t\t\t" << arr << "\n";
    }
}

void insertAndWriteHeap(std::vector<int>& heap, std::vector<int>& insert) {
    for (int i = 0; i < std::end(insert) - std::begin(insert); i++) {
        insertAndWriteForEach(heap, insert[i]);
    }
}

void insertAndWriteForEach(std::vector<int>& heap, int i) {
    if (i > 0) {
        heap.push_back(i);
        std::push_heap(heap.begin(), heap.end());
        printHeap("Heap after insert(" + std::to_string(i) + ")\t", heap);
    } else if (i == 0) {
        std::pop_heap(heap.begin(), heap.end());
        heap.pop_back();
        printHeap("Heap after remove()\t", heap);
    } else {
        heap[0] = abs(i);
        std::make_heap(heap.begin(), heap.end());
        std::string text = "Heap after replace(" + std::to_string(abs(i)) + ")\t";
        printHeap(text, heap);
    }
}

void printHeap(std::string text, std::vector<int> heap) {
    std::cout << text << ": ";

    for (int num : heap) {
        std::cout << num << " ";
    }

    std::cout << "\n";
}
