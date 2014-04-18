#include <iostream>
using namespace std;

int main()
{
    struct f{
        int num;
        int num2;
    };

    f s;
    s.num = 1;
    s.num2 = 2;
    ((f *)&(s.num2))->num = 3;
    cout << s.num2 << endl;
    

    int array[5];
    array[0] = 128;
    ((short *)array)[1] = 1;
    cout << array[0] << endl;
}
