#include <bits/stdc++.h>


using namespace std;

int trieTable[100005][60];
int counter[100005];
int depth = 1 ;

void insert(char *input , int length)
{

    int index = 0;

    int currLevel = 0;
    for(int i = 0 ; i < length ; i++)
    {
        if(input[i] >= 'A' && input[i] <= 'Z')
        {
            index = input[i] - 'A' ;
        }
        else
        {
            index = input[i] - 'a' + 26;
        }

        if(trieTable[currLevel][index] != -1)
        {
            currLevel = trieTable[currLevel][index];
        }
        else
        {
            memset(trieTable[depth] , -1 , sizeof(trieTable[depth]));
            counter[depth] = 0;
            trieTable[currLevel][index] = depth;
            currLevel = depth;
            depth++;
        }
    }
    counter[currLevel]++;
}

int find(char *input , int length )
{
    int index = 0;

    int currLevel =  0;
    for(int i = 0 ; i < length ; i++)
    {
        if(input[i] >= 'A' && input[i] <= 'Z')
        {
            index = input[i] - 'A' ;
        }
        else
        {
            index = input[i] - 'a' + 26;
        }

        if(trieTable[currLevel][index] != -1)
        {
            currLevel = trieTable[currLevel][index];
        }
        else
        {
            return 0;
        }
    }
     return counter[currLevel];
}


int main(int argc, const char * argv[])
{
    int T , n ;

    string input , word;

    scanf("%d", &T);

    for(int i = 0 ; i < T ; i++)
    {
        memset(trieTable[0] , -1 , sizeof(trieTable[0]));
        counter[0] = 0 ;
        counter[1] = 0;
        depth = 1;

        scanf("%d", &n);

        for(int j = 0 ; j < n ; j++)
        {
            char str[100+5];
            scanf("%s",str);

            int len = (int) strlen(str);
            if( len > 3 ) sort( str+1, str+(len-1) );

            insert(str , len);
        }
        scanf("%d\n", &n);
        printf("Case %d:\n",i+1);

        char Sentence[10000+5],word[10000+5];



        for(int j = 0 ; j < n ; j++)
        {
            int ans = 1;

            gets(Sentence);
            stringstream ss( Sentence );


            while(ss>>word)
            {
                int len2 = (int)strlen(word);
                if( len2 > 3 ) sort( word+1, word+(len2-1) );
                ans *= find(word , len2);
            }

            printf("%d\n",ans);
        }
    }
    return 0;
}
