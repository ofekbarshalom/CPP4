// ofekbarshalom@gmail.com

#ifndef ORDER_ITERATOR_HPP
#define ORDER_ITERATOR_HPP

#include <vector>
#include <cstddef>

using namespace std;

namespace container {

    template<typename T>
    class MyContainer;

    template<typename T>
    class OrderIterator {

        private:
            const MyContainer<T>& container;
            size_t pos;

        public:
            OrderIterator(const MyContainer<T>& cont, size_t start_pos = 0): container(cont), pos(start_pos) {}

            OrderIterator(const OrderIterator& other) = default;
            OrderIterator& operator=(const OrderIterator& other) = default;
            ~OrderIterator() = default;

            const T& operator*() const {
                if (pos >= container.size()) {
                    throw out_of_range("Iterator out of bounds");
                }
                return container.elements[pos];
            }

            OrderIterator& operator++() {
                if (pos >= container.size()) {
                    throw out_of_range("Cannot increment iterator past end");
                }
                ++pos;
                return *this;
            }

            OrderIterator operator++(int) {
                OrderIterator temp = *this;
                ++(*this);
                return temp;
            }

            OrderIterator& operator--() {
                if (pos == 0) {
                    throw out_of_range("Cannot decrement iterator before start");
                }
                --pos;
                return *this;
            }

            OrderIterator operator+(int n) const {
                OrderIterator temp = *this;
                temp.pos += n;
                if (temp.pos > container.size()) {
                    throw out_of_range("Addition past end");
                }
                return temp;
            }

            OrderIterator operator-(int n) const {
                OrderIterator temp = *this;
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
                return container.elements[index];
            }

            bool operator==(const OrderIterator& other) const {
                return pos == other.pos && &container == &other.container;
            }

            bool operator!=(const OrderIterator& other) const {
                return !(*this == other);
            }
    };

} // namespace container

#endif
