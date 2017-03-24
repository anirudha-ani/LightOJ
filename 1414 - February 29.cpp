#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int test_no , date1 , year1, date2 , year2 , start_year , end_year;
    string month1 , comma1 , month2 , comma2 ;
    scanf("%d", &test_no);


    for(int i = 0 ; i < test_no ; i++)
    {
        cin >> month1 >> date1 >> comma1 >> year1 ;
        cin >> month2 >> date2 >> comma2 >> year2 ;

        if(month1 == "January" || (month1 == "February"))
        {
            //cout << "Working"<<endl;123
            start_year = year1;
        }
        else
        {
            start_year = year1 +1 ;
        }

        if(month2 == "January" || (month2 == "February" && date2<=28))
        {
            end_year = year2 - 1;
        }
        else
        {
            end_year = year2 ;
        }
        //cout << start_year << " " << end_year << endl;
        int  count = ((end_year)/4 - (end_year)/100 + (end_year)/400) - ((start_year -1 )/4 - (start_year - 1)/100 + (start_year-1)/400);

        printf("Case %d: %d\n", i + 1 , count);
    }
    return 0;
}
