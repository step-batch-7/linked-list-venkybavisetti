#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List_ptr create_list(void)
{
  List *list = malloc(sizeof(List));

  list->head = NULL;
  list->last = NULL;
  list->count = 0;

  return list;
}

Node_ptr create_node(int value)
{
  Node_ptr new_node = malloc(sizeof(Node));

  new_node->value = value;
  new_node->next = NULL;

  return new_node;
}

Status add_to_end(List_ptr list, int value)
{
  Node_ptr new_node = create_node(value);

  Node_ptr *ptr_to_set = &list->head;
  if (list->head != NULL)
  {
    ptr_to_set = &list->last->next;
  }
  (*ptr_to_set) = new_node;
  list->last = new_node;
  list->count++;
  printf("\ninside\n");
  return Success;
}

void display(List_ptr list)
{
  Node_ptr p_walk = list->head;
  while (p_walk != NULL)
  {
    printf("%d ", p_walk->value);
    p_walk = p_walk->next;
  }
}

Status add_to_start(List_ptr list, int value)
{
  Node_ptr new_node = create_node(value);
  if (list->head == NULL)
  {
    list->last = new_node;
  }
  new_node->next = list->head;
  list->head = new_node;
  list->count++;
  return Success;
}

Status insert_at(List_ptr list, int value, int position)
{
  if (position == 0)
    return add_to_start(list, value);

  if (position > list->count)
    return Failure;

  if (position == list->count)
    return add_to_end(list, value);

  Node_ptr prev = NULL;
  Node_ptr new_node = create_node(value);

  Node_ptr p_walk = list->head;
  for (int index = 0; index < position; index++)
  {
    prev = p_walk;
    p_walk = p_walk->next;
  }
  new_node->next = p_walk;
  prev->next = new_node;
  list->count++;
  return Success;
}

Status add_unique(List_ptr list, int value)
{
  if (list->last->value == value)
    return Failure;
  return add_to_end(list, value);
}

Status remove_from_start(List_ptr list)
{
  if (list->count == 0)
    return Failure;

  Node_ptr element_to_free = list->head;
  list->head = list->head->next;
  free(element_to_free);

  return Success;
}
