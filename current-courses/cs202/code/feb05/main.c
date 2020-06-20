#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ll.h"

typedef struct {
    char *name;
    int salary;
} employee_t;

employee_t *new_employee(const char *name, int salary);

int main(int argc, char *argv[])
{
    list_t *li = new_list();
    employee_t *e1 = new_employee("Dave", 50);
    employee_t *e2 = new_employee("Charles", 75);
    employee_t *e3 = new_employee("Steve", 45);

    list_push_front(li, (void *)e1);
    list_push_front(li, (void *)e2);
    list_push_front(li, (void *)e3);

    printf("%p %p %p\n", e1, e2, e3);
    list_print(li);

    return 0;
}

employee_t *new_employee(const char *name, int salary)
{
    employee_t *e = (employee_t *)malloc(sizeof(employee_t));
    e->name = strdup(name);
    e->salary = salary;
    return e;
}
