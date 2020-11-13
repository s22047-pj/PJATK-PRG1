#include <iostream>
using namespace std;

auto main() -> int
{
    string user_password;
    while (true)
    {
        cout << "enter password: ";
        cin >> user_password;
        if (user_password == "student"){
            break;
        }    
    }

    cout << "ok!";
    return 0;
}
