#include <bits/stdc++.h>

using namespace std;

class NumberContainers {
public:
    unordered_map<int, int> index_to_number;
    map<int, set<int>> number_to_index;
    NumberContainers() {}

    void change(int index, int number) {
        if (index_to_number[index]) {
            int value = index_to_number[index];
            number_to_index[value].erase(index);
        }
        index_to_number[index] = number;
        number_to_index[number].insert(index);
    }

    int find(int number) {
        return number_to_index[number].size() ? *number_to_index[number].begin()
                                              : -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */