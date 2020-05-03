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
  list->count--;
  free(element_to_free);

  return Success;
}

Status remove_from_end(List_ptr list)
{
  Status status = Failure;
  Node_ptr element_to_free = list->last;
  if (list->count == 1)
  {
    element_to_free = list->head;
    list->head = NULL;
    list->last = NULL;
    list->count--;
    free(element_to_free);
    return Success;
  }
  Node_ptr p_walk = list->head;
  for (int i = list->count; i > 1; i--)
  {
    if (i == 2)
    {
      status = Success;
      p_walk->next = NULL;
      list->last = p_walk;
      list->count--;
      free(element_to_free);
    }
    p_walk = p_walk->next;
  }
  return status;
}

Status remove_at(List_ptr list, int position)
{
  if (position == 0)
    return remove_from_start(list);

  if (position >= list->count)
    return Failure;

  if (position == (list->count) - 1)
    return remove_from_end(list);

  Node_ptr prev = NULL;

  Node_ptr p_walk = list->head;
  for (int index = 0; index < position; index++)
  {
    prev = p_walk;
    p_walk = p_walk->next;
  }

  Node_ptr element_to_free = p_walk;
  prev->next = p_walk->next;
  list->count--;
  free(p_walk);

  return Success;
}

Status remove_first_occurrence(List_ptr list, int value)
{
  Node_ptr p_walk = list->head;
  for (int index = 0; index < list->count; index++)
  {
    if (p_walk->value == value)
    {
      return (remove_at(list, index));
    }
    p_walk = p_walk->next;
  }
  return Failure;
}
