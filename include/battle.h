/*
** EPITECH PROJECT, 2018
** battle
** File description:
** rpg
*/

# ifndef RPG_BATTLE_H
# define RPG_BATTLE_H

# include "structs.h"

# define 	MAP_X 		(225)
# define 	MAP_Y 		(180)
# define 	B_X 		(114)
# define 	B_Y 		(72)

void		battle_management(rpg_t *, battle_t *);

/* FREE */
void		destroy_battle(rpg_t *);

/* DISPLAY */
void		display_map(rpg_t *, battle_t *, int);
void		display_interface(rpg_t *, battle_t *);
void		display_enemy_stats(rpg_t *, sfVector2f);
void		display_current_target(rpg_t *, battle_t *);
void		fill_map_state(battle_t *, int);
void		draw_all(rpg_t *);
void		display_hero(rpg_t *, battle_t *);
void		display_enemy(rpg_t *, battle_t *);
void		display_other_enemy(rpg_t *, battle_t *, int);

/* HERO */
void		check_deplacement(battle_t *);
void		check_attack(battle_t *);
void		hero_deplacement(rpg_t *, battle_t *);
void		hero_attack(rpg_t *, battle_t *);
void		set_attack_orientation(battle_t *, sfVector2f);
void		set_color(battle_t *, int, sfColor);
void		display_enemy_dead_animation(rpg_t *, battle_t *, int);
void		display_hero_damage(rpg_t *, battle_t *, int);

/* SPELL */

void		cast_spell(rpg_t *, battle_t *, int);
void		display_simple_case(battle_t *, sfVector2f, sfVector2f);
void		display_double_case(battle_t *, sfVector2f);
void		cast_heal(rpg_t *, battle_t *);
void		cast_fire(rpg_t *, battle_t *);
void		cast_ice(rpg_t *, battle_t *);
void		cast_storm(rpg_t *, battle_t *);
void		display_spell_damage(rpg_t *, battle_t *, int , int);
void		display_strom_damage(rpg_t *, battle_t *);
void		display_ice_damage(rpg_t *, battle_t *);
void		hit_the_target(rpg_t *, battle_t *, int, int);

/* AI_ENEMY */
void		enemy_turn(rpg_t *, battle_t *);
bool		check_enemy_attack(rpg_t *, battle_t *, int, sfVector2f);
void		enemy_attack_anim(rpg_t *, battle_t *, sfVector2f, int);
bool		enemy_go_left(rpg_t *, battle_t *, int, sfVector2f);
bool		enemy_go_right(rpg_t *, battle_t *, int, sfVector2f);
bool		enemy_go_up(rpg_t *, battle_t *, int, sfVector2f);
bool		enemy_go_down(rpg_t *, battle_t *, int, sfVector2f);
void		display_enemy_damage(rpg_t *, battle_t *, int);

/* EVENT */
void		battle_event_management(rpg_t *, battle_t *, sfEvent *);
void		reset_map_state(battle_t *);
void		change_turn(battle_t *);
bool		end_battle(rpg_t *, battle_t *);

/*EVENT->INTERACTION*/
void		interaction(battle_t *, sfEvent *);
void		select_or_unselect(battle_t *, int);

/*EVENT->DEPLACEMENT->HERO*/
void		deplacement(battle_t *);

/*EVENT->SPELL*/
void		cast_spell_attack(battle_t *);

/*EVENT->ATTACK*/
void		attack(battle_t *);

/* INIT */
void		configure_battle(rpg_t *);

// init_fight.c

sfRectangleShape **create_battle_map(sfVector2f *);

sfText 		*create_text(sfFont *, char *, sfVector2f , sfColor);

# endif
