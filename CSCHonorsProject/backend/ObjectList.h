#ifndef OBJECTLIST_H
#define OBJECTLIST_H

#include <vector>

template <typename T>
class ObjectList {
private:
    std::vector<T> items;

public:
    void add(const T& item) {
        items.push_back(item);
    }

    std::vector<T>& getAll() {
        return items;
    }

    int size() const {
        return items.size();
    }
};

#endif // OBJECTLIST_H
