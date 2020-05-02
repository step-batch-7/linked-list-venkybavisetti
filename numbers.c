#include <stdio.h>
#include "list.h"

#define clrscr() printf("\e[1;1H\e[2J")
#define DONE printf("Done\n\n")
#define FAIL printf("Fail\n\n")

void print_menu_bar(void)
{
  printf("Main Menu\n");
  printf("---------\n");
  printf("(a) add a number to the end of the list\n");
  printf("(b) add a number to the start of the list\n");
  printf("(c) insert a number at a given position in the list\n");
  printf("(d) add a unique item on the list at the end(if it already exists, do not insert)\n");
  printf("(e) remove a number from the beginning of the list\n");
  printf("(f) remove a number from the end of the list\n");
  printf("(g) remove a number from a given position in the list\n");
  printf("(h) remove first occurrence of a number\n");
  printf("(i) remove all occurrences of a number\n");
  printf("(j) clear the whole list\n");
  printf("(k) check if a number exists in the list\n");
  printf("(l) display the list of numbers\n");
  printf("(m) exit\n\n");
  printf("Please enter the alphabet of the operation you would like to perform\n\n");
}

void clear_buffer()
{
  while ((getchar()) != '\n')
  {
  }
}

char read_operation_code(void)
{
  char operation;
  scanf("%c", &operation);
  clear_buffer();
  return operation;
}

int read_input_value(void)
{
  int value;
  printf("Enter a number :\n");
  scanf("%d", &value);
  clear_buffer();
  return value;
}

void print_status(Status status)
{
  clrscr();
  if (status)
  {
    DONE;
    return;
  }
  FAIL;
}

void run_operations(List *list)
{
  int value;
  char operation;
  Status status = Failure;

  print_menu_bar();
  operation = read_operation_code();

  switch (operation)
  {
  case 'm':
    return;
    break;

  case 'a':
    value = read_input_value();
    status = add_to_end(list, value);
    break;

  case 'l':
    display(list);
    break;
  }

  print_status(status);
  run_operations(list);
}

int main(void)
{
  List_ptr list = create_list();
  run_operations(list);

  return 0;
}