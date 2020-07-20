#include <stdio.h>

#include "hashtable.h"

void display_number(void *value) {
  
  double d = *(double*)value;
  printf("found %f\n", d);
}

int main(int argc, const char* argv[]) {
  HashTable table;
  
  /* Choose initial capacity of 10 */
  /* Specify the size of the keys and values you want to store once */
  ht_setup(&table, sizeof(int), sizeof(double), 10);
  
  ht_reserve(&table, 100);
  
  int x = 6;
  double y = 9;
  ht_insert(&table, &x, &y);
  
  if (ht_contains(&table, &x)) {
    y = *(double*)ht_lookup(&table, &x);
    /* Or use convenience macros */
    y = HT_LOOKUP_AS(double, &table, &x);
    printf("%d's value is: %f\n", x, y);
  }
  
  x = 7;
  y = 10;
  ht_insert(&table, &x, &y);

  /* iterate values */
  ht_foreach(&table, &display_number);
  
  ht_erase(&table, &x);
  
  ht_clear(&table);
  ht_destroy(&table);
}
