/*
 * Title:   Liner Clustering
 * Author:  Nathan Wong
 * Date:    2021.11.24
 */
#include <iostream>
using namespace std;

const int N = 1000;

struct Point{
    int x;
    int y;
} PointA[N], PointB[N];
int count_A, count_B;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int judge_flag = 1, final_output_flag = 1;
    int n, m;   // n for point count, m for query count.
    count_A = 0, count_B = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        char point_type;
        cin >> x >> y >> point_type;
        if(point_type == 'A')
            PointA[count_A].x = x, PointA[count_A++].y = y;
        else
            PointB[count_B].x = x, PointB[count_B++].y = y;
    }

    for(int i = 0; i < m; i++)      // for each query input
    {
        final_output_flag = 1;      // Extreme important!!!
        
        int theta0, theta1, theta2;
        cin >> theta0 >> theta1 >> theta2;
        
        // ----------------------Handle the exceptions----------------------
        if(theta2 == 0)
        {
            float const_x = -( (float)theta0 / theta1 );
            judge_flag = (PointA[0].x > const_x);
            for(int i = 0; i < count_A; i++)
            {
                if( (PointA[i].x > const_x) != judge_flag )
                {
                    final_output_flag = 0;
                    break;
                }
            }
            
            for(int i = 0; i < count_B; i++)
            {
                if( (PointB[i].x > const_x) == judge_flag)
                {
                    final_output_flag = 0;
                    break;
                }
            }
            
            if(final_output_flag == 0)
                cout << "No\n";
            else
                cout << "Yes\n";
            
            continue;
        }
        
        float k = -((float)theta1/theta2);
        float b = -((float)theta0/theta2);
        float y_star;

        // ---------------Process for PointA---------------
        y_star = k*PointA[0].x + b;
        judge_flag = (PointA[0].y > y_star);

        for(int i = 0; i < count_A; i++)    // for each Point in A
        {
            int x = PointA[i].x;
            int y = PointA[i].y;
            y_star = k*x + b;
            if((y > y_star) != judge_flag)
            {
                final_output_flag = 0;
                break;
            }
        }

        if(final_output_flag == 0)
        {
            cout << "No\n";
            continue;
        }

        // ---------------Process for PointB---------------------
        for(int i = 0; i < count_B; i++)
        {
            int x = PointB[i].x;
            int y = PointB[i].y;
            y_star = k*x + b;
            if((y > y_star) == judge_flag)
            {
                final_output_flag = 0;
                break;
            }
        }

        if(final_output_flag == 1)
            cout << "Yes\n";
        else
            cout << "No\n";

    }

}


/* --------TEST DATA--------
9 3
1 1 A
1 0 A
1 -1 A
2 2 B
2 3 B
0 1 A
3 1 B
1 3 B
2 0 A

0 2 -3
-3 0 2
-3 1 1

*/