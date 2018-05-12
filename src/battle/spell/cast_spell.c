/*
** EPITECH PROJECT, 2018
** cast_spell
** File description:
** rpg
*/

#include "rpg.h"

static void cast_simple_case_spell(battle_t *battle, int a)
{
	sfVector2f pos;
	sfVector2f size;

	if (!battle->hero->spell[a]->cast) {
		for (int i = 0; i < 120; i++) {
			pos = sfRectangleShape_getPosition(
				battle->fight[battle->id]->map[i]);
			size = sfRectangleShape_getSize(
				battle->fight[battle->id]->map[i]);
			sfRectangleShape_setFillColor(
			battle->fight[battle->id]->map[i], sfTransparent);
			display_simple_case(battle, pos, size, i);
		}
	} else {
		/* if (a == 0) */
		/* 	cast_heal(rpg, battle); */
		/* else if (a == 1) */
		/* 	cast_fire(rpg, battle); */
	}
}

static void cast_double_case_spell(battle_t *battle, int a)
{
	sfVector2f pos = sfSprite_getPosition(battle->hero->form);

	if (!battle->hero->spell[a]->cast)
		display_double_case(battle, pos);
}

void cast_spell(rpg_t *rpg, battle_t *battle, int a)
{
	printf("SPELL %d\n", a);
	if (a == 0 || a == 1)
		cast_simple_case_spell(battle, a);
	else if ( a == 2 || a == 3)
		cast_double_case_spell(battle, a);
}
