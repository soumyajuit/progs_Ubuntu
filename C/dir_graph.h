#define MAX_VERTEX_NUM 1024
#define MAX_EDGE_NUM	1024
#define MAX_VERTEX	(MAX_VERTEX_NUM + 1)
#define MAX_EDGE	(MAX_EDGE_NUM + 1)

typedef struct graph_V_s {
	int node_num;
	int adj[MAX_VERTEX];
	int num_dependency;
	int num_dependent;
	short visited;
} graph_V_t;

typedef struct dir_graph {
	int num_v;
	int num_e;
	graph_V_t* v_set[MAX_VERTEX];
} dir_graph_t;	

dir_graph_t* create_graph(int num_v, int num_e);
graph_V_t* create_vertex(int node_num);
int create_edges(dir_graph_t *t_graph, graph_V_t* vertex, int node_num);
int populate_graph(dir_graph_t *t_graph);
void graph_display(dir_graph_t* t_graph, int choice);
void graph_display_show_edges(dir_graph_t *t_graph);
void graph_display_show_edge_chain(dir_graph_t *t_graph);
void graph_display_depout_show(dir_graph_t* t_graph);
void graph_display_depin_show(dir_graph_t* t_graph);
int graph_run_dfs(dir_graph_t* t_graph);

#define MEM_FAILURE()							\
	do{								\
		printf("\n Memory failure in function "			\
			   "%s at %d line \n", __FUNCTION__, __LINE__);	\
		exit(0);						\
	} while(0);

#define DEP_HASH_MASK	12
#define START_SENTINAL	-1
#define DEP_MAX_ELE	(1 << DEP_HASH_MASK)
#define DEP_CHAIN_SENTINAL	(MAX_VERTEX + 1)	
#define DEP_ELE_GET(dep_ele) (dep_ele & ((1 << DEP_HASH_MASK) - 1))
#define DEP_ELE_GET_LAST(dep_ele) (dep_ele >> DEP_HASH_MASK)
#define DEP_HASH(_new_ele, _last_ele_store)				\
			((_new_ele << DEP_HASH_MASK) | _last_ele_store)

#define DEP_HASH_SET(_struct_v1, _new_ele, _last_ele)			\
	do {								\
		int _last_ele_store = _struct_v1->adj[_last_ele];	\
		_struct_v1->adj[_last_ele] =				\
				DEP_HASH(_new_ele, _last_ele_store);	\
	} while(0);

#define SET_DEP(struct_v1, v2)		\
	do {				\
		struct_v1->adj[v2] = 1;	\
	} while(0);
