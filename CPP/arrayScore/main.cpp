#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
    vector<unsigned> grades;

    const size_t sz = 11;
    unsigned scores[sz] = {};
    unsigned grade;

    while (cin >> grade) {
        if (grade <= 100) {
            ++scores[grade / 10];
        }
        grades.push_back(grade);
    }

    for (auto g = grades.cbegin(); g != grades.cend(); ++g) {
        cout << "*g"
             << " ";
    }
    cout << endl;

    for (size_t i = 0; i != sz; ++i) {
        cout << scores[i] << " ";
    }
    cout << endl;

    return 0;
}
