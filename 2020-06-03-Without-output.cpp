/*
 *  Title:  Markdown Render
 *  Author: Nathan Wong
 *  Date:   2021.12.1
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

void get_rid_of_space(string &str)
{
    str.erase(0, str.find_first_not_of(' ')); // L_Close & R_Open (What are U saying man)
    str.erase(str.find_last_not_of(' ') + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    //cin.tie(0);

    //--------------------------------------
    bool para_flag = false;
    bool is_last_line_empty = true;
    int line_count = 0;
    int width_count = 0;
    int para_count = 1;
    //--------------------------------------

    int width = 0;
    vector<string> text;
    string input_str;
    cin >> width;
    cin.get();
    while (cin.eof() != true)
    {
        getline(cin, input_str);
        get_rid_of_space(input_str);
        text.push_back(input_str);
    }

    vector<string>::iterator iter = text.begin();
    for (; iter != text.end(); ++iter)
    {
        if (para_flag == false)
        {
            if ((*iter) == "") // When first new empty line appears.
            {
                para_flag = true;
                continue;
            }
        }
        else
        {
            if ((*iter) != "") // When first non-empty line appears.
            {
                para_flag = false;
                width_count = 0;
                line_count += 2;
                para_count++;
                is_last_line_empty = true;
                //cout << endl << endl;
            }
            else // When entered empty sequence and line still empty.
                continue;
        }

        for (int i = 0; i < iter->length(); i++)
        {
            if (width_count == width)
            {
                width_count = 0;
                line_count++;
                //cout << endl;
                if((*iter)[i] == ' ')
                {
                    string temp_str = iter->substr(i);
                    iter->erase(i, temp_str.find_first_not_of(' '));                
                }
            }

            if (i == 0 && is_last_line_empty == false)
            {
                //cout << ' ';
                width_count++;
                if (width_count == width)
                {
                    width_count = 0;
                    line_count++;
                    //cout << endl;
                    if((*iter)[i] == ' ')
                    iter->erase(i, iter->find_first_not_of(' '));                        
                }
            }

           // cout << (*iter)[i];
            width_count++;
        }
        is_last_line_empty = false;

    }

    line_count++;
    cout << line_count;
}

/*

--------------------My Test Set------------------------
10
CSP

    

CSP is
a real realrealrealrealreal 
       competition.
    

Come    and    join    us   


-------------------CSP 1 Test Set----------------------
10
CSP

CSP is
a real realrealrealrealreal 
     competition.

   
Come   and   join   us   


-------------------CSP2 Test Set-----------------------
10
* CSP

*    CSP is
   * a real    
       competition.
*
   * Come!   and   join.   
*Tel:
* 12345
*
-------------------------------------------------------


*/
