typedef struct ele {
	int val;
	struct ele* next;
} ele_t;

ele_t* create(const int val);

void append(ele_t* appendTo, ele_t* toAppend);

void printAndFree(ele_t* head);

ele_t* makeN(int len);

int rearrange(int* ar, int n, int pivot_index);

void quick_sort(int* ar, int n);