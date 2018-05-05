/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** menu_views functions
*/

# include "rpg.h"

void credits_view(rpg_t *rpg)
{
	sfSprite *sprite = get_sprite(rpg, "bg_credits");

	if (sprite == NULL)
		return;

	sfRenderWindow_clear(rpg->win, sfBlack);
	sfRenderWindow_setTitle(rpg->win, "Legacy Of The Kek | Credits");
	sfRenderWindow_drawSprite(rpg->win, sprite, NULL);
}


void settings_view(rpg_t *rpg)
{
	sfSprite *sprite = get_sprite(rpg, "bg_settings");
	slider_t *vol = get_slider(rpg, "sld_volume");

	if (sprite == NULL || vol == NULL)
		return;

	sfRenderWindow_clear(rpg->win, sfBlack);
	sfRenderWindow_setTitle(rpg->win, "Legacy Of The Kek | Options");
	sfRenderWindow_drawSprite(rpg->win, sprite, NULL);

	if (vol != NULL) {
		sfRenderWindow_drawText(rpg->win, vol->text, NULL);
	}
}

void main_view(rpg_t *rpg)
{
	sfSprite *sp = get_sprite(rpg, "bg_main");

	sfRenderWindow_setTitle(rpg->win, "Legacy Of The Kek | Menu Principal");

	if (sp == NULL)
		return;

	sfRenderWindow_drawSprite(rpg->win, sp, NULL);
}