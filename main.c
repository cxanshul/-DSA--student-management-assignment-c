#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

/* Student structure */
struct Student
{
    int rollNo;
    char name[50];
    float marks;
    char grade;
};

/* Linked List Node */
struct Node
{
    struct Student data;
    struct Node *next;
};

/* Array for storing students */
struct Student students[MAX_STUDENTS];

int studentCount = 0;

/* Head of the linked list */
struct Node *head = NULL;


/* -------------------------------------------------
   HELPER FUNCTIONS
   ------------------------------------------------- */

/* Calculate grade from marks */
char calculateGrade(float marks)
{
    if (marks >= 90)
        return 'A';
    else if (marks >= 75)
        return 'B';
    else if (marks >= 60)
        return 'C';
    else if (marks >= 40)
        return 'D';
    else
        return 'F';
}

/* Print table header */
void printHeader()
{
    printf("\n-----------------------------------------------------\n");
    printf("%-10s %-22s %-10s %-6s\n", "Roll No", "Name", "Marks", "Grade");
    printf("-----------------------------------------------------\n");
}

/* Print one student row */
void printStudent(struct Student s)
{
    printf("%-10d %-22s %-10.2f %-6c\n",
           s.rollNo, s.name, s.marks, s.grade);
}


/* -------------------------------------------------
   ARRAY FUNCTIONS
   ------------------------------------------------- */

/* Add student using Array */
void addStudentArray()
{
    int i, roll;

    if (studentCount >= MAX_STUDENTS)
    {
        printf("\nStudent limit reached!\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &roll);

    /* Check for duplicate roll number */
    for (i = 0; i < studentCount; i++)
    {
        if (students[i].rollNo == roll)
        {
            printf("\nRoll number already exists!\n");
            return;
        }
    }

    students[studentCount].rollNo = roll;

    printf("Enter Name: ");
    scanf(" %49[^\n]", students[studentCount].name);

    printf("Enter Marks (0-100): ");
    scanf("%f", &students[studentCount].marks);

    if (students[studentCount].marks < 0 || students[studentCount].marks > 100)
    {
        printf("\nInvalid marks! Student not added.\n");
        return;
    }

    students[studentCount].grade = calculateGrade(students[studentCount].marks);

    studentCount++;

    printf("\nStudent added successfully!\n");
}


/* Display students using Array */
void displayStudentsArray()
{
    int i;

    if (studentCount == 0)
    {
        printf("\nNo students available!\n");
        return;
    }

    printHeader();

    for (i = 0; i < studentCount; i++)
    {
        printStudent(students[i]);
    }
}


/* Search student using Linear Search */
void searchStudentArray()
{
    int roll, i;
    int found = 0;

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);

    for (i = 0; i < studentCount; i++)
    {
        if (students[i].rollNo == roll)
        {
            printf("\nStudent Found!\n");
            printHeader();
            printStudent(students[i]);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nStudent not found!\n");
    }
}


/* Update marks of a student in the Array */
void updateMarksArray()
{
    int roll, i;
    float newMarks;
    int found = 0;

    printf("\nEnter Roll Number to update: ");
    scanf("%d", &roll);

    for (i = 0; i < studentCount; i++)
    {
        if (students[i].rollNo == roll)
        {
            printf("Enter new Marks (0-100): ");
            scanf("%f", &newMarks);

            if (newMarks < 0 || newMarks > 100)
            {
                printf("\nInvalid marks!\n");
                return;
            }

            students[i].marks = newMarks;
            students[i].grade = calculateGrade(newMarks);

            printf("\nMarks updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nStudent not found!\n");
    }
}


/* Delete student from the Array */
void deleteStudentArray()
{
    int roll, i, pos = -1;

    if (studentCount == 0)
    {
        printf("\nNo students available!\n");
        return;
    }

    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &roll);

    for (i = 0; i < studentCount; i++)
    {
        if (students[i].rollNo == roll)
        {
            pos = i;
            break;
        }
    }

    if (pos == -1)
    {
        printf("\nStudent not found!\n");
        return;
    }

    /* Shift elements to the left */
    for (i = pos; i < studentCount - 1; i++)
    {
        students[i] = students[i + 1];
    }

    studentCount--;

    printf("\nStudent deleted successfully!\n");
}


/* Sort students by Marks using Selection Sort (Highest to Lowest) */
void sortStudents()
{
    int i, j, maxIndex;
    struct Student temp;

    if (studentCount == 0)
    {
        printf("\nNo students available for sorting!\n");
        return;
    }

    for (i = 0; i < studentCount - 1; i++)
    {
        maxIndex = i;

        for (j = i + 1; j < studentCount; j++)
        {
            if (students[j].marks > students[maxIndex].marks)
            {
                maxIndex = j;
            }
        }

        if (maxIndex != i)
        {
            temp = students[i];
            students[i] = students[maxIndex];
            students[maxIndex] = temp;
        }
    }

    printf("\nStudents sorted by marks (Highest to Lowest).\n");
}


/* -------------------------------------------------
   LINKED LIST FUNCTIONS
   ------------------------------------------------- */

/* Add student using Linked List */
void addStudentLinkedList()
{
    struct Node *newNode;
    struct Node *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("\nMemory allocation failed!\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &newNode->data.rollNo);

    /* Check for duplicate roll number */
    temp = head;
    while (temp != NULL)
    {
        if (temp->data.rollNo == newNode->data.rollNo)
        {
            printf("\nRoll number already exists!\n");
            free(newNode);
            return;
        }
        temp = temp->next;
    }

    printf("Enter Name: ");
    scanf(" %49[^\n]", newNode->data.name);

    printf("Enter Marks (0-100): ");
    scanf("%f", &newNode->data.marks);

    if (newNode->data.marks < 0 || newNode->data.marks > 100)
    {
        printf("\nInvalid marks! Student not added.\n");
        free(newNode);
        return;
    }

    newNode->data.grade = calculateGrade(newNode->data.marks);
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("\nStudent added to Linked List successfully!\n");
}


/* Display Linked List */
void displayLinkedList()
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("\nLinked List is empty!\n");
        return;
    }

    printHeader();

    while (temp != NULL)
    {
        printStudent(temp->data);
        temp = temp->next;
    }
}


/* Search student in Linked List */
void searchLinkedList()
{
    int roll;
    struct Node *temp = head;

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);

    while (temp != NULL)
    {
        if (temp->data.rollNo == roll)
        {
            printf("\nStudent Found!\n");
            printHeader();
            printStudent(temp->data);
            return;
        }

        temp = temp->next;
    }

    printf("\nStudent not found!\n");
}


