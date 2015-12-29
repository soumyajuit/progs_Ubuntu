#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


/* Better with conditional compiling */
//static int print_info 0;

typedef struct m_heap_s{
	unsigned int *arr;
	int start;
	int end;
}m_heap_t;


#define MAX_HEAP_SIZE      10000 
#define LEFT_CHILD(_idx, _offset)   ((2 * (_idx - _offset) + 1) + _offset)
#define RIGHT_CHILD(_idx, _offset)  ((2 * (_idx - _offset) + 2) + _offset)
#define PARENT(_idx, _offset)    (((_idx - _offset) - 1)/2 + _offset)

#define ASSERT  assert

#define SWAP(_arr, _i, _j)                  \
        do {                                \
            unsigned int _tmp = _arr[_i];   \
            _arr[_i] = _arr[_j];            \
            _arr[_j] = _tmp;                \
        }while(0);

#define PRINT_ARR(_arr, _start, _end)       \
        {                                   \
            printf("\n ============ \n");   \
            int i = _start;                 \
            for (;i <= _end; i++) {         \
                printf("\n %u", arr[i]);    \
            }                               \
        }

static int
partition(unsigned int arr[], int start, int end, int pivot);

static int
find_kth_element(unsigned int arr[], int k, int start, int end)
{

    int pivot = start + (end - start)/2;
    int idx = 0;

    //printf("\n ====> K = %d start = %d end = %d \n", k, start, end);
    //PRINT_ARR(arr, start, end);
    
    if (k > (end - start)) {
        printf("\n K = %d is more than diff=%d \n", k, (end-start));
        return -1;
    } else if (start > end) {
        printf("\n start = %d is more than end = %d can't happen ?? \n", start, end);
        return -1;
    }

    ASSERT(k >= 0);

    idx = partition(arr, start, end, pivot);
    printf("\n ====> K = %d start = %d end = %d idx = %d\n", k, start, end, idx);

    if ((idx - start) == k - 1) {
        printf("\n Element is %d\n", arr[idx]);
        return idx;
    } else if ((idx - start) < k) {
        return find_kth_element(arr, k-(idx-start), idx+1, end);
    } else {
        return find_kth_element(arr, k, start, idx -1);
    }

    return 0;
}

static int
partition(unsigned int arr[], int start, int end, int pivot)
{

    int i = start-1;
    int end_t = end-1;
    int j = start;

    ASSERT(start <= end);

    SWAP(arr, pivot, end);

    unsigned int pivot_ele = arr[end];

    for(;j <= end_t; j++) {
        if (arr[j] > pivot_ele) {
            i++;
            SWAP(arr, i, j);
        }
    }

    i++;

    //printf("\n\n ==> The pivot element is %u and idx is %d\n", arr[end], i);
    //PRINT_ARR(arr, end)
    SWAP(arr, i, end);

    return i;
}


static unsigned int
max_heapify_down(unsigned int arr[], int offset, int len, int idx)
{
    int largest = idx;
    int left = LEFT_CHILD(idx, offset); 
    int right = RIGHT_CHILD(idx, offset);

    if (left < len && arr[left] > arr[idx]) {
        largest = left;
    }

    if (right < len && arr[right] > arr[largest]) {
        largest = right;
    }

    //printf("\n %d %d %u %u \n", largest, idx, arr[largest], arr[idx]);
    if (largest != idx) {
        //ASSERT(largest >= 0 && largest < len);
        SWAP(arr, largest, idx);
    } else {
        return idx; 
    }

    return max_heapify_down(arr, offset, len, largest);
}

static int
max_heapify_up(unsigned int arr[], int offset, int len, int idx)
{

    if (idx == 0) {
        return 0;
    }

    if (arr[PARENT(idx, offset)] < idx) {
        SWAP(arr, PARENT(idx, offset), idx);
    }

    return max_heapify_up(arr, offset, len, PARENT(idx, offset));
}


static int
create_max_heap(unsigned int arr[], int start, int end)
{
    int len = end - start;
    int i = start + (len/2);

    printf("\n Create max-heap ==== \n");

    for(; i>= start; i--) {
        printf("\n ======== %d %d %d\n", start, len, i);
        max_heapify_down(arr, start, len, i);
    }

    return 0;
}
        
static int
is_max_heap_int(unsigned int arr[], int offset, int end_idx, int idx)
{
    if (idx >= end_idx) {
        return 1;
    }

    if (((LEFT_CHILD(idx, offset) < end_idx) && arr[idx] < arr[LEFT_CHILD(idx, offset)]) ||
        ((RIGHT_CHILD(idx, offset) < end_idx) && arr[idx] < arr[RIGHT_CHILD(idx, offset)])) {
        printf("\n The heap broke at %d \n", idx);
        return 0;
    }

    return (is_max_heap_int(arr, offset, end_idx, LEFT_CHILD(idx, offset)) &&
            is_max_heap_int(arr, offset, end_idx, RIGHT_CHILD(idx, offset)));
}


static void
print_heap(unsigned int arr[], int offset, int end, int idx)
{

    if (idx >= end) {
        return;
    }

    printf ("\n The children of arr[%d] == %u", idx, arr[idx]);
    

    printf(" Left child arr[%d] == %u ", (LEFT_CHILD(idx, offset) >= end ? -1: LEFT_CHILD(idx, offset)),
                                         (LEFT_CHILD(idx, offset) >= end ? -1 : arr[LEFT_CHILD(idx, offset)]));

    printf(" Right child arr[%d] == %u ", (RIGHT_CHILD(idx, offset) >= end ? -1: RIGHT_CHILD(idx, offset)),
                                          (RIGHT_CHILD(idx, offset) >= end ? -1 : arr[RIGHT_CHILD(idx, offset)]));

    printf("\n");

    print_heap(arr, offset, end, LEFT_CHILD(idx, offset));
    print_heap(arr, offset, end, RIGHT_CHILD(idx, offset));

    return;
}

static inline void
is_max_heap(unsigned int arr[], int offset, int end, int start)
{
    int ret = 0;
    ret = is_max_heap_int(arr, 0, end, start);
    if (ret) {
        printf("\n correct max heap \n");
    } else {
        printf("\n Not max heap \n");
    }

}

static inline unsigned int
get_max(unsigned int arr[], int start)
{
	return arr[start];
}

static unsigned int
extract_max(unsigned int arr[], int start, int end)
{
	SWAP(arr, start, end);
	max_heapify_down(arr, start, end - start-1, start);	
	is_max_heap(arr, start,  end, start);
	return arr[end];
}

int main(int argc, char *argv[])
{
    unsigned int arr[MAX_HEAP_SIZE];
    int len;
    int i = 0;
    int part_idx = -1;
    int ret = 0;

    scanf("%d", &len);

    for(i = 0; i < len; i++) {
        scanf("%u", &arr[i]);
    }

    part_idx = find_kth_element(arr, 500, 0, len-1);

    ASSERT(part_idx < len || (part_idx == -1));
    create_max_heap(arr, 0, part_idx+1); 
    create_max_heap(arr, part_idx+1, len); 
    //PRINT_ARR(arr, 0, len-1);

    is_max_heap(arr, 0, part_idx+1, 0);
    is_max_heap(arr, part_idx+1, len, part_idx+1);

/*
    printf("\n \n ====> \n");
    print_heap(arr, 0, part_idx+1, 0);
    printf("\n \n ====> \n");
    print_heap(arr, part_idx+1, len, part_idx+1);
*/
    printf("\n %u \n", extract_max(arr, 0, part_idx));

    return 0;
}

