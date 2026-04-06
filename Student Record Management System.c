#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    float marks;
};

struct Student s[100];
int count = 0;

// Add Student
void addStudent() {
    printf("\nEnter ID: ");
    scanf("%d", &s[count].id);

    printf("Enter Name: ");
    scanf("%s", s[count].name);

    printf("Enter Marks: ");
    scanf("%f", &s[count].marks);

    count++;
    printf("Student added successfully!\n");
}

// Display Students
void displayStudents() {
    if (count == 0) {
        printf("\nNo records found!\n");
        return;
    }

    printf("\nStudent Records:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Marks: %.2f\n",
               s[i].id, s[i].name, s[i].marks);
    }
}

// Search Student
void searchStudent() {
    int id, found = 0;
    printf("\nEnter ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (s[i].id == id) {
            printf("Found: %s | Marks: %.2f\n",
                   s[i].name, s[i].marks);
            found = 1;
        }
    }

    if (!found)
        printf("Student not found!\n");
}

// Main Function
int main() {
    int choice;

    while (1) {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}