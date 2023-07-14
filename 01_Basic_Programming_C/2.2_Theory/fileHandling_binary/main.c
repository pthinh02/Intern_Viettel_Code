#include <stdio.h>


int main()
{

    FILE *fp;
    char another = 'y';
    
    struct emp
    {
        char name[40];
        int age;
        float bs;
    };

    struct emp e;

    fp = fopen("binary.bin", "wb");
    if (fp ==NULL)
    {
        printf("Cannot open file.\n");
        return 1;
    }

    while (another == 'y')
    {
        printf("Enter name: ");
        fgets(e.name, sizeof(e.name), stdin);
        printf("\nEnter age: ");
        scanf("%d", &e.age);
        printf("\nEnter salary: ");
        scanf("%.2f", &e.bs);
        while (getchar() != '\n');
        fwrite(&e,sizeof(e), 1, fp);
        printf("\nAdd another records? (y/n): ");
        another = getchar();
        fgetc(stdin);
    }
    fclose(fp);
    return 0;
}