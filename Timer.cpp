#include <ctime>
#include <iostream>

int main()
{
    int start = clock();
    std::cout << double(clock() - start) / CLOCKS_PER_SEC << std::endl;
}