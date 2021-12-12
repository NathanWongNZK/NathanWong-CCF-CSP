/*
 This code only gets 70% of the score.
 I am too naive. I don't know the better solutions.
*/

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

vector<int> my_array;

int count_non_zero_segments()
{
     // -----Initial Version of Count_Non_zero_Segments-----
    int temp_non_zero_count = 0;
    for(int i = 0;i < my_array.size(); i++)
    {
        if(my_array[i] != 0)
        {
            temp_non_zero_count++;
            int j = i;
            for(; j < my_array.size(); j++)
                if(my_array[j] == 0)
                    break;
            i = j;      // IMPORTANT!
        }
    }
    return temp_non_zero_count;
    // ----------Count End Here----------
}

// TODO
void modify_my_array(int p)
{
    for(int i = 0;i < my_array.size(); i++)
    {
        if(my_array[i] != 0 && my_array[i] < p)
            my_array[i] = 0;
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int ans = 0;
   
    my_array.reserve(1000);

    int n = 0;
    cin >> n;

    int temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        my_array.push_back(temp);
    }
    
    int p = 2;      // p starts from 2.
    int max_count_before = count_non_zero_segments();
    int count_now = 0;
    ans = max_count_before;
    
    set<int> array_elems(my_array.begin(), my_array.end());
    
    for(set<int>::iterator iter = array_elems.begin(); iter != array_elems.end(); ++iter)
    {
        p = (*iter) + 1;
        modify_my_array(p);

        count_now = count_non_zero_segments();
        if(count_now > max_count_before)
            max_count_before = count_now;
    }
    
    ans = max_count_before;
    cout << ans << endl;
}
