/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** views_configuration functions
*/

# include "rpg.h"

void configure_main_view(rpg_t *rpg)
{
	configure_main_play_button(rpg);
	configure_main_settings_button(rpg);
	configure_main_credits_button(rpg);
	configure_main_quit_button(rpg);
	configure_main_history_button(rpg);
}

void configure_settings_view(rpg_t *rpg)
{
	configure_settings_volume_button(rpg);
	configure_settings_volume_slider(rpg);
	configure_settings_return_button(rpg);
	configure_settings_fullscreen_button(rpg);
}

void configure_credits_view(rpg_t *rpg)
{
	configure_credits_return_button(rpg);

	configure_history_return_button(rpg);

	configure_select_return_button(rpg);
	configure_select_play_button(rpg);
}

void configure_pause_view(rpg_t *rpg)
{
	configure_pause_resume_button(rpg);
	configure_pause_save_button(rpg);
	configure_pause_settings_button(rpg);
	configure_pause_quit_button(rpg);
}
