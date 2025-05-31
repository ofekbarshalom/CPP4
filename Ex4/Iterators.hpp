#ifndef ITERATORS_HPP
#define ITERATORS_HPP

#include <vector>
#include <algorithm>
#include "MyContainer.hpp"

using namespace std;

namespace container {

    // Basic Iterator (Order Iterator)
    template <typename T>

    class BaseIterator {
        protected:
            vector<T> orderedElements;
            typename vector<T>::const_iterator current;

        public:
            BaseIterator(const vector<T>& elements): orderedElements(elements), current(orderedElements.begin()) {}

            const T& operator*() const {
                return *current;
            }

            BaseIterator& operator++() {
                ++current;
                return *this;
            }

            bool operator==(const BaseIterator& other) const {
                return current == other.current;
            }

            bool operator!=(const BaseIterator& other) const {
                return !(*this == other);
            }

            BaseIterator begin() const {
                BaseIterator it(orderedElements);
                it.current = it.orderedElements.begin();
                return it;
            }

            BaseIterator end() const {
                BaseIterator it(orderedElements);
                it.current = it.orderedElements.end();
                return it;
            }
    };

    // Ascending Order Iterator
    template <typename T>
    class AscendingOrderIterator : public BaseIterator<T> {
        public:
            AscendingOrderIterator(const vector<T>& input): BaseIterator<T>(prepare_sorted(input)) {}
            AscendingOrderIterator(const class MyContainer<T>& container): AscendingOrderIterator(container.getElements()) {}

        private:
            static vector<T> prepare_sorted(const vector<T>& input) {
                vector<T> temp = input;
                sort(temp.begin(), temp.end());
                return temp;
            }
    };

    // Descending Order Iterator
    template <typename T>
    class DescendingOrderIterator : public BaseIterator<T> {
        public:
            DescendingOrderIterator(const vector<T>& input): BaseIterator<T>(prepare_sorted(input)) {}
            DescendingOrderIterator(const class MyContainer<T>& container): DescendingOrderIterator(container.getElements()) {}

        private:
            static vector<T> prepare_sorted(const vector<T>& input) {
                vector<T> temp = input;
                sort(temp.begin(), temp.end(), greater<T>());
                return temp;
            }
    };

    // Side cross Order Iterator
    template <typename T>
    class SideCrossOrderIterator : public BaseIterator<T> {
        public:
            SideCrossOrderIterator(const vector<T>& input): BaseIterator<T>(prepare_sidecross(input)) {}
            SideCrossOrderIterator(const class MyContainer<T>& container): SideCrossOrderIterator(container.getElements()) {}

        private:
            static vector<T> prepare_sidecross(const vector<T>& input) {
                vector<T> temp = input;
                sort(temp.begin(), temp.end());

                vector<T> result;
                size_t left = 0, right = temp.size() - 1;

                while (left <= right) {
                    if (left == right) {
                        result.push_back(temp[left]);
                    } else {
                        result.push_back(temp[left]);
                        result.push_back(temp[right]);
                    }
                    ++left;
                    if (right == 0) break; // to prevent underflow
                    --right;
                }

                return result;
            }
    };

    // Reverse Order Iterator
    template <typename T>
    class ReverseOrderIterator : public BaseIterator<T> {
        public:
            ReverseOrderIterator(const vector<T>& input): BaseIterator<T>(prepare_reverse(input)) {}
            ReverseOrderIterator(const class MyContainer<T>& container): ReverseOrderIterator(container.getElements()) {}

        private:
            static vector<T> prepare_reverse(const vector<T>& input) {
                vector<T> temp = input;
                reverse(temp.begin(), temp.end());
                return temp;
            }
    };

    // Middle Out Order Iterator
    template <typename T>
    class MiddleOutOrderIterator : public BaseIterator<T> {
        public:
            MiddleOutOrderIterator(const vector<T>& input): BaseIterator<T>(prepare_middle_out(input)) {}
            MiddleOutOrderIterator(const class MyContainer<T>& container): MiddleOutOrderIterator(container.getElements()) {}

        private:
            static vector<T> prepare_middle_out(const vector<T>& input) {
                vector<T> temp = input;
                sort(temp.begin(), temp.end());

                vector<T> result;
                int n = temp.size();
                int mid = n / 2;

                if (n == 0) return result;

                result.push_back(temp[mid]);

                int left = mid - 1;
                int right = mid + 1;

                while (left >= 0 || right < n) {
                    if (right < n) result.push_back(temp[right++]);
                    if (left >= 0) result.push_back(temp[left--]);
                }

                return result;
            }
    };



} // namespace container

#endif // ITERATORS_HPP
