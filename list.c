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

void print_menu(void)
{
  printf("Main Menu");
}

void take_input(List *list)
{
  int input;
  // print_menu();
  // printf("Please enter a number:\n");
  // scanf("%d", &input);
  // if (input == -99)
  // {
  //   printf("\n\n");
  //   return;
  // }
  // insert_node(list, input);

  // take_input(list);
}