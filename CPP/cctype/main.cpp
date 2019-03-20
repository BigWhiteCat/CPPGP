#include <cctype>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::isalpha;
using std::islower;
using std::isspace;
using std::isupper;
using std::string;
using std::tolower;
using std::toupper;

int main() {
    string s("Hello World!!!");
    string::size_type punct_cnt = 0;

    for (string::size_type c = 0; c != s.size(); ++c) {
        if (ispunct(s[c])) {
            ++punct_cnt;
        }
    }

    cout << punct_cnt << " punctuation characters in " << s << endl;

    string orig = s;
    for (string::size_type c = 0; c != s.size(); ++c) {
        s[c] = toupper(s[c]);
    }
    cout << s << endl;

    s = orig;
    string::size_type index = 0;

    while (index != s.size() && !isspace(s[index])) {
        s[index] = toupper(s[index]);

        ++index;
    }
    cout << s << endl;
    return 0;
}
