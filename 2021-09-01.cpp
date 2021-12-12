#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

const int N = 100000;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int A_MAX = 0;
    int A_MIN = 0;

    int n = 0;
    cin >> n;

    int before = 0;
    int now = 0;

    // Special initial sequence:
    if( n > 0)
    {
        cin >> now;
        before = now;
        A_MAX += now;
        A_MIN += now;
    }

    for(int i = 1; i < n; i++)
    {
        cin >> now;
        if(now != before)
        {
            A_MAX += now;
            A_MIN += now;
        }
        else    // now == before
        {
            A_MAX += now;
            A_MIN += 0;
        }
        before = now;       
    }
    cout << A_MAX << endl << A_MIN;
}