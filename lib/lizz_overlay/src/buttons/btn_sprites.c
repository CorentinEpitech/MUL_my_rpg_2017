/*
** EPITECH PROJECT, 2018
** lizz_overlay
** File description:
** btn_sprite functions
*/

# include "utils.h"
# include "debug.h"
# include "lizz.h"

static void print_debug_1(char *btn, int x, int y)
{
	lizz_info("Position of \"");
	lizz_print(1, btn);
	lizz_print(1, "\" button changed to: x = ");
	lizz_print(1, lizz_itoa(x));
	lizz_print(1, ", y = ");
	lizz_print(1, lizz_itoa(y));
	lizz_print(1, "\n");
}

static void print_debug_2(char *btn, sfIntRect rect)
{
	lizz_info("Texture rect of \"");
	lizz_print(1, btn);
	lizz_print(1, "\" button changed to: heigth = ");
	lizz_print(1, lizz_itoa(rect.height));
	lizz_print(1, ", width = ");
	lizz_print(1, lizz_itoa(rect.width));
	lizz_print(1, ", top = ");
	lizz_print(1, lizz_itoa(rect.top));
	lizz_print(1, ", left = ");
	lizz_print(1, lizz_itoa(rect.left));
	lizz_print(1, "\n");
}

/*
** Changer la position d'une sprite
** @param (btn_t *btn) - Bouton
** @param (int x) - Position en x
** @param (int y) - Position en y
** @return (void)
*/
void lizz_btn_set_position(btn_t *btn, int x, int y)
{
	sfVector2f pos;

	if (!btn) {
		lizz_error("Button can't be NULL.\n");
		return;
	}

	if (!btn->sprite || !btn->texture || !btn->name)
		return;

	pos.x = x;
	pos.y = y;
	btn->current_pos.columns = pos.x;
	btn->current_pos.rows = pos.y;
	sfSprite_setPosition(btn->sprite, pos);
	print_debug_1(btn->name, x, y);
}

/*
** Changer le rectangle d'un sprite (annimations par exemple)
** @param (btn_t *btn) - Bouton
** @param (sfIntRect *rect) - Rectangle a mettre en place (hauteur, longeur,
** top et left)
** @return (void)
*/
void lizz_btn_set_texture_rect(btn_t *btn, sfIntRect *rect)
{
	if (!btn) {
		lizz_error("Button can't be NULL.\n");
		return;
	}

	if (!btn->sprite || !btn->name)
		return;

	sfSprite_setTextureRect(btn->sprite, *rect);
	print_debug_2(btn->name, *rect);
}
