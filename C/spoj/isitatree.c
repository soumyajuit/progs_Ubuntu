#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_VERTEX_NUM 10000
#define MAX_V	(MAX_VERTEX_NUM + 1)

typedef struct undir_graph_s{
	int num_v;
	int num_e;
	int component;
	void* adj_mat;
}undir_graph_t;	

#define MEM_FAILURE()							\
	do{								\
		printf("\n Memory failure in function "			\
			   "%s at %d line \n", __FUNCTION__, __LINE__);	\
		exit(0);						\
	} while(0);

#define DEP_HASH_MASK	16
#define AUX_V(NUM)	(NUM+1)
#define START_SENTINAL	-1
#define VISITED		1
#define DEP_MAX_ELE	(1 << DEP_HASH_MASK)
#define DEP_CHAIN_SENTINAL	(MAX_V + 1)
#define DEP_ELE_GET(dep_ele) (dep_ele & ((1 << DEP_HASH_MASK) - 1))
#define DEP_ELE_GET_LAST(dep_ele) (dep_ele >> DEP_HASH_MASK)
#define DEP_HASH(_new_ele, _last_ele_store)				\
			((_new_ele << DEP_HASH_MASK) | _last_ele_store)

#define SET_DEP(struct_v1_arr, v2)		\
	do {					\
		struct_v1_arr[v2] |= 1;		\
	} while(0);

#define DEP_HASH_SET(_struct_v1_arr, _new_ele, _last_ele)			\
	do {									\
		int _last_ele_store = DEP_ELE_GET(_struct_v1_arr[_last_ele]);	\
		_struct_v1_arr[_last_ele] =					\
				DEP_HASH(_new_ele, _last_ele_store);		\
		_struct_v1_arr[_new_ele] =					\
				DEP_HASH(DEP_CHAIN_SENTINAL, 0);		\
		SET_DEP(_struct_v1_arr, _new_ele)				\
	} while(0);

#define ADJ_MAT(_struct_t_graph, v)	(&((int*)_struct_t_graph->adj_mat)[v * AUX_V(t_graph->num_v)])

#define DEP_HASH_SET1(_struct_v1_arr, _new_ele, _last_ele)		\
	do {								\
		int _last_ele_store = _struct_v1_arr[_last_ele];	\
		_struct_v1_arr[_last_ele] =				\
				DEP_HASH(_new_ele, _last_ele_store);	\
		SET_DEP(_struct_v1_arr, _new_ele)			\
	} while(0);

undir_graph_t* undir_graph_create(int num_v, int num_e);
undir_graph_t* undir_graph_destroy(undir_graph_t* t_graph);

int
main(int argc, char *argv[])
{
	int num_v = 0;
	int num_e = 0;
	int num_test_cases = 0;
	undir_graph_t *t_graph = NULL;
	
	scanf("%d", &num_test_cases);

	while(num_test_cases != 0) {
		scanf("%d %d", &num_v, &num_e);
		t_graph = undir_graph_create(num_v, num_e);
		undir_graph_populate(t_graph);
		undir_graph_run_dfs(t_graph);
		t_graph = undir_graph_destroy(t_graph);
		num_test_cases--;
	}
	return 0;
}

undir_graph_t*
undir_graph_create(int num_v, int num_e)
{
	undir_graph_t * n_graph = NULL;

	n_graph = (undir_graph_t*)malloc(sizeof(undir_graph_t)*1);
	n_graph->adj_mat = (int*) malloc(sizeof(int)*AUX_V(num_v)*AUX_V(num_v));

	if ((n_graph == NULL) || (n_graph->adj_mat == NULL)) {
		MEM_FAILURE();
	}
	
	n_graph->num_v = num_v;
	n_graph->num_e = num_e;
	memset(n_graph->adj_mat, 0, sizeof(int)*AUX_V(num_v)*AUX_V(num_v));
	return n_graph;
}

undir_graph_t*
undir_graph_destroy(undir_graph_t* t_graph)
{
	free(t_graph->adj_mat);
	free(t_graph);
	return NULL;
}


int
undir_graph_populate(undir_graph_t* t_graph)
{
	int i;
	int v1;
	int v2;
	int last_ele[t_graph->num_v];

	memset(last_ele, 0, sizeof(int)*AUX_V(t_graph->num_v));

	for(i = 0; i < t_graph->num_e; i++) 
	{
		scanf("%d %d", &v1, &v2);

		if ((v1 < 0) || (v1 > t_graph->num_v) ||
		    (v2 < 0 ) || (v2 > t_graph->num_v)) {
			return -1;
		}

		DEP_HASH_SET(ADJ_MAT(t_graph, v1), 
			     v2, last_ele[v1]);
		last_ele[v1] = v2;
		DEP_HASH_SET(ADJ_MAT(t_graph, v2), 
			     v1, last_ele[v2]);
		last_ele[v2] = v1;
	}

	return 0;
}

static int
undir_graph_dfs(undir_graph_t *t_graph, int v, int *visited_arr)
{
	int next_ele = 0;
	int *v_adj = ADJ_MAT(t_graph, v);
	next_ele  = DEP_ELE_GET_LAST(v_adj[0]);
	
	visited_arr[v] = VISITED;
	while (next_ele != DEP_CHAIN_SENTINAL) {
		if (visited_arr[next_ele] != VISITED) {
			undir_graph_dfs(t_graph, next_ele, visited_arr);
		}
		next_ele = DEP_ELE_GET_LAST(v_adj[next_ele]);
	}
}

static inline int
undir_graph_isatree(undir_graph_t* t_graph)
{
	return (t_graph->num_e <= (t_graph->num_v - t_graph->component));
}


int
undir_graph_run_dfs(undir_graph_t *t_graph)
{
	int i = 0;
	int arr[AUX_V(t_graph->num_v)];
	int *v_arr = NULL;
	int count = 0;
	int component = 0;
	
	memset(arr, 0, sizeof(int) * AUX_V(t_graph->num_v));
	
	for (i = 1; i <= t_graph->num_v; i++) 
	{
		v_arr = ADJ_MAT(t_graph, i);
		if (arr[i] != VISITED) {
			undir_graph_dfs(t_graph, i, arr);
			component++;
		}
	}

	t_graph->component = component;
	for (i = 1; i <= t_graph->num_v; i++) {
		if (arr[i] == VISITED) {
			count++;
		}
	}

	//printf("\n Total number of vertex = %d, total number of traversed = %d component = %d\n", t_graph->num_v, count, t_graph->component);
	
	if (undir_graph_isatree(t_graph)) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
}
