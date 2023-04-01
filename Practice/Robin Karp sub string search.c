#include<stdio.h>
#include "my string.h"
#include<math.h>

int substringsearch(char*,char*);

void main()
{
    char str[10],i;
    printf("ENTER THE MAIN STRING:");
    scanf("%s",str);

    char st[10];
    printf("ENTER THE SUB STRING TO BE SEARCHED:");
    scanf("%s",st);

    i=substringsearch(str,st);
    if(i!=-1) printf("THE SUB STRING IS AT %d",i+1);
    else printf("THE SUB STRING IS NOT FOUND...");
}

int substringsearch(char* str,char* st)
{
    int values[26];

    int n,m,i=1,a,hash1=0,hash2,prime=113;
    for(char z='a';z<='z';z++) { values[z]=i; i++; }

    n=strlength(str);
    m=strlength(st);

    for(i=0;i<m;i++)
    {
        hash1=hash1%prime+(values[st[i]]*pow(m,i))%prime;
    }

        for(i=0;i<m;i++)
    {
        hash2=hash2%prime+(values[str[i]]*pow(26,i))%prime;
    }

    if(m>n) return(-1);
    else
    {
        char s1[m];
        for(i=0;i<=n-m;i++)
        {
            strcopy(str,s1,i,m);
            if(hash1==hash2)
            {
                a=strcompare(s1,st);
                if(a==1) return(i);
            }
            hash2=hash2-(values[str[i+m]]*pow(26,m-1))%prime;
            hash2=(hash2*26);
            hash2=hash2%prime+(values[str[i+m])%prime;
        }return(-1);
    }
}
