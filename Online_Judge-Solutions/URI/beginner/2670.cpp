#include <iostream>

using namespace std;

int main()
{
    int a1, a2, a3, mini;
    cin >> a1 >> a2 >> a3;
    mini = 2*a2 + 4*a3;
    mini = min(mini, 2*a1 + 2*a3);
    mini = min(mini, 4*a1 + 2*a2);
    cout << mini << endl;
    return 0;
}
