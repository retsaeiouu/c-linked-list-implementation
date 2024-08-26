#include "linked_list_functions.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static struct node *new_node(int value) {
  struct node *new = (struct node *)malloc(sizeof(struct node));
  if (new == NULL)
    printf("ERROR: %s\n", strerror(errno));
  new->value = value;
  return new;
}

struct node *new_head(int value) {
  struct node *new = new_node(value);
  new->next = NULL;
  return new;
}

void insertion_at_head(struct node **head, int value) {
  if (*head == NULL)
    return;
  struct node *new = new_node(value);
  struct node *temporary_list = *head;
  new->next = temporary_list;
  *head = new;
}

void insertion_before(struct node *previous_node, int value) {
  if (previous_node == NULL)
    return;
  struct node *new = new_node(value);
  if (previous_node->next != NULL) {
    struct node *temporary_next = previous_node->next;
    previous_node->next = new;
    new->next = temporary_next;
    return;
  }
  previous_node->next = new;
}

void insertion_at_tail(struct node *head, int value) {
  if (head == NULL)
    return;
  struct node *new = new_node(value);
  new->next = NULL;
  while (head->next != NULL)
    head = head->next;
  head->next = new;
}

void reverse_list(struct node **head) {
  if (*head == NULL)
    return;
  struct node *temporary_previous = NULL;
  struct node *temporary_current = *head;
  struct node *temporary_next = NULL;
  while (temporary_current != NULL) {
    temporary_next = temporary_current->next;
    temporary_current->next = temporary_previous;
    temporary_previous = temporary_current;
    temporary_current = temporary_next;
  }
  *head = temporary_previous;
}

void print_list(struct node *head) {
  if (head == NULL)
    return;
  while (head != NULL) {
    (head->next != NULL) ? printf("%d, ", head->value)
                         : printf("%d\n", head->value);
    head = head->next;
  }
}

void deallocate_list(struct node *head) {
  if (head == NULL)
    return;
  struct node *temporary_next;
  while (head != NULL) {
    temporary_next = head->next;
    free(head);
    head = temporary_next;
  }
}
