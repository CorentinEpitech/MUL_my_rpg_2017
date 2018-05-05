/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** Options button configuration
*/

# include "rpg.h"

void setup_volume_settings_button(rpg_t *rpg)
{
	button_t conf;
	sfIntRect rec = { 590, 507, 80, 82 };
	sfVector2f origin = { (rec.width / 2), (rec.height / 2) };
	sfTexture *texture = get_texture(rpg, aBtnSp);

	conf.type = btnVolume;
	conf.pos.x = 0;
	conf.pos.y = 0;
	conf.onClick = default_click_callback;
	conf.onHover = default_hover_callback;
	conf.onStart = nothing_callback;
	conf.state = gameOnSettings;
	conf.sprite = sfSprite_create();
	sfSprite_setTexture(conf.sprite, texture, sfFalse);
	sfSprite_setTextureRect(conf.sprite, rec);
	sfSprite_setOrigin(conf.sprite, origin);
	conf.rect = rec;
	conf.next = NULL;
	add_button(rpg, conf);
	info("Configured volume button for settings view!");
}

void setup_return_settings_button(rpg_t *rpg)
{
	button_t conf;
	sfIntRect rec = { 265, 0, 265, 80 };
	sfTexture *texture = get_texture(rpg, aBtnSp);

	conf.type = btnReturn;
	conf.pos.x = 320;
	conf.pos.y = 830;
	conf.onClick = default_click_callback;
	conf.onHover = default_hover_callback;
	conf.onStart = btn_return_released;
	conf.state = gameOnSettings;
	conf.sprite = sfSprite_create();
	sfSprite_setTexture(conf.sprite, texture, sfFalse);
	sfSprite_setTextureRect(conf.sprite, rec);
	sfSprite_setPosition(conf.sprite, conf.pos);
	conf.rect = rec;
	conf.next = NULL;
	add_button(rpg, conf);
	info("Configured return button for setting view!");
}

void setup_fullscreen_settings_button(rpg_t *rpg)
{
	button_t conf;
	sfIntRect rec = { 265, 240, 265, 80 };
	sfTexture *texture = get_texture(rpg, aBtnSp);

	conf.type = btnFullscreen;
	conf.pos.x = 320;
	conf.pos.y = 440;
	conf.onClick = default_click_callback;
	conf.onHover = default_hover_callback;
	conf.onStart = nothing_callback; // TODO: Start fullscreen
	conf.state = gameOnSettings;
	conf.sprite = sfSprite_create();
	sfSprite_setTexture(conf.sprite, texture, sfFalse);
	sfSprite_setTextureRect(conf.sprite, rec);
	sfSprite_setPosition(conf.sprite, conf.pos);
	conf.rect = rec;
	conf.next = NULL;

	add_button(rpg, conf);
	info("Configured fullscreen button for setting view!");
}