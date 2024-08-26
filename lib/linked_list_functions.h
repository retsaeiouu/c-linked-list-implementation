#pragma once

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  int value;
  struct node *next;
};

struct node *new_head(int value);
void insertion_at_head(struct node **head, int value);
void insertion_before(struct node *previous_node, int value);
void insertion_at_tail(struct node *head, int value);
void reverse_list(struct node **head);
void print_list(struct node *head);
void deallocate_list(struct node *head);
