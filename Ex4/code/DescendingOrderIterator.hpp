// ofekbarshalom@gmail.com

#ifndef DESCENDING_ORDER_ITERATOR_HPP
#define DESCENDING_ORDER_ITERATOR_HPP

#include <vector>
#include <algorithm>
#include <cstddef>

using namespace std;

namespace container {

    template<typename T>
    class MyContainer;

    template<typename T>
    class DescendingOrderIterator {

        private:
            const MyContainer<T>& container;
            vector<size_t> sortedIndices;
            size_t pos;

            void build_indices() {
                sortedIndices.resize(container.size());
                for (size_t i = 0; i < container.size(); ++i) {
                    sortedIndices[i] = i;
                }
                sort(sortedIndices.begin(), sortedIndices.end(),
                    [this](size_t a, size_t b) {
                        return container.elements[a] > container.elements[b];
                    });
            }

        public:
            DescendingOrderIterator(const MyContainer<T>& cont, size_t start_pos = 0): container(cont), pos(start_pos) {
                build_indices();
            }

            DescendingOrderIterator(const DescendingOrderIterator& other) = default;
            DescendingOrderIterator& operator=(const DescendingOrderIterator& other) = default;
            ~DescendingOrderIterator() = default;

            const T& operator*() const {
                if (pos >= container.size()) {
                    throw out_of_range("Iterator out of bounds");
                }
                return container.elements[sortedIndices[pos]];
            }

            DescendingOrderIterator& operator++() {
                if (pos >= container.size()) {
                    throw out_of_range("Cannot increment iterator past end");
                }
                ++pos;
                return *this;
            }

            DescendingOrderIterator operator++(int) {
                DescendingOrderIterator temp = *this;
                ++(*this);
                return temp;
            }

            DescendingOrderIterator& operator--() {
                if (pos == 0) {
                    throw out_of_range("Cannot decrement iterator before start");
                }
                --pos;
                return *this;
            }

            DescendingOrderIterator operator+(int n) const {
                DescendingOrderIterator temp = *this;
                temp.pos += n;
                if (temp.pos > container.size()) {
                    throw out_of_range("Addition past end");
                }
                return temp;
            }

            DescendingOrderIterator operator-(int n) const {
                DescendingOrderIterator temp = *this;
                if (n > static_cast<int>(temp.pos)) {
                    throw out_of_range("Subtraction before start");
                }
                temp.pos -= n;
                return temp;
            }

            const T& operator[](size_t index) const {
                if (index >= container.size()) {
                    throw out_of_range("Index out of bounds");
                }
                return container.elements[sortedIndices[index]];
            }

            bool operator==(const DescendingOrderIterator& other) const {
                return pos == other.pos && &container == &other.container;
            }

            bool operator!=(const DescendingOrderIterator& other) const {
                return !(*this == other);
            }
    };

} // namespace container

#endif
