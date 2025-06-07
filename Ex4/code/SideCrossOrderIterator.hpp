// ofekbarshalom@gmail.com

#ifndef SIDECROSS_ORDER_ITERATOR_HPP
#define SIDECROSS_ORDER_ITERATOR_HPP

#include <vector>
#include <algorithm>
#include <cstddef>

using namespace std;

namespace container {

    template<typename T>
    class MyContainer;

    template<typename T>
    class SideCrossOrderIterator {

        private:
            const MyContainer<T>& container;
            vector<size_t> sideCrossIndices;
            size_t pos;

            void build_order() {
                size_t n = container.size();
                vector<size_t> sortedIndices(n);
                for (size_t i = 0; i < n; ++i) {
                    sortedIndices[i] = i;
                }

                sort(sortedIndices.begin(), sortedIndices.end(),
                    [this](size_t a, size_t b) {
                        return container.elements[a] < container.elements[b];
                    });

                size_t left = 0;
                size_t right = n - 1;
                while (left <= right) {
                    sideCrossIndices.push_back(sortedIndices[left]);
                    if (left != right)
                        sideCrossIndices.push_back(sortedIndices[right]);
                    ++left;
                    if (right > 0) --right; else break;
                }
            }

        public:
            SideCrossOrderIterator(const MyContainer<T>& cont, size_t start_pos = 0): container(cont), pos(start_pos) {
                build_order();
            }

            SideCrossOrderIterator(const SideCrossOrderIterator& other) = default;
            SideCrossOrderIterator& operator=(const SideCrossOrderIterator& other) = default;
            ~SideCrossOrderIterator() = default;

            const T& operator*() const {
                if (pos >= container.size()) {
                    throw out_of_range("Iterator out of bounds");
                }
                return container.elements[sideCrossIndices[pos]];
            }

            SideCrossOrderIterator& operator++() {
                if (pos >= container.size()) {
                    throw out_of_range("Cannot increment iterator past end");
                }
                ++pos;
                return *this;
            }

            SideCrossOrderIterator operator++(int) {
                SideCrossOrderIterator temp = *this;
                ++(*this);
                return temp;
            }

            SideCrossOrderIterator& operator--() {
                if (pos == 0) {
                    throw out_of_range("Cannot decrement iterator before start");
                }
                --pos;
                return *this;
            }

            SideCrossOrderIterator operator+(int n) const {
                SideCrossOrderIterator temp = *this;
                temp.pos += n;
                if (temp.pos > container.size()) {
                    throw out_of_range("Addition past end");
                }
                return temp;
            }

            SideCrossOrderIterator operator-(int n) const {
                SideCrossOrderIterator temp = *this;
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
                return container.elements[sideCrossIndices[index]];
            }

            bool operator==(const SideCrossOrderIterator& other) const {
                return pos == other.pos && &container == &other.container;
            }

            bool operator!=(const SideCrossOrderIterator& other) const {
                return !(*this == other);
            }
    };

} // namespace container

#endif
