#pragma once
#include <vector>
#include <algorithm>
#include <functional>

template <typename T>
class Manager {
private:
    std::vector<T*> items;

public:
    ~Manager() {
        for (auto item : items) {
            delete item;
        }
    }

    void add(T* item) {
        items.push_back(item);
    }

    void displayAll() const {
        for (const auto& item : items) {
            item->display();
        }
    }

    void sortByBalance() {
        std::sort(items.begin(), items.end(),
            [](T* a, T* b) {
                return a->getBalance() < b->getBalance();
            });
    }

    T* findIf(std::function<bool(T*)> condition) {
        auto it = std::find_if(items.begin(), items.end(), condition);
        return (it != items.end()) ? *it : nullptr;
    }

    T* get(size_t index) {
        return items.at(index); // only if invalid
    }

    size_t size() const {
        return items.size();
    }
};