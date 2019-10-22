#include<stdio.h>
void concate(char *original, char *add)
{
        while(*original)
        original++;
        while(*add)
        {
                *original=*add;
                add++;
                original++;
        }
        *original=NULL;
}
void main()
{
        char original[100], add[100];
        printf("ENTER ORIGINAL STRING\n");
        gets(original);
        printf("ENTER STRING TO CONCATENATE\n");
        gets(add);
        concate(original, add);
        printf("ENTER AFTER CONCATENATION IS \"%s\"\n",original);
}

