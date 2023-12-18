#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
// Studen struct
struct Student 
{
    int ID;
    char name[30];
    date DOB;
    int age;
    char gender[5];
    float score1;
    float score2;
    float score3;
    float averageScore = 0;
    char academicPerformance[10] = "-";
    char classCode[10];
}; typedef Student ST;

void importStudentInformation(ST* st);
void exportStudentInformatin(ST* st);
void getAge(ST* st);
void getAvergeScore(ST* st);
void classification(ST* st);
void updateStudentInformation(ST* st);
void importStudent(ST* arrStudent, int* length);
void exportStudent(ST* arrStudent, int* length);


int main() {
    ST *stArr = NULL;
     stArr = (ST*)malloc(0);
    int numOfStudent = 0;
    int ordinal;
}

void importStudentInformation(ST* st) {
    printf("\nID: "); scanf("%d", &st->ID);
    printf("\nName: "); fgets(st->name, sizeof(st->name), stdin); st->name[strcspn(st->name, "\n")] = '\0';
    printf("\nAge: "); scanf("%d", &st->age);
    printf("\nGender: "); fgets(st->gender, sizeof(st->gender), stdin); st->gender[strcspn(st->gender, "\n")] = '\0';
    printf("\nScore 1: "); scanf("%d", &st->score1);
    printf("\nScore 2: "); scanf("%d", &st->score2);
    printf("\nScore 3: "); scanf("%d", &st->score3);
    printf("\nClass code: "); fgets(st->classCode, sizeof(st->classCode), stdin); st->classCode[strcspn(st->classCode, "\n")] = '\0';
}

void exportStudentInformatin(ST* st) {
    printf("\n%d", st->ID);
    printf("\t%s", st->name);
    printf("\t\t%s", st->gender);
    printf("\t\t%d", st->age);
    printf("\t%.2f\t%.2f\t%.2f", st->score1, st->score2, st->score3);
    printf("\t%.2f", st->averageScore);
    printf("\t%s", st->academicPerformance);
}

void addStudent(ST* stArr, int* length) {
    (*length)++;
    stArr = (ST*)realloc(stArr, *length * sizeof(ST));
    ST student;
    importStudentInformation(student);
    stArr[*length-1] = student;
    printf("\nThem sinh vien thanh cong!\n");
}

void importStudentList(ST* stArr, int* length) {
    do {
        
    }
}

void exportStudent(ST* stArr, int lenghth) {
    
}