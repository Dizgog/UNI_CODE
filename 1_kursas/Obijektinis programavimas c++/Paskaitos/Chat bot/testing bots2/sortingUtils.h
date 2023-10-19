#ifndef CHATBOT_SORTINGUTILS_H
#define CHATBOT_SORTINGUTILS_H

#include <vector>
#include <set>
#include <string>

std::vector<int> generateRandomList(std::size_t list_size);
bool isVectorSorted(const std::vector<int> &list);
std::string determineWhichSort(std::vector<int> list, std::set<int> operations);
int getOperationIndex(int a, int b, int listSize);

#endif //CHATBOT_SORTINGUTILS_H
