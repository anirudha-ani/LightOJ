#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int case_no , report_no , previous , current , lies;

    scanf("%d", &case_no);

    for(int i = 0 ; i < case_no ; i++)
    {
        scanf("%d", &report_no);
        previous = 2;
        lies = 0;
        for(int j = 0 ; j < report_no ; j++)
        {
            scanf("%d", &current);
            if(current!=previous)
            {
                lies+= (current - previous)/5;
                if((current-previous)%5)
                    lies++;
                previous = current;
            }
        }
        printf("Case %d: %d\n",i+1 , lies);
    }
    return 0;
}
