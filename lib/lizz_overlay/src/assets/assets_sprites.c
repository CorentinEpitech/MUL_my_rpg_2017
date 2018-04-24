/*
** EPITECH PROJECT, 2018
** lizz_overlay
** File description:
** assets_sprite functions
*/

# include "utils.h"
# include "debug.h"
# include "lizz.h"

static void print_debug_1(char *assets, int x, int y)
{
	lizz_info("Position of \"");
	lizz_print(1, assets);
	lizz_print(1, "\" button changed to: x = ");
	lizz_print(1, lizz_itoa(x));
	lizz_print(1, ", y = ");
	lizz_print(1, lizz_itoa(y));
	lizz_print(1, "\n");
}

// TODO: free itoa
static void print_debug_2(char *assets, sfIntRect rect, bool reset)
{
	lizz_info("Texture rect of \"");
	lizz_print(1, assets);
	lizz_print(1, "\" button changed to: heigth = ");
	lizz_print(1, lizz_itoa(rect.height));
	lizz_print(1, ", width = ");
	lizz_print(1, lizz_itoa(rect.width));
	lizz_print(1, ", top = ");
	lizz_print(1, lizz_itoa(rect.top));
	lizz_print(1, ", left = ");
	lizz_print(1, lizz_itoa(rect.left));
	if (reset)
		lizz_print(1, " (reset by default)");
	lizz_print(1, "\n");
}

/*
** Changer la position d'une sprite
** @param (assets_t *assets) - Bouton
** @param (int x) - Position en x
** @param (int y) - Position en y
** @return (void)
*/
void lizz_assets_set_position(assets_t *assets, int x, int y)
{
	sfVector2f pos;

	if (!assets) {
		lizz_error("Button can't be NULL.\n");
		return;
	}

	if (!assets->sprite || !assets->texture || !assets->name)
		return;

	pos.x = x;
	pos.y = y;
	assets->pos.x = pos.x;
	assets->pos.y = pos.y;
	sfSprite_setPosition(assets->sprite, pos);
	print_debug_1(assets->name, x, y);
}

/*
** Changer le rectangle d'un sprite (annimations par exemple)
** @param (assets_t *assets) - Bouton
** @param (sfIntRect *rect) - Rectangle a mettre en place (hauteur, longeur,
** top et left)
** Set rect to NULL equals to reset by default the rectangle shape
** @return (void)
*/
void lizz_assets_set_texture_rect(assets_t *assets, sfIntRect *rect)
{
	sfIntRect r;
	bool reset = false;

	if (!assets) {
		lizz_error("Asset can't be NULL.\n");
		return;
	}

	if (!assets->sprite || !assets->name)
		return;

	if (rect == NULL) {
		r = assets->def_rect;
		reset = true;
	} else
		r = *rect;

	sfSprite_setTextureRect(assets->sprite, r);
	print_debug_2(assets->name, r, reset);
}

/*
** Changer la rotation d'un sprite
** @param (assets_t *assets) - Bouton
** @param (float angle) - Angle en degrés
** @return (void)
*/
void lizz_assets_set_rotation(assets_t *assets, float angle)
{
	char *deg = NULL;

	if (!assets) {
		lizz_error("Asset can't be NULL.\n");
		return;
	}

	if (!assets->sprite || !assets->name)
		return;

	sfSprite_setRotation(assets->sprite, angle);
	lizz_info("Rotation of \"");
	lizz_print(1, assets->name);
	lizz_print(1, "\" asset changed to ");
	deg = lizz_itoa(((int)angle));
	lizz_print(1, deg);
	free(deg);
	lizz_print(1, " degrees.\n");
}
