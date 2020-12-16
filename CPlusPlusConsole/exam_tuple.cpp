#include <iostream>
#include <string>
#include <tuple>
////////////////////////////





using namespace std;
decltype(auto) GetScore() {
    int id = 10;
    string str = "viva";
    auto tmp = std::make_tuple(id, str);
    return tmp;
}

int main_tuple()
{
    auto score = GetScore();

    cout << std::get<0>(score) << endl;
    cout << std::get<1>(score) << endl;
    return 0;
}
