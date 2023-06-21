#include "sortingUtils.h"

#include <random>
#include <array>
#include <functional>

std::vector<int> generateRandomList(std::size_t list_size) {
    std::vector<int> list{};
    list.resize(list_size);

    for (int i = 0; i < list.size(); ++i) {
        list[i] = i + 1;
    }

    std::random_device r;
    std::mt19937 random_generator(r());
    std::shuffle(list.begin(), list.end(), random_generator);

    return list;
}

bool isVectorSorted(const std::vector<int> &list) {
    for (std::size_t i = 0; i < list.size() - 1; ++i) {
        if (list[i] > list[i + 1]) {
            return false;
        }
    }

    return true;
}

int getOperationIndex(int a, int b, int listSize) {
    if (a < b) {
        std::swap(a, b);
    }

    return a * listSize + b;
}

std::set<int> insertionSort(std::vector<int> items) {
    std::set<int> operations;

    for (std::size_t i = 1; i < items.size(); ++i) {
        for (std::size_t j = i; j > 0 && items[j - 1] > items[j]; --j) {
            std::swap(items[j], items[j - 1]);
            operations.insert(getOperationIndex(items[j], items[j - 1], (int) items.size()));
        }
    }

    return operations;
}

std::set<int> bubbleSort(std::vector<int> items) {
    std::set<int> operations;

    for (int i = 0; i < items.size(); ++i) {
        for (int j = 0; j < items.size() - 1; ++j) {
            if (items[j + 1] < items[j]) {
                std::swap(items[j + 1], items[j]);
                operations.insert(getOperationIndex(items[j], items[j + 1], (int) items.size()));
            }
        }
    }

    return operations;
}

std::set<int> selectionSort(std::vector<int> items) {
    std::set<int> operations;

    for (std::size_t i = 0; i < items.size(); ++i) {
        std::size_t min_index = i;
        for (std::size_t j = i + 1; j < items.size(); ++j) {
            if (items[j] < items[min_index]) {
                min_index = j;
            }
        }

        if (min_index != i) {
            std::swap(items[i], items[min_index]);
            operations.insert(getOperationIndex(items[i], items[min_index], (int) items.size()));
        }
    }

    return operations;
}

#include <iostream>

std::string determineWhichSort(std::vector<int> list, std::set<int> operations) {
    using SortFunction = std::function<std::set<int>(std::vector<int>)>;

    std::array<std::pair<std::string, SortFunction>, 3> sorts{
            {
                    {"insertion sort", insertionSort},
                    {"selection sort", selectionSort},
                    {"bubble sort", bubbleSort}
            }};

    int minDiff = std::numeric_limits<int>::max();
    std::string sortName{};

    for (auto &[name, sort]: sorts) {
        std::set<int> swapOperations = sort(list);

        int occurrences = 0;
        for (auto op: operations) {
            occurrences += swapOperations.contains(op);
        }

        int additionalDiff = (int) operations.size() - (int) swapOperations.size();
        int newDiff = (int) swapOperations.size() - occurrences + additionalDiff;

        if(newDiff < minDiff) {
            minDiff = newDiff;
            sortName = name;
        }
    }

    if(minDiff > 5) {
        return "bogo sort";
    }

    return sortName;
}
