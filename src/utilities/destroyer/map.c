/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** player destroyer
*/

# include "rpg.h"

void free_iterations(interact_t **it)
{
	for (int i = 0; it[i] != NULL; i++) {
		free(it[i]->msg);
		free(it[i]);
	}
	free(it);
}

void destroy_map(rpg_t *rpg)
{
	for (int i = 0; rpg->map[i]; i++) {
		// for (int j = 0; rpg->map[i]->layer[j]; j++)
		// 	free(rpg->map[i]->layer[j]);
		free_iterations(rpg->map[i]->it);
		//free(rpg->map[i]->layer);
		free(rpg->map[i]);
	}
	free(rpg->map);
}
