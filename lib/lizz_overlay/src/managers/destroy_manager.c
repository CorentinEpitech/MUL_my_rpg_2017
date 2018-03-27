/*
** EPITECH PROJECT, 2018
** lizz_overlay
** File description:
** destroy_manager functions
*/

# include "utils.h"
# include "debug.h"
# include "lizz.h"

static void destroy_all_btn(void)
{
	btn_t *tmp = NULL;

	while (lizz->btn != NULL) {
		tmp = lizz->btn;
		lizz->btn = lizz->btn->next;
		tmp->destroy(tmp);
		free(tmp);
	}
}

void lizz_destroy_all(void)
{
	destroy_all_btn();
}
