#ifndef MY_CONTAINER_HPP
#define MY_CONTAINER_HPP

#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

namespace container {

template <class T>
class MyContainer {
private:
    vector<T> elements;

public:
    void add(const T& value) {
        elements.push_back(value);
    }

    void remove(const T& value) {
        auto it = remove(elements.begin(), elements.end(), value);
        if (it == elements.end()) {
            throw runtime_error("Value not found in container");
        }
        elements.erase(it, elements.end());
    }

    size_t size() const {
        return elements.size();
    }

    friend ostream& operator<<(ostream& os, const MyContainer& container) {
        os << "[ ";
        for (const auto& val : container.elements) {
            os << val << " ";
        }
        os << "]";
        return os;
    }

    const vector<T>& getElements() const {
        return elements;
    }

    AscendingOrderIterator<T> begin_ascending_order() const {
        return AscendingOrderIterator<T>(*this).begin();
    }

    AscendingOrderIterator<T> end_ascending_order() const {
        return AscendingOrderIterator<T>(*this).end();
    }

    DescendingOrderIterator<T> begin_descending_order() const {
        return DescendingOrderIterator<T>(*this).begin();
    }

    DescendingOrderIterator<T> end_descending_order() const {
        return DescendingOrderIterator<T>(*this).end();
    }

    SideCrossOrderIterator<T> begin_side_cross_order() const {
        return SideCrossOrderIterator<T>(*this).begin();
    }

    SideCrossOrderIterator<T> end_side_cross_order() const {
        return SideCrossOrderIterator<T>(*this).end();
    }

    ReverseOrderIterator<T> begin_reverse_order() const {
        return ReverseOrderIterator<T>(*this).begin();
    }

    ReverseOrderIterator<T> end_reverse_order() const {
        return ReverseOrderIterator<T>(*this).end();
    }

    BaseIterator<T> begin_order() const {
        return BaseIterator<T>(elements).begin();
    }

    BaseIterator<T> end_order() const {
        return BaseIterator<T>(elements).end();
    }

    MiddleOutOrderIterator<T> begin_middle_out_order() const {
        return MiddleOutOrderIterator<T>(*this).begin();
    }

    MiddleOutOrderIterator<T> end_middle_out_order() const {
        return MiddleOutOrderIterator<T>(*this).end();
    }

};

} // namespace container

#endif // MY_CONTAINER_HPP
