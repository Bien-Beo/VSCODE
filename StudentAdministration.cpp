#include <stdio.h> //new commment
#include<conio.h>
#include <iostream>
#include <string.h>
#define MAX 100
// Student structure
struct student {
	int ID;
	char name[30];
	char gender[5];
	int age;
	float mathScore;
	float physicsScore;
	float chemistryScore;
	float averageScore = 0;
	char academicPerformance[10] = "-";
};
typedef student ST;

void AverageScore(ST &st) {
	st.averageScore = (st.mathScore + st.physicsScore + st.chemistryScore) / 3;
}

void Classification(ST &st) {
	if(st.averageScore >= 8) strcpy(st.academicPerformance, "Excellent");
	else if(st.averageScore >= 6.5) strcpy(st.academicPerformance, "Fairly");
	else if(st.averageScore >= 5) strcpy(st.academicPerformance, "Median");
	else strcpy(st.academicPerformance, "Weak");
}

void importStudentInformation(ST &st, int ID) {
	printf("\nName: "); fflush(stdin); gets(st.name);
	printf("\nGender: "); gets(st.gender);
	printf("\nAge: "); scanf("%d", st.age);
	printf("\nMath score: "); scanf("%.2f", st.mathScore);
	printf("\nPhysics score: "); scanf("%.2f", st.physicsScore);
	printf("\nChemistry score: "); scanf("%.2f", st.chemistryScore);
	st.ID = ID;
	AverageScore(st);
	Classification(st);
}

void importStudent(ST st[], int ID, int length) {
	printf("\nEnter student [%d]: ", length + 1);
	importStudentInformation(st[length], ID);
}

void updateStudentInformation(ST &st) {
	printf("\nName: "); fflush(stdin); gets(st.name);
	printf("\nGender: "); gets(st.gender);
	printf("\nAge: "); scanf("%d", st.age);
	printf("\nMath score: "); scanf("%d", st.mathScore);
	printf("\nPhysics score: "); scanf("%d", st.physicsScore);
	printf("\nChemistry score: "); scanf("%d", st.chemistryScore);
	AverageScore(st);
	Classification(st);
}

void updateStudent(ST st[], int ID, int length) {
	int found = 0;
	for(int i = 0; i < length; i++) {
		if(st[i].ID == ID) {
			found = 1;
			printf("\nUpdate student ID: %d", ID);
			updateStudentInformation(st[i]);
			break;
		}
	}
	if(found == 0) {
		printf("\nError studen ID: %d", ID);
	}
}

int deleteStudentID(ST st[], int ID, int length) {
	int found = 0;
	for(int i = 0; i < length; i++) {
		if(st[i].ID == ID) {
			found = 1;
			for(int j = i; j < length; j++) {
				st[j] = st[j + 1];
			}
			printf("\nDelete student ID: %d", ID);
			break;
		}
	}
	if(found == 0) {
		printf("\nError student ID: %d", ID);
		return 0;
	} else {
		return 1;
	}
}

//void findStudentName(ST st[], char name[], int length) {
//	ST arrayFound[MAX];
//	char nameStudent[30];
//	int found = 0;
//    for(int i = 0; i < length; i++) {
//        strcpy(nameStudent, st[i].name);
//        if(strstr(strupr(nameStudent), strupr(name))) {
//            arrayFound[found] = st[i];
//            found++;
//        }
//    }
//    showStudent(arrayFound, found);
//}

void showStudent(ST st[], int length) {
	printf("\n\STT\tID\tHo va ten\tGioi tinh\tTuoi\tToan\tLy\tHoa\tDiem TB\tHoc luc");
    for(int i = 0; i < length; i++) {
        printf("\n %d", i + 1);
        printf("\t%d", st[i].ID);
        printf("\t%s", st[i].name);
        printf("\t\t%s", st[i].gender);
        printf("\t\t%d", st[i].age);
        printf("\t%.2f\t%.2f\t%.2f", st[i].mathScore, st[i].physicsScore, st[i].chemistryScore);
        printf("\t%.2f", st[i].averageScore);
        printf("\t%s", st[i].academicPerformance);
    }
}

//Fuction ID max
int maxID(ST arr[], int length) {
	int idMax = 0;
	if (length > 0) {
		idMax = arr[0].ID;
		for (int i = 0; i < length; i++) {
			if (idMax < arr[i].ID) {
				idMax = arr[i].ID;
			}
		}
	}
	return idMax;
}

int docFile(ST a[], char fileName[]) {
    FILE * fp;
    int i = 0;
    fp = fopen (fileName, "r");
    printf("Chuan bi doc file: "); puts(fileName);
    // doc thong tin sinh vien
    while (fscanf(fp, "%5d%30s%5s%5d%10f%10f%10f%10f%10s\n", &a[i].ID, &a[i].name, 
            &a[i].gender, &a[i].age, &a[i].mathScore, &a[i].physicsScore, &a[i].chemistryScore, 
            &a[i].averageScore, &a[i].academicPerformance) != EOF) {
       i++;
       printf(" Doc ban ghi thu: %d\n", i);
    }
    printf(" So luong sinh vien co san trong file la: %d\n", i);
    printf("\n");
    fclose (fp);
    // tra ve so luong sinh vien duoc doc tu file
    return i;
}