/* Delete student from Linked List */
void deleteStudentLinkedList()
{
    int roll;
    struct Node *temp = head;
    struct Node *prev = NULL;

    if (head == NULL)
    {
        printf("\nLinked List is empty!\n");
        return;
    }

    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &roll);

    while (temp != NULL && temp->data.rollNo != roll)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("\nStudent not found!\n");
        return;
    }

    if (prev == NULL)
    {
        head = temp->next;      /* deleting the first node */
    }
    else
    {
        prev->next = temp->next;
    }

    free(temp);

    printf("\nStudent deleted from Linked List successfully!\n");
}


/* Free all nodes before exiting */
void freeLinkedList()
{
    struct Node *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}


/* -------------------------------------------------
   MAIN FUNCTION
   ------------------------------------------------- */

int main()
{
    int choice, result, c;

    do
    {
        printf("\n\n========================================");
        printf("\n       STUDENT MANAGEMENT SYSTEM");
        printf("\n========================================");

        printf("\n\n--- ARRAY OPERATIONS ---");

        printf("\n1. Add Student");
        printf("\n2. Display Students");
        printf("\n3. Search Student");
        printf("\n4. Sort Students by Marks");
        printf("\n5. Update Student Marks");
        printf("\n6. Delete Student");

        printf("\n\n--- LINKED LIST OPERATIONS ---");

        printf("\n7. Add Student using Linked List");
        printf("\n8. Display Linked List");
        printf("\n9. Search Student in Linked List");
        printf("\n10. Delete Student from Linked List");

        printf("\n\n11. Exit");

        printf("\n\nEnter your choice: ");

        result = scanf("%d", &choice);

        if (result == EOF)
        {
            /* No more input available: exit the program */
            freeLinkedList();
            printf("\nInput ended. Exiting...\n");
            break;
        }
        else if (result != 1)
        {
            /* Non-number input: clear the buffer (stop at newline or EOF) */
            while ((c = getchar()) != '\n' && c != EOF);
            choice = 0;
        }

        switch (choice)
        {
            case 1:
                addStudentArray();
                break;

            case 2:
                displayStudentsArray();
                break;

            case 3:
                searchStudentArray();
                break;

            case 4:
                sortStudents();
                break;

            case 5:
                updateMarksArray();
                break;

            case 6:
                deleteStudentArray();
                break;

            case 7:
                addStudentLinkedList();
                break;

            case 8:
                displayLinkedList();
                break;

            case 9:
                searchLinkedList();
                break;

            case 10:
                deleteStudentLinkedList();
                break;

            case 11:
                freeLinkedList();
                printf("\nThank you for using Student Management System!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 11);

    return 0;
}