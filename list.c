#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List_ptr create_list(void)
{
  List *list = malloc(sizeof(list));

  list->head = NULL;
  list->last = NULL;
  list->count = 0;

  return list;
}

void print_menu_bar(void)
{
  clrscr();
  printf("Main Menu\n");
  printf("---------\n");
  printf("(a) add a number to the end of the list\n");
  printf("(b) add a number to the start of the list\n");
  printf("(c) insert a number at a given position in the list\n");
  printf("(d) add a unique item on the list at the end(if it alreay exists, do not insert)\n");
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

void take_input(List *list)
{
  char input;

  print_menu_bar();
  scanf("%c", &input);
  if (input == 'm')
  {
    return;
  }

  take_input(list);
}