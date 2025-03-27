#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

// Structure to store student data
typedef struct {
    int roll_no;
    char name[50];
    float marks[3]; // Marks for three subjects
} Student;

Student students[MAX_STUDENTS];
int student_count = 0;

// Function to add a student
void addStudent() {
    if (student_count >= MAX_STUDENTS) {
        printf("Student list is full!\n");
        return;
    }
    
    printf("Enter Roll Number: ");
    scanf("%d", &students[student_count].roll_no);
    while (getchar() != '\n'); // Clear input buffer
    printf("Enter Name: ");
    fgets(students[student_count].name, sizeof(students[student_count].name), stdin);
    students[student_count].name[strcspn(students[student_count].name, "\n")] = 0; // Remove newline
    printf("Enter Marks (3 subjects): ");
    for (int i = 0; i < 3; i++) {
        scanf("%f", &students[student_count].marks[i]);
    }
    
    student_count++;
    printf("Student Added Successfully!\n");
}

// Function to display all students
void displayStudents() {
    if (student_count == 0) {
        printf("No records found.\n");
        return;
    }
    
    printf("\nStudent Report Card:\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < student_count; i++) {
        printf("Roll No: %d\n", students[i].roll_no);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f, %.2f, %.2f\n", students[i].marks[0], students[i].marks[1], students[i].marks[2]);
        printf("----------------------------------------\n");
    }
}

// Function to search for a student by roll number
void searchStudent() {
    int roll_no;
    printf("Enter Roll Number to search: ");
    scanf("%d", &roll_no);
    
    for (int i = 0; i < student_count; i++) {
        if (students[i].roll_no == roll_no) {
            printf("\nStudent Found!\n");
            printf("Roll No: %d\nName: %s\nMarks: %.2f, %.2f, %.2f\n",
                   students[i].roll_no, students[i].name, students[i].marks[0], students[i].marks[1], students[i].marks[2]);
            return;
        }
    }
    printf("Student Not Found.\n");
}

// Function to update student marks
void updateMarks() {
    int roll_no;
    printf("Enter Roll Number to update marks: ");
    scanf("%d", &roll_no);
    
    for (int i = 0; i < student_count; i++) {
        if (students[i].roll_no == roll_no) {
            printf("Enter new marks (3 subjects): ");
            for (int j = 0; j < 3; j++) {
                scanf("%f", &students[i].marks[j]);
            }
            printf("Marks Updated Successfully!\n");
            return;
        }
    }
    printf("Student Not Found.\n");
}

// Function to delete a student record
void deleteStudent() {
    int roll_no;
    printf("Enter Roll Number to delete: ");
    scanf("%d", &roll_no);
    
    for (int i = 0; i < student_count; i++) {
        if (students[i].roll_no == roll_no) {
            for (int j = i; j < student_count - 1; j++) {
                students[j] = students[j + 1];
            }
            student_count--;
            printf("Student Record Deleted Successfully!\n");
            return;
        }
    }
    printf("Student Not Found.\n");
}

// Main function
int main() {
    int choice;
    while (1) {
        printf("\nStudent Report Card System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Marks\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                updateMarks();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
