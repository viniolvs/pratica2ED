#include <iostream>
#include "modulo.hpp"

int main(int argc, char const *argv[])
{
    List list;
    for (int i = 0; i < 10; i++)
    {
        list.pushBack(i);
    }
    list.print();
    for (int i = 0; i < 10; i++)
    {
        list.popFront();
        list.print();
    }
    cout << list.search(10) << endl;
    return 0;
}
