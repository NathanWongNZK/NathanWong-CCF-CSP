#include "bits/stdc++.h"

using namespace std;

int main()
{
    string output_str("Rocking!");
    cout << setiosflags(ios::left) << setw(6) << '*' << setw(4) << '|';
}














//------------------------------------------------------

/*
void get_rid_of_front_space(string &str)
{
    cout << str.find_first_not_of(' ') << endl;
    cout << str.find_last_not_of(' ') << endl;
    cout << str.size()<< endl;
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') + 1, str.size());   
}

int main()
{
    vector<string> text;
    string my_str;
    getline(cin, my_str);

    get_rid_of_front_space(my_str);
    while(getline(cin, input_str))
    {
        text.push_back(input_str);
    } 
    
    cout << "Process finished." << endl;
    return 0;
}

*/

//------------------------------------------------------

/* 
const int N = 1000;

struct Point{
    int x;
    int y;
}PointA[N], PointB[N];

int main()
{
    int count_A, count_B;
    int x = 20, y = 40;
    for(int i = 0; i < 10; i++)
    {
        if(true)
            PointA[i].x = i, PointA[i].y = i*10;
        printf("%d %d\n", PointA[i].x, PointA[i].y);
    }
    count_A = 10, count_B = 20;
    printf("%d %d\n",count_A, count_B);
}
 */
//------------------------------------------------------
/* 
int main()
{
    printf("\nSession Starts...\n");

    int n, m, h;
    scanf("%d %d %d", &n, &m, &h);
    //std::cin >> n >> m;
    printf("n is %d, m is %d\n", n, m);
    //std::cin >> h;
    printf("and here is leftbehind h %d", h);
}
*/