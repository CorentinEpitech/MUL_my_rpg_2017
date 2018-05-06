/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** events_manager functions
*/

# include "rpg.h"

void mouse_events(rpg_t *rpg, sfEvent *event)
{
	sfEventType type = event->type;

	if (type == sfEvtMouseButtonPressed) {
		mouse_button_pressed(rpg, event->mouseButton);
	} else if (type == sfEvtMouseButtonReleased) {
		mouse_button_released(rpg, event->mouseButton);
	} else if (type == sfEvtMouseMoved) {
		mouse_moved(rpg, event->mouseMove);
	}
}

void keyboard_manager(rpg_t *rpg, sfEvent *event)
{
	(void)rpg;
	(void)event;
}

void poll_event(rpg_t *rpg, sfEvent *event)
{
	while (sfRenderWindow_pollEvent(rpg->win, event)) {
		if (event->type == sfEvtClosed)
			sfRenderWindow_close(rpg->win);

		mouse_events(rpg, event);
		views_events(rpg, event);
	}
}
