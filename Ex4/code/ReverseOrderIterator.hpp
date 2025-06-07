// ofekbarshalom@gmail.com

#ifndef REVERSE_ORDER_ITERATOR_HPP
#define REVERSE_ORDER_ITERATOR_HPP

#include <vector>
#include <cstddef>

using namespace std;

namespace container {

    template<typename T>
    class MyContainer;

    template<typename T>
    class ReverseOrderIterator {

        private:
            const MyContainer<T>& container;
            size_t pos;

        public:
            ReverseOrderIterator(const MyContainer<T>& cont, size_t start_pos): container(cont), pos(start_pos) {}

            ReverseOrderIterator(const ReverseOrderIterator& other) = default;
            ReverseOrderIterator& operator=(const ReverseOrderIterator& other) = default;
            ~ReverseOrderIterator() = default;

            const T& operator*() const {
                if (pos >= container.size()) {
                    throw out_of_range("Iterator out of bounds");
                }
                return container.elements[pos];
            }

            ReverseOrderIterator& operator++() {
                if (pos == 0) {
                    pos = container.size();  // Mark as end
                } else {
                    --pos;
                }
                return *this;
            }

            ReverseOrderIterator operator++(int) {
                ReverseOrderIterator temp = *this;
                ++(*this);
                return temp;
            }

            ReverseOrderIterator& operator--() {
                if (pos >= container.size()) {
                    // Was at end(); bring to last element
                    pos = (container.size() > 0) ? container.size() - 1 : 0;
                } else {
                    ++pos;
                    if (pos >= container.size()) {
                        throw out_of_range("Cannot decrement past start");
                    }
                }
                return *this;
            }

            ReverseOrderIterator operator+(int n) const {
                if (n > static_cast<int>(pos)) {
                    throw out_of_range("Addition past end");
                }
                ReverseOrderIterator temp = *this;
                temp.pos -= n;
                return temp;
            }

            ReverseOrderIterator operator-(int n) const {
                ReverseOrderIterator temp = *this;
                temp.pos += n;
                if (temp.pos >= container.size()) {
                    throw out_of_range("Subtraction past beginning");
                }
                return temp;
            }

            const T& operator[](size_t index) const {
                if (index >= container.size()) {
                    throw out_of_range("Index out of bounds");
                }
                return container.elements[container.size() - 1 - index];
            }

            bool operator==(const ReverseOrderIterator& other) const {
                return pos == other.pos && &container == &other.container;
            }

            bool operator!=(const ReverseOrderIterator& other) const {
                return !(*this == other);
            }
    };

} // namespace container

#endif
