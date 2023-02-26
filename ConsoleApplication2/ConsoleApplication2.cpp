#include <iostream>
#include <cstring>
using namespace std;
//open the file using fopen
//read every number, conbvert it to int and add it tot the sum


char mystring[250];

void conv(char mystring[], int&sum)
{
    int temp = 0;
    for(int  i = 0; i < strlen(mystring); ++i)
        if(mystring[i] >= 48 and mystring[i] <= 57)
            temp = temp *10 +  mystring[i]-48;
    sum+=temp;
}

void f1()
{
    FILE * pFile;
    pFile = fopen("‪../../in.txt", "r");
    int ans = 0;
    if(pFile!=NULL)
        while (fgets(mystring, 250, pFile))
            conv(mystring, ans);
    printf("%d", ans);
    fclose (pFile);
}

void sortwords(char a[])
{
    char mat[100][200];
    int ind = 0;
    char*p;
    p = strtok(a, " ");
    while(p)
    {
        strcpy(mat[ind++], p);
        p = strtok(NULL, " ");
    }
    for(int i = 0; i < ind-1; ++i)
        for(int j = i+1; j < ind; ++j)
            if(strlen(mat[i])<strlen(mat[j]))
                swap(mat[i], mat[j]);
            else if(strlen(mat[i]) == strlen(mat[j]) and strcmp(mat[i], mat[j]) > 0)
                swap(mat[i], mat[j]);
    for(int i = 0; i < ind; ++i)
        printf("%s\n",mat[i]);
}

void f2()
{
    FILE* pFile;
    pFile = fopen("E:\\prinfo\\oop\\oop\\sentence.txt", "r");///??????
    if(pFile!= NULL)
    {
        char a[200]="";
        while (!feof(pFile))
        fscanf(pFile,"%[^\n]\n", a);
        printf("%s\n", a);
        sortwords(a);
        fclose(pFile);
    }
    else
    {
        printf("File does not exist");
    }
}

bool isPrime(int n)
{
    for (int tr=2; tr < n/2+1; tr++)
        if ((n % tr ) == 0)//and n<2
            return false;
    return true;
}

void f3()
{
    int n;
    cout << "Enter a number:";
    cin >> n;
    if (isPrime(n))
        cout << n << " is prime !";
    else
        cout << n << " is NOT prime !";
}

int main()
{
    //f1();
    //f2();
    f3();
    return 0;
}
