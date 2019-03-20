#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main() {
    string str("some string"), orig = str;
    if (!str.empty()) {
        cout << str[0] << endl;
    }

    if (!str.empty()) {
        str[0] = toupper(str[0]);
    }
    cout << str << endl;

    str = orig;

    if (str.begin() != str.end()) {
        string::iterator iter = str.begin();
        *iter = toupper(*iter);
    }
    cout << str << endl;

    str = orig;

    for (string::size_type index = 0; index != str.size() && !isspace(str[index]); ++index) {
        str[index] = toupper(str[index]);
    }
    cout << str << endl;

    str = orig;

    for (string::iterator iter = str.begin(); iter != str.end() && !isspace(*iter); ++iter) {
        *iter = toupper(*iter);
    }
    str = orig;

    return 0;
}
