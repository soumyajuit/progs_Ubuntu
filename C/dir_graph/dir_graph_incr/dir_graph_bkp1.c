#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MEM_FAILURE()							\
	do{								\
		printf("\n Memory failure in function "			\
			   "%s at %d line \n", __FUNCTION__, __LINE__);	\
		exit(0);						\
	} while(0);

#define MAX_VERTEX	1024
#define MAX_EDGE	1024
#define DEP_HASH_MASK	12
#define DEP_MAX_ELE	(1 << DEP_HASH_MASK)
#define DEP_ELE_GET(dep_ele) (dep_ele & ((1 << DEP_HASH_MASK) - 1))
#define DEP_ELE_GET_LAST(dep_ele) (dep_ele >> DEP_HASH_MASK)

#define SET_DEP(struct_v1, v2)		\
	do {				\
		struct_v1->adj[v2] = 1;	\
	} while(0);


typedef struct graph_V_s {
	int node_num;
	int adj[MAX_VERTEX -1];
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
void graph_display_depout_show(dir_graph_t* t_graph);
void graph_display_depin_show(dir_graph_t* t_graph);
int graph_run_dfs(dir_graph_t* t_graph);

int main(int argc, char *argv[])
{
	int num_v, num_e;
	int choice;
	dir_graph_t *t_graph = NULL;

	scanf("%d", &num_v);
	choice = atoi(argv[1]);
	t_graph = create_graph(num_v, 0);
	populate_graph(t_graph);
	graph_display(t_graph, choice);
	return 0;
}


dir_graph_t* create_graph(int num_v, int num_e)
{
	dir_graph_t* t_graph = NULL;
	
	t_graph = (dir_graph_t*) malloc(sizeof(dir_graph_t)*1);

	if ((num_v > MAX_VERTEX) || (num_e > MAX_EDGE)) {
		printf("\n wrong argument \n");
		exit(0);
	}

	if (t_graph == NULL) {
		MEM_FAILURE();
 	}

	t_graph->num_v = num_v;
	t_graph->num_e = num_e;
	memset(t_graph->v_set, 0, sizeof(graph_V_t*)*MAX_VERTEX);
	//printf("\n Graph ptr = %p \n", t_graph);

	return t_graph;
}


graph_V_t*
create_vertex(int node_num)
{
	graph_V_t* new_v = NULL;
	
	new_v = (graph_V_t*)malloc(sizeof(graph_V_t) * 1);
	if (new_v == NULL) {
		MEM_FAILURE();
	}
	memset((void*)new_v, 0, sizeof(graph_V_t));
	new_v->node_num = node_num;
	//printf("\n vertex prt = %p \n", new_v);
	return new_v;
}


int 
populate_graph(dir_graph_t *t_graph)
{

	int i=0;
	int ret = 0;

	for (i = 0; i < t_graph->num_v; i++) {
		t_graph->v_set[i] = create_vertex(i);
	}

	for (i = 0; i < t_graph->num_v; i++) {
		ret = create_edges(t_graph, t_graph->v_set[i], i);

		if (ret < 0) {
			printf("\n Error in argument \n");
			exit(0);
		}
	}
}

int 
create_edges(dir_graph_t *t_graph, graph_V_t* vertex, int node_num)
{
	int i = 0;
	int num_dependency = 0;
	int t_node_num = 0;

	scanf("%d", &num_dependency);

	if ((num_dependency < 0) || (num_dependency > t_graph->num_v)) {
		return -1;
	}

	vertex->num_dependency = num_dependency;

	for (i = 0; i < vertex->num_dependency; i++) {
		scanf("%d", &t_node_num);
		if ((t_node_num < 0) || (t_node_num > t_graph->num_v-1)) {
			return -1;
		}
		SET_VERTEX_VALUE(vertex, t_node_num);
		t_graph->v_set[t_node_num]->num_dependent++;
	}

	return 0;
}


void
graph_display(dir_graph_t* t_graph, int choice)
{
	switch(choice) {
		case 1:
			graph_display_depout_show(t_graph);
			break;
		case 2:
			graph_display_depin_show(t_graph);
			break;
		case 3:
			graph_display_show_edges(t_graph);
			break;
		default:
			printf("\n Not a correct choice ");
	}
}

void
graph_display_depout_show(dir_graph_t* t_graph)
{
	int i = 0;

	for(i = 0; i < t_graph->num_v; i++) {
		printf("\n vertex = %d has dep = %d \n", 
				i, t_graph->v_set[i]->num_dependency);
	}
}

void
graph_display_depin_show(dir_graph_t* t_graph)
{
	int i = 0;

	for(i = 0; i < t_graph->num_v; i++) {
		printf("\n vertex = %d has dep = %d \n", 
				i, t_graph->v_set[i]->num_dependent);
	}
}


void
graph_display_show_edges(dir_graph_t *t_graph)
{

	int i=0;
	int j=0;

	for (i=0; i < t_graph->num_v; i++) {
		printf("\n Vertext [%d] = [", i);
		for (j = 0; j < t_graph->num_v; j++) {
			if (t_graph->v_set[i]->adj[j] == 1) {
				printf(" %d", j);
			}
		}
		printf("]\n");
	}
}


int
graph_run_dfs(dir_graph_t* t_graph)
{
	int i = 0;
	graph_V_t *v  = NULL;

	for(i = 0; i < t_graph->num_v; i++) {
		v = t_graph->v_set[i];
		if (v->num_dependent == 0) {
			dfs_visit(t_graph, v);
		}
	}
}

int
dfs_visit(dir_graph_t* t_graph, graph_V_t* v)
{
	return 0;
}




