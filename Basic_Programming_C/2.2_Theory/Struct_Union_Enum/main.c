#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct{
    int day;
    int month;
    int year;
}Date_t;

typedef struct {
    char name[30];
    int age;
    float gpa;
    Date_t birthday;
}Human_t;

/*
enum ledstate_t
{

};
enum ledstate_t ledstate;
*/

typedef enum 
{
    S_LEDON,        //=0
    S_LEDOFF,       //=1
    S_LEDBLINK,     //=2
    S_LEDDEAD       //=3
}ledstate_t;

ledstate_t led_state;


void nhap(Human_t *sinhvien)
{
    printf("Name: ");
    gets(sinhvien->name);
    printf("Age: ");
    scanf("%d", &sinhvien->age);
    printf("GPA: ");
    scanf("%f", &sinhvien->gpa);
    printf("DoB: ");
    scanf("%d", &sinhvien->birthday.day);
    printf("DoB: ");
    scanf("%d", &sinhvien->birthday.month);
    printf("DoB: ");
    scanf("%d", &sinhvien->birthday.year);
}

void xuat(Human_t *sinhvien1)
{
    printf("\n%s %d %.2f %d/%d/%d\n", sinhvien1->name, sinhvien1->age, sinhvien1->gpa,sinhvien1->birthday.day,sinhvien1->birthday.month,sinhvien1->birthday.year);
}


int main(int argc, char **argv)
{
    int count;
    printf("Nhap vao so luong: ");
    scanf("%d", &count);
    getchar();
    Human_t *a[count] ;
    for (int i=0; i<count; i++)
    {
        nhap(a[i]);
    }

    printf("Test");
    nhap(a[1]);
    printf("Test");

    for (int i=0; i<count ; i++)
    {
        xuat(a[i]);
    }


    return 0;
}









