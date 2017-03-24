#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    int test_case;

    int people;

    int length , width , height ;

    string name , thief ,victim;

    int volume , max_volume , min_volume;

    cin >> test_case;

    for(int i = 0 ; i < test_case ; i++)
    {
        cin >> people ;
        max_volume = 0 ;
        min_volume = 99999999 ;
        for(int j = 0 ; j < people ; j++)
        {
            cin >> name >> length >> width >> height;

            volume = length * width * height;

            if(volume > max_volume)
            {
                max_volume = volume ;
                thief = name;
            }
            if(volume < min_volume)
            {
                min_volume = volume;
                victim = name;
            }
        }
        if(max_volume != min_volume)
        {
            cout << "Case "<<i+1<<": "<<thief<<" took chocolate from "<<victim<<endl;
        }
        else
        {
            cout << "Case "<<i+1<<": no thief"<<endl;
        }
    }
    return 0;
}
