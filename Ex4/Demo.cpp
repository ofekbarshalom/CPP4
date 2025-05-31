#include <iostream>
#include "MyContainer.hpp"

using namespace std;

using namespace container;
int main() {

    MyContainer<int> container;
    container.add(7);
    container.add(15);
    container.add(6);
    container.add(1);
    container.add(2);

    cout << "Size of container: " << container.size() << endl;

    for (auto it = container.begin_ascending_order(); it != container.end_ascending_order(); ++it) {
        cout << *it << ' ';   // 1 2 6 7 15
    }
    cout << endl;

    for (auto it = container.begin_descending_order(); it != container.end_descending_order(); ++it) {
        cout << *it << ' ';  // 15 7 6 2 1
    }
    cout << endl;

    for (auto it = container.begin_side_cross_order(); it != container.end_side_cross_order(); ++it) {
        cout << *it << ' ';  // 1 15 2 7 6
    }
    cout << endl;

    for (auto it = container.begin_reverse_order(); it != container.end_reverse_order(); ++it) {
        cout << *it << ' ';  // 2 1 6 15 7
    }
    cout << endl;

    for (auto it = container.begin_order(); it != container.end_order(); ++it) {
        cout << *it << ' ';  // 7 15 6 1 2
    }
    cout << endl;

    for (auto it = container.begin_middle_out_order(); it != container.end_middle_out_order(); ++it) {
        cout << *it << ' ';  // 6 15 1 7 2
    }
    cout << endl;

  

    return 0;
}
