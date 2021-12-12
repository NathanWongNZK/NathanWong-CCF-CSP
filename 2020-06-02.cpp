#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    // n is total dimensions
    int n, a, b;        // a for count_u and b for count_v
    cin >> n >> a >> b;

    unordered_map<int, int> A;
    long long ans = 0;
    int temp_index, temp_value;
    for(int i = 0; i < a; i++)
    {
        cin >> temp_index >> temp_value;
        A[temp_index] = temp_value;
    }
    for(int i = 0; i < b; i++)
    {
        cin >> temp_index >> temp_value;
        ans += A[temp_index]*temp_value;
    }
    cout << ans;
    return 0;

}