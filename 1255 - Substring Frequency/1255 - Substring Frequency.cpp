/**
Knuth Morris Pratt aka KMP Algorithm

Thanks to - Niloy Datta from Jahangirnagar University for teaching this awesome algorithm

And also thanks to Tushar Roy from youtube

Resource -

Part 1 - https://www.youtube.com/watch?v=GTJr8OvyEVQ
Part 2 - https://www.youtube.com/watch?v=KG44VoDtsAA
**/

#include <bits/stdc++.h>

using namespace std;

int KMP_Number[1000005];

void buildingTemporarySubArray(string input_String , int KMP_Number[])
{
    int length = input_String.length();

    int i = 0 , j = 1 ;

    KMP_Number[0] = 0;

    while(j != length)
    {
        if(input_String[i] == input_String[j])
        {
            KMP_Number[j] = i + 1;
            i++;
            j++;

        }
        else if (i == 0)
        {
            KMP_Number[j] = 0;
            j++;

        }
        else
        {
            i = KMP_Number[i-1];

        }
    }
}

long long int matchCounter(string mainString , string patternString)
{
    long long int counter = 0 ;

    int mainString_length = mainString.length();
    int patternString_length = patternString.length();



    buildingTemporarySubArray(patternString , KMP_Number);

    int i = 0 , j = 0 ;

    while(i != mainString_length)
    {
        if(patternString[j] == mainString[i])
        {
            i++;
            j++;


            if(j == patternString_length)
            {
                counter++;
                j = KMP_Number[j - 1];
            }
        }
        else if(j == 0)
        {
            i++;
        }
        else
        {
            j = KMP_Number[j - 1];
        }
    }

    return counter ;
}

int main()
{
    ios::sync_with_stdio(false);

    int test_case ;
    string fake ;

    cin >> test_case ;
    getline(cin , fake);


    string mainString ,  patternString;

    for(int i = 0 ; i < test_case ; i++)
    {
         getline(cin , mainString);
        getline(cin , patternString);

        cout << "Case " << i+1 << ": " << matchCounter(mainString , patternString) << endl;
    }

    return 0 ;
}

