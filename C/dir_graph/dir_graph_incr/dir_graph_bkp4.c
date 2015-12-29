#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "dir_graph.h"

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

	for (i = 0; i <= t_graph->num_v; i++) {
		t_graph->v_set[i] = create_vertex(i);
	}

	for (i = 1; i <= t_graph->num_v; i++) {
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
	int last_ele = 0;

	scanf("%d", &num_dependency);

	if ((num_dependency < 0) || (num_dependency > t_graph->num_v)) {
		return -1;
	}

	vertex->num_dependency = num_dependency;

	for (i = 0; i < vertex->num_dependency; i++) {
		scanf("%d", &t_node_num);
		if ((t_node_num < 1) || (t_node_num > t_graph->num_v)) {
			return -1;
		}
		SET_DEP(vertex, t_node_num);
		DEP_HASH_SET(vertex, t_node_num, last_ele);
		last_ele = t_node_num;
		t_graph->v_set[t_node_num]->num_dependent++;
	}
	DEP_HASH_SET(vertex, DEP_CHAIN_SENTINAL, last_ele);

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
		case 4:
			graph_display_show_edge_chain(t_graph);
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


static void
graph_display_travrse_chain(graph_V_t* v)
{
	int next_ele = 0;
	next_ele =  DEP_ELE_GET_LAST(v->adj[0]);
	while(next_ele != DEP_CHAIN_SENTINAL) {
		printf(" %d",next_ele);
		next_ele = DEP_ELE_GET_LAST(v->adj[next_ele]);
	}
}

static void
graph_display_iterate_all(graph_V_t* v, int num_v)
{
	int j = 0;
	for (j = 1; j < num_v; j++) {
		if (DEP_ELE_GET(v->adj[j]) != 0) {
			//printf(" %d(%d)", j, t_graph->v_set[i]->adj[j]);
			printf(" %d", j);
		}
	}
}

void
graph_display_show_edges(dir_graph_t *t_graph)
{

	int i=0;
	int j=0;
	graph_V_t* v = NULL;

	for (i=1; i <= t_graph->num_v; i++) {
		printf("\n Vertext [%d] = [", i);
		graph_display_travrse_chain(t_graph->v_set[i]);
		//graph_display_iterate_all(t_graph->v_set[i] ,t_graph->num_v);
		printf("]\n");
	}
}

void
graph_display_show_edge_chain(dir_graph_t *t_graph)
{

	int i=0;
	int j=0;

	for (i=0; i < t_graph->num_v; i++) {
		printf("\n Vertext [%d] = [", i);
		for (j = 0; j < t_graph->num_v; j++) {
			if (DEP_ELE_GET_LAST(t_graph->v_set[i]->adj[j]) != 0) {
				printf(" %d(%d)", j, t_graph->v_set[i]->adj[j]);
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




