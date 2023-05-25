#include <stdio.h>

typedef struct list *List;

typedef int Value;

List ListNew(void);

void ListAdd(List, Value);
