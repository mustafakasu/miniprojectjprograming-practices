/*
STUDENT MANAGMENT SYSTEM 
CREATED BY : MUSTAFA KASUBHAI WALA 
ROLL NO. 0801CS221093.
© COPYRIGHT 2023 BY MUSTAFA KASUBHAI WALA . THESE MATERIAL CANNOT BE
DUBLICATE FOR ANY PROFIT DRIVEN ENTERPRISE.
 These software helps to keep the record of the student it helps the university to keep the updates of the student 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// define the maximum size for the string .
#define g_size 60
// define the maximum size for the
#define g_N 100
// structure to store the grades of the student .
struct Grades {
    char c_subjects[g_size];
    char c_grade[g_size];
};
// structure to store the student information .
struct studentinfo {
    int i_year_admission;
    char c_enrollment_no[g_size];
    char c_name[g_size];
    char c_lastname[g_size];
    int i_phone_no;
    int i_age;
    char c_City[g_size];
    char c_Gender[g_size];
    char c_address[g_size];
    char c_email_id[g_size];
    char c_branch[g_size];
    int i_fees;
    struct Grades gradesshow[g_N];
    int i_num_subjects;
};
// Defining the function prototyes.
void F_Add_student_details(struct studentinfo *student, int *serial_no);
void F_Display_student_details(struct studentinfo *student, int *serial_no);
int F_Search_the_student(struct studentinfo *student, int *serial_no, char *c_enrollment);
void F_Delete_the_student_details(struct studentinfo *student, int *serial_no, char *c_enrollment);
void F_Modify_the_student_details(struct studentinfo *student, int *serial_no, char *c_enrollment);
void F_Student_grades(struct studentinfo *student, int *serial_no, char *c_enrollment);
void F_Student_grades_show(struct studentinfo *student, int *serial_no, char *c_enrollment);
// main function .
int main() {
    //Allocate memory to structure function .
    struct studentinfo *student = malloc(g_N * sizeof(struct studentinfo));
    // These condition checks that memory allocate is successfully or not .
        if (student == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    int serial_no = 0;
    int choice; // user choice to select the menu .
    char c_enrollment_no[g_size];// variable to store the enrollment number of student .
     while (1) {
        printf("Welcome to Student Management System:\n");
        printf("1. Add Student\n");
        printf("2. Display Student Details\n");
        printf("3. Search Student\n");
        printf("4. Delete Student Registration\n");
        printf("5. Modify Student Details\n");
        printf("6. Add Grades\n");
        printf("7. Display Grades\n");
        printf("8. Exit\n");
        printf("Enter your number ");
        scanf("%d", &choice);
        // perform the user task .
        switch (choice) {
            case 1:
            // Add the student details.
                F_Add_student_details(&student[serial_no], &serial_no);
                break;
            case 2:
            //Display the student details .
                F_Display_student_details(student, &serial_no);
                break;
            case 3:
            //search the student of specific enrollment number .
                printf("Enter the student Enrollment number for search:\n");
                scanf("%s", c_enrollment_no);
                int index = F_Search_the_student(student, &serial_no, c_enrollment_no);
                if (index != -1) {
                    // display the student details .
                    printf("*******-------------------------------------*******\n");
                      printf("Enrollment No:%s\n", student[index].c_enrollment_no);
                      printf("Year of admission: %d\n", student[index].i_year_admission);
                      printf("Name: %s %s\n", student[index].c_name, student[index].c_lastname);
                      printf("Gender:%s",student[index].c_Gender);
                      printf("Branch: %s\n", student[index].c_branch);
                      printf("Address :%s\n",student[index].c_address);
                      printf("city: %s",student[index].c_City);
                      printf("Age of the student: %d\n", student[index].i_age);
                      printf("Student phone no is: %d\n", student[index].i_phone_no);
                      printf("Email Id:%s\n",student[index].c_email_id);
                      printf("****-----------------------****\n");
                } else {
                    printf("Student details not found.\n");
                }
                break;
            case 4:
            // Delete the student details of specific enrollment number.
                printf("Enter the student Enrollment number whose registration is cancelled: ");
                scanf("%s", c_enrollment_no);
                F_Delete_the_student_details(student, &serial_no, c_enrollment_no);
                break;
            case 5:
            // Modify the student details 
                printf("Enter the Enrollment Number of the student to modify details:\n");
                scanf("%s", c_enrollment_no);
                F_Modify_the_student_details(student, &serial_no, c_enrollment_no);
                break;
                
            case 6:
            // Add the student details .
               printf("Enter the Enrollment number of student for grades:\n");
                scanf("%s", c_enrollment_no);
                F_Student_grades(student, &serial_no, c_enrollment_no);
                break;
            case 7:
            //Display the student grades of specific enrollment number .
                printf("Enter the Enrollment number of student to display grades:\n");
                scanf("%s", c_enrollment_no);
                F_Student_grades_show(student, &serial_no, c_enrollment_no);
                break;
            case 8:
              // exit from the program .
                free(student);// Free allocate memory .
                printf("Thank you for using Student Management System.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
// Function to add the student details .
void F_Add_student_details(struct studentinfo *student, int *serial_no) {
    printf("Enter the data for student %d:\n", (*serial_no) + 1);
    printf("*********************************\n");
    printf("Enter the year of admission: ");
    scanf("%d", &student->i_year_admission);
    printf("Enter the Enrollment no of student: ");
    scanf("%s", student->c_enrollment_no);
    printf("Enter the student name: ");
    scanf("%s", student->c_name);
    printf("Enter the surname: ");
    scanf("%s", student->c_lastname);
    printf("Enter the Gender :");
    scanf("%s",student->c_Gender);
    printf("Enter the branch: ");
    scanf("%s", student->c_branch);
    printf("Enter the phone number: ");
    scanf("%d",&student->i_phone_no);
    printf("Enter the address:");
    scanf("%s",student->c_address);
    printf("Enter the city :");
    scanf("%s",student->c_City );
    printf("Enter the age of the student:");
    scanf("%d", &student->i_age);
    printf("Enter the Email Id: ");
    scanf("%s",student->c_email_id);
    printf("Enter the Fees: ");
    scanf("%d", &student->i_fees);
    printf("Detail of Student is Saved :\n");
    printf("\n******************************\n");

    (*serial_no)++; 
}
// Function to display the student details .
void F_Display_student_details(struct studentinfo *student, int *serial_no) {
   printf("Details of students are as follows:\n");
    for (int i = 0; i < *serial_no; i++)
    {
        printf("****---------------------------------******\n");
        printf("Enrollment No:%s\n", student[i].c_enrollment_no);
        printf("Year of admission: %d\n", student[i].i_year_admission);
        printf("Name: %s %s\n", student[i].c_name, student[i].c_lastname);
        printf("Gender:%s",student[i]. c_Gender);
        printf("Branch: %s\n", student[i].c_branch);
        printf("Address :%s\n",student[i].c_address);
        printf("city: %s",student[i].c_City);
        printf("Age of the student: %d\n", student[i].i_age);
        printf("Student phone no is: %d\n", student[i].i_phone_no);
        printf("Email Id:%s\n",student[i].c_email_id);
        printf("Fees: %d\n", student[i].i_fees);
        printf("****-----------------------****\n");
    }
}
// Function which search the speacific student  .
int F_Search_the_student(struct studentinfo *student, int *serial_no, char *enrollment) {
       for (int i = 0; i < *serial_no; i++)
    {
        if (strcmp(student[i].c_enrollment_no, enrollment) == 0)
        {
            return i;
        }
    }
    return -1;
}
// Function Delete the student details of specific enrollment number.
void F_Delete_the_student_details(struct studentinfo *student, int *serial_no, char *c_enrollment) {
    int search = F_Search_the_student(student, serial_no, c_enrollment);
    if (search != -1)
    {
        for (int i = search; i < *serial_no - 1; i++)
        {
            student[i] = student[i + 1];
        }
        (*serial_no)--;
        printf("Student with enrollment number: %s has been deleted.\n", c_enrollment);
    }
    else
    {
        printf("Student with enrollment number: %s is not found.\n", c_enrollment);
    }
}
// Function Modify the details of the student details .
void F_Modify_the_student_details(struct studentinfo *student, int *serial_no, char *c_enrollment) {
   int index = F_Search_the_student(student, serial_no, c_enrollment);
    if (index != -1)
    {
        printf("----------------------------------------------------------");
        printf("Enter the modified details for student with Enrollment Number %s:\n",c_enrollment);
        printf("Enter the new Year of Admission: ");
        scanf("%d", &student[index].i_year_admission);
        printf("Enter the new Name and Last Name of the student: ");
        scanf("%s %s", student[index].c_name, student[index].c_lastname);
        printf("Enter the new Phone Number: ");
        scanf("%d", &student[index].i_phone_no);
        printf("Enter the new Age of Student: ");
        scanf("%d", &student[index].i_age);
        printf("Enter the new Email Address: ");
        scanf("%s", student[index].c_email_id);
        printf("Enter the new City: ");
        scanf("%s", student[index].c_City);
        printf("Student details updated successfully.\n");
        printf("------------------------------------------\n");
    }
    else
    {
        printf("Student with Enrollment Number %s not found.\n", c_enrollment);
    }  
}
// Function which adds the student grades .
void F_Student_grades(struct studentinfo *student, int *serial_no, char *c_enrollment) {
    int index = F_Search_the_student(student, serial_no, c_enrollment);
    if (index != -1) {
        printf("Enter the number of subjects:\n");
        scanf("%d", &student[index].i_num_subjects);
        for (int i = 0; i < student[index].i_num_subjects; i++) {
            printf("Enter subject %d: ", i + 1);
            scanf("%s", student[index].gradesshow[i].c_subjects);
            printf("Enter the grade for %s: ", student[index].gradesshow[i].c_subjects);
            scanf("%s", student[index].gradesshow[i].c_grade);
        }
        printf("Grades for student with Enrollment No. %s successfully added.\n", c_enrollment);
    } else {
        printf("Student with Enrollment %s not found.\n", c_enrollment);
    }
}
// Function display the student grades .
void F_Student_grades_show(struct studentinfo *student, int *serial_no, char *c_enrollment) {
    int index =F_Search_the_student(student, serial_no, c_enrollment);
    if (index != -1) {
        printf("\n--------------------------\n");
        printf("Grades for student with Enrollment No. %s:\n", student[index].c_enrollment_no);
        for (int i = 0; i < student[index].i_num_subjects; i++) {
            printf("Subject: %s, Grade: %s\n", student[index].gradesshow[i].c_subjects, student[index].gradesshow[i].c_grade);
        printf ("\n--------------------------\n");
        }
    } else {
        printf("Enrollment %s not found.\n", c_enrollment);
    }
}