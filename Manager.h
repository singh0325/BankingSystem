#pragma once
#include <vector>
#include <algorithm>
#include <functional>

template <typename T>
class Manager {
private:
    std::vector<T*> items;  // Collection of pointers to managed objects

public:
    // Destructor cleans up all dynamically allocated objects
    ~Manager() {
        for (auto item : items) {
            delete item;
        }
    }

    // Appends new item to the collection
    void add(T* item) {
        items.push_back(item);
    }

    // Calls display() on every item in the collection
    void displayAll() const {
        for (const auto& item : items) {
            item->display();
        }
    }

    // Sorts items ascending by their balance using lambda comparator
    void sortByBalance() {
        std::sort(items.begin(), items.end(),
            [](T* a, T* b) {
                return a->getBalance() < b->getBalance();
            });
    }

    // Returns first item matching predicate, or nullptr if none found
    T* findIf(std::function<bool(T*)> condition) {
        auto it = std::find_if(items.begin(), items.end(), condition);
        return (it != items.end()) ? *it : nullptr;
    }

    // Returns item at index with bounds checking
    T* get(size_t index) {
        return items.at(index); // only if invalid
    }

    // Returns total number of managed items
    size_t size() const {
        return items.size();
    }
};
