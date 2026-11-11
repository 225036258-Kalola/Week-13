
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[30];
    double salary;
} Employee;

int main(void) {
    int capacity = 2;
    int count = 0;
    int choice;
    int searchID;

    Employee *employees = NULL;
    Employee *bigger;
    Employee e;

    /* TODO 1: Allocate initial memory */
    employees = malloc(capacity * sizeof(Employee));

    if (employees == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    do {
        printf("\n===== WEEK 13: EMPLOYEE MANAGEMENT =====\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (count == capacity) {
                /* TODO 2: Increase memory safely */
                int newCapacity = capacity * 2;

                bigger = realloc(employees,
                                 newCapacity * sizeof(Employee));

                if (bigger == NULL) {
                    printf("Memory expansion failed.\n");
                    free(employees);
                    return 1;
                }

                employees = bigger;
                capacity = newCapacity;

                printf("Memory expanded! New capacity: %d\n",
                       capacity);
            }

            /* TODO 3: Store employee details */
            printf("Enter employee ID: ");
            scanf("%d", &e.id);

            printf("Enter employee name: ");
            scanf(" %29[^\n]", e.name);

            printf("Enter employee salary: ");
            scanf("%lf", &e.salary);

            employees[count] = e;
            count++;

            printf("Employee added successfully!\n");
        }

        else if (choice == 2) {
            /* TODO 4: Display employees */
            if (count == 0) {
                printf("No employees available.\n");
            } else {
                printf("\n--- Employee Records ---\n");

                for (int i = 0; i < count; i++) {
                    printf("\nID: %d\n", employees[i].id);
                    printf("Name: %s\n", employees[i].name);
                    printf("Salary: %.2f\n", employees[i].salary);
                }
            }

            printf("\nTotal employees: %d\n", count);
            printf("Current capacity: %d\n", capacity);
        }

        else if (choice == 3) {
            printf("Enter employee ID to search: ");
            scanf("%d", &searchID);

            int found = 0;

            for (int i = 0; i < count; i++) {
                if (employees[i].id == searchID) {
                    printf("\nEmployee found!\n");
                    printf("ID: %d\n", employees[i].id);
                    printf("Name: %s\n", employees[i].name);
                    printf("Salary: %.2f\n", employees[i].salary);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Employee not found.\n");
            }
        }

        else if (choice == 4) {
            printf("Exiting program...\n");
        }

        else {
            printf("Invalid choice. Try again.\n");
        }

    } while (choice != 4);

    /* TODO 5: Release allocated memory */
    free(employees);
    employees = NULL;

    printf("Memory released successfully.\n");

    return 0;
}
