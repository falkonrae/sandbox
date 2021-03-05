#include <iostream>
using namespace std;

int ft_switch(int cases, int z, int m, int r)
{
    if (cases > 0)
    {
        while (cases == 1)
        {
            z = m;
            break;
        }
        while (cases == 2)
            cases = 3;
        while (cases == 3)
        {
            z = m + r;
            break;
        }
    }
    else
         z = m - r;
    return z;
}

int main()
{
    int y = 0, n = 5, x = 2;
    int z = 0, m = 5, r = 2;
    switch(0)
    {
        case 1:
            y = n;
            break;
        case 2:
        case 3:
            y = n + x;
            break;
        default: 
            y = n - x;
            break;
    }
    cout << "my switch = " << ft_switch(0, z, m, r) << "\n";
    cout << "switch = " << y << "\n";
}