void ghiFile(ST a[], int n, char fileName[]) {
    FILE * fp;
    fp = fopen (fileName,"w");
    for(int i = 0;i < n;i++){
        fprintf(fp, "%5d%30s%5s%5d%10f%10f%10f%10f%10s\n", a[i].ID, a[i].name,a[i].gender, 
            a[i].age, a[i].mathScore, a[i].physicsScore, a[i].chemistryScore, a[i].averageScore, a[i].academicPerformance);
    }
    fclose (fp);
}
 
void pressAnyKey() {
    printf("\n\nBam phim bat ky de tiep tuc...");
    getch();
    system("cls");
}

int main()
{
	int key;
    char fileName[] = "sinhvien.txt";
    ST arraySV[MAX];
    int soluongSV = 0;
    int idCount = 0;
     
    // nhap danh sach sinh vien tu file
    soluongSV = docFile(arraySV, fileName);
    idCount = maxID (arraySV, soluongSV);
 
    while(true) {
        printf("CHUONG TRINH QUAN LY SINH VIEN C/C++\n");
        printf("*************************MENU**************************\n");
        printf("**  1. Them sinh vien.                               **\n");
        printf("**  2. Cap nhat thong tin sinh vien boi ID.          **\n");
        printf("**  3. Xoa sinh vien boi ID.                         **\n");
        printf("**  4. Tim kiem sinh vien theo ten.                  **\n");
        printf("**  5. Sap xep sinh vien theo diem trung binh (GPA). **\n");
        printf("**  6. Sap xep sinh vien theo ten.                   **\n");
        printf("**  7. Hien thi danh sach sinh vien.                 **\n");
        printf("**  8. Ghi danh sach sinh vien vao file.             **\n");
        printf("**  0. Thoat                                         **\n");
        printf("*******************************************************\n");
        printf("Nhap tuy chon: ");
        scanf("%d", &key);
        switch(key){
            case 1:
                printf("\n1. Them sinh vien.");
                idCount++;
                importStudent(arraySV, idCount, soluongSV);
                printf("\nThem sinh vien thanh cong!");
                soluongSV++;
                pressAnyKey();
                break;
            case 2:
                if(soluongSV > 0) {
                    int id;
                    printf("\n2. Cap nhat thong tin sinh vien. ");
                    printf("\n Nhap ID: "); scanf("%d", &id);
                    updateStudent(arraySV, id, soluongSV);
                }else{
                    printf("\nSanh sach sinh vien trong!");
                }
                pressAnyKey();
                break;
            case 3:
                if(soluongSV > 0) {
                    int id;
                    printf("\n3. Xoa sinh vien.");
                    printf("\n Nhap ID: "); scanf("%d", &id);
                    if (deleteStudentID(arraySV, id, soluongSV) == 1) {
                        printf("\nSinh vien co id = %d da bi xoa.", &id);
                        soluongSV--;
                    }
                }else{
                    printf("\nSanh sach sinh vien trong!");
                }
                pressAnyKey();
                break;
 /*           case 4:
                if(soluongSV > 0) {
                    printf("\n4. Tim kiem sinh vien theo ten.");
                    char strTen[30];
                    printf("\nNhap ten de tim kiem: "); fflush(stdin); gets(strTen);
                    timKiemTheoTen(arraySV, strTen, soluongSV);
                }else{
                    printf("\nSanh sach sinh vien trong!");
                }
                pressAnyKey();
                break;*/
//            case 5:
//                if(soluongSV > 0) {
//                    printf("\n5. Sap xep sinh vien theo diem trung binh (GPA).");
//                    sapxepTheoDTB(arraySV, soluongSV);
//                    showStudent(arraySV, soluongSV);
//                }else{
//                    printf("\nSanh sach sinh vien trong!");
//                }
//                pressAnyKey();
//                break;
//            case 6:
//                if(soluongSV > 0) {
//                    printf("\n6. Sap xep sinh vien theo ten.");
//                    sapXepTheoTen(arraySV, soluongSV);
//                    showStudent(arraySV, soluongSV);
//                } else {
//                    printf("\nSanh sach sinh vien trong!");
//                }
//                pressAnyKey();
//                break;
            case 7:
                if(soluongSV > 0){
                    printf("\n7. Hien thi danh sach sinh vien.");
                    showStudent(arraySV, soluongSV);
                }else{
                    printf("\nSanh sach sinh vien trong!");
                }
                pressAnyKey();
                break;
            case 8:
                if(soluongSV > 0){
                    printf("\n8. Ghi danh sach sinh vien vao file.");
                    ghiFile(arraySV, soluongSV, fileName);
                }else{
                    printf("\nSanh sach sinh vien trong!");
                }
                printf("\nGhi danh sach sinh vien vao file %s thanh cong!", fileName);
                pressAnyKey();
                break;
            case 0:
                printf("\nBan da chon thoat chuong trinh!");
                getch();
                return 0;
            default:
                printf("\nKhong co chuc nang nay!");
                printf("\nHay chon chuc nang trong hop menu.");
                pressAnyKey();
                break;
        }
    }
}