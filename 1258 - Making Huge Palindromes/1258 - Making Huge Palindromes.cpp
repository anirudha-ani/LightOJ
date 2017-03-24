/**
    Problem Link - http://lightoj.com/volume_showproblem.php?problem=1258

    Solving Technique - I inverted the string and build a new String like this

    newString = <inverted string> <"#"> <main string>

    If we run KMP on this in the last index it will save the number
    which indicates what is the highest length of prefix of the inverted string
    that match with the suffix with the original string
    basically that length we don't want to be added

**/

#include <bits/stdc++.h>

using namespace std;

int KMP_Number[2000005];

void buildingTemporarySubArray(string input_String)
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



int main()
{
    ios::sync_with_stdio(false);

    int input_no , length;

    cin >> input_no;

    string inputString ,  fake , palindromeString;

    getline(cin , fake);

    for(int i = 0 ; i < input_no ; i++)
    {
        getline(cin , inputString);

        length = inputString.length();

        palindromeString = "";

        for(int j = length -1 ; j >= 0 ; j--)
        {
            palindromeString += inputString[j];

        }
        palindromeString += "#";
        palindromeString += inputString;
        buildingTemporarySubArray(palindromeString);

        int answer = length + length - KMP_Number[length * 2];

        cout << "Case " << i+1 << ": " << answer << endl;

    }

    return 0 ;
}
