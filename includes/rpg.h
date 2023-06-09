/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** rpg
*/


#ifndef _RPG_H__
    #define _RPG_H__

    #include "gl.h"
    #include "jp.h"
    #include "view.h"
    #include "player.h"
    #include <time.h>
    #include <math.h>
    #include <stdbool.h>
    #include "menu.h"

    #define WINDOW_NAME "Zombie Quarter Rampage"

    #define MINECRAFT_FONT 8888
    #define CRYSTAL_FONT 8889
    #define TLOU_FONT 8890

    #define SPLASH_SCREEN_TEXT1 9999
    #define SPLASH_SCREEN_TEXT2 10001
    #define LOST_TEXT 10002
    #define WIN_TEXT 10402

    #define EVENT_WINDOW_CLOSE 1
    #define EVENT_INVENTORY_OPEN 454545
    #define INVENTORY_SIZE 16
    #define M_PI 3.14159265358979323846

    #define EVENT_DIALOGUE_CHOICE 651546

    #define XP_SOUND_PATH "resources/sounds/xp.ogg"
    #define XP_SOUND_ID 10
    #define MAIN_THEME_PATH "resources/sounds/main_theme_tlou.ogg"
    #define MAIN_THEME_ID 11
    #define BASEMENT_SOUND_PATH "resources/sounds/basement.ogg"
    #define BASEMENT_SOUND_ID 12
    #define INV_SOUND_PATH "resources/sounds/open-bag-sound.ogg"
    #define INV_SOUND_ID 13
    #define DROP_SOUND_PATH "resources/sounds/drop_sound.ogg"
    #define DROP_SOUND_ID 14
    #define NATURE_SOUND_PATH "resources/sounds/nature.ogg"
    #define NATURE_SOUND_ID 15
    #define PAPER_SOUND_PATH "resources/sounds/paper.ogg"
    #define PAPER_SOUND_ID 16
    #define RADIATION_SOUND_PATH "resources/sounds/radiations.ogg"
    #define RADIATION_SOUND_ID 17
    #define GROCERY_SOUND_PATH "resources/sounds/grocery.ogg"
    #define GROCERY_SOUND_ID 18
    #define HEART_SOUND_PATH "resources/sounds/heart.ogg"
    #define HEART_SOUND_ID 19
    #define PIECE_SOUND_PATH "resources/sounds/piece.ogg"
    #define PIECE_SOUND_ID 20
    #define MUSICIAN_SOUND_PATH "resources/sounds/tloumusician.ogg"
    #define MUSICIAN_SOUND_ID 21
    #define TALKIEFR_SOUND_PATH "resources/sounds/talkie_fr.ogg"
    #define TALKIEFR_SOUND_ID 22
    #define TALKIEEN_SOUND_PATH "resources/sounds/talkie_en.ogg"
    #define TALKIEEN_SOUND_ID 23
    #define RAIN_SOUND_PATH "resources/sounds/rain.ogg"
    #define RAIN_SOUND_ID 24

    #define DIALOGUE_CHOICE_TIMEOUT (seconds < 1)

    #define RS_RAIN "resources/shader/rain.frag"
    #define RS_BLOOD "resources/shader/blood.frag"
    #define RS_FADE "resources/shader/fade.frag"
    #define RS_TORCH "resources/shader/torch.frag"

    #define GET_SAVE_GAMELANGUAGE my_strcmp(jp_search(data, \
        "game_language")->value.p_str, "fr") == 0 ? FR : EN;
    #define SAVE_GAMELANGUAGE rpg->settings->game_language == FR ? "fr" : "en";

    typedef struct pos_s {
        int x;
        int y;
    } pos_t;

    typedef struct tiled_object_s {
        char *name;
        int id;
        float height;
        float width;
        int is_trigger;
        int is_exit;
        sfVector2f pos;
        struct tiled_object_s *next;
    } tiled_object_t;

    typedef struct tile_s {
        int id;
        struct tiled_object_s *colisions;
        struct tile_s *next;
    } tile_t;

    typedef struct layer_s {
        int id;
        char *class;
        char *name;
        int opacity;
        char *type;
        bool_t visible;
        int width;
        int height;
        int tiles_count;
        pos_t *pos;
        int z_index;
        int *data;
        char *color;
        struct tiled_object_s *objects;
        struct tiled_object_s *sounds;
        sfSprite **sprites;
        struct layer_s *next;
    } layer_t;

    typedef struct tilesets_l {
        char *name;
        char *path;
        int tile_count;
        int width;
        int height;
        struct tilesets_l *next;
    } tilesets_t;

    typedef struct dialog_option_s {
        char *text;
        char *next_dialog;
    } dialog_option_t;

    typedef struct dialog_func_s {
        char *name;
        void (*func)(void*);
    } dialog_func_t;

    typedef struct dialog_s {
        char *name;
        char *text;
        char *function;
        dialog_option_t **options;
        struct dialog_s *next;
    } dialog_t;

    typedef struct npc_s {
        char *name;
        char *texture_path;
        char *default_dialog;
        bool_t one_time;
        sfVector2f pos;
        sfSprite *sprite;
        sfTexture *texture;
        sfIntRect rect;
        dialog_t *dialogs;
        sfClock *clock;
        struct npc_s *next;
    } npc_t;

    typedef struct map_s {
        char *map_path;
        char *map_name;
        int map_width;
        int map_height;
        int tile_width;
        int tile_height;
        char *tileset_path;
        sfTexture **textures;
        layer_t *layers;
        npc_t *npcs;
        struct tilesets_l *tilesets;
        struct tile_s *tiles;
        struct map_s *next;
    } map_t;

    /*SHADER*/

    typedef struct shader_s {
        sfShader *shader_rain;
        sfShader *shader_blood;
        sfShader *shader_fade;
        sfShader *shader_torch;
        sfRenderStates states_rain;
        sfRenderStates states_blood;
        sfRenderStates states_fade;
        sfRenderStates states_torch;
        int rain_bool;
        int blood_bool;
        int fade_bool;
        int fade_val;
        int torch_bool;
        sfClock *shader_clock;
        sfClock *fade_clock;
    } shader_t;
    sfRenderStates init_renderstate(sfShader *shader);
    sfRenderStates init_renderstate2(sfShader *shader);
    shader_t *init_shader(void);

    #define resolution_vec "resolution",(sfVector2f){1920, 1080}

    typedef enum language_type_e {
        FR,
        EN
    } language_type_t;

    typedef struct languages_s {
        char *name;
        char *fr;
        char *en;
    } languages_t;

    typedef struct menu_s {
        sfTexture *settings_bg_texture;
        sfSprite *settings_bg_sprite;
        sfSprite *slider_sprite;
        sfTexture *slider_texture;
        sfRectangleShape *slider_back;
        int slider_val;
        bool active;
    } menu_t;

    typedef struct menu_background_s {
        sfTexture *background_menu_t;
        sfSprite *bg_menu_s;
        sfRectangleShape *bg_escape;
        bool active;
    } menu_background_t;

    typedef enum wmode_e {
        NUL,
        FSCREEN,
        WINDOWED
    } wmode_t;

    typedef struct menu_save_s {
        sfTexture *bg_texture;
        sfSprite *bg_sprite;
        bool active;
    } menu_save_t;

    typedef struct menu_keybinds_s {
        sfTexture *settings_bg_key_texture;
        sfSprite *settings_bg_key_sprite;
        bool active;
    } menu_keybinds_t;

    typedef struct settings_s {
        language_type_t game_language;
        int volume;
        wmode_t window_mode;
    } settings_t;

    typedef struct save_s {
        int loaded;
        char *name;
        char *path;
        char *format;
        char **npc_interactions;
    } save_t;

    typedef struct splash_screen_s {
        sfClock *clock;
    } splash_screen_t;

    typedef struct quests_func_s {
        char *name;
        void (*func)(void*);
    } quests_func_t;

    typedef struct quest_s {
        char *id;
        char *name;
        char *description;
        char *type;
        char *func;
        struct quest_s *next;
    } quest_t;

    typedef struct sounds_s {
        int id;
        sfClock *start;
        sfClock *fade;
        float fade_time;
        struct sounds_s *next;
    } sounds_t;

    typedef struct devide_text_s {
        sfVector2f pos;
        char *text;
        sfColor color;
        int max_len;
        int line_spaces;
    } devide_text_t;

    typedef struct narative_s {
        sfText *text;
        char *str;
        sfClock *clock;
    } narative_t;

    typedef struct hud_s {
        sfRectangleShape *hp_bar;
        sfRectangleShape *hp_bar_back;
        sfRectangleShape *hunger_bar;
        sfRectangleShape *hunger_bar_back;
    } hud_t;

    typedef enum game_state_e {
        MENU,
        GAME,
        COMBAT,
        PAUSE,
        GAME_LOST,
        GAME_WIN
    } game_state_t;

    typedef struct combat_history_s {
        int i_lauch_combat1_status;
        int i_lauch_combat2_status;
        int i_lauch_combat3_status;
    } combat_history_t;


    typedef struct rpg_s {
        int debug;
        char *actual_map;
        int game_state;
        int maps_loaded;
        hud_t *hud;
        dialog_t *actual_dialog;
        sfClock *actual_clock;
        npc_t *actual_npc;
        map_t *maps;
        GLib_t *glib;
        menu_background_t *background;
        menu_t *menu;
        menu_keybinds_t *menu_key;
        menu_save_t *menu_save;
        player_t *player;
        languages_t **languages;
        settings_t *settings;
        save_t *save;
        splash_screen_t *splash_screen;
        quest_t *quests;
        sounds_t *sounds;
        narative_t *narative;
        shader_t *shader;
        combat_history_t *combat_history;
        char **quests_in_progress;
        char **quests_completed;
        char **chests_opened;
        sfClock *global_clock;
    } rpg_t;

    typedef struct keyboard_images_s {
        sfKeyCode key;
        int id;
    } keyboard_images_t;

    typedef struct keys_arr_s {
        char *name;
        sfKeyCode key;
    } keys_arr_t;

    typedef struct interactions_s {
        char *name;
        void (*func)(rpg_t *, sfVector2f pos);
        void (*on_exit)(rpg_t *, sfVector2f pos);
    } interactions_t;

    typedef struct chests_s {
        char *name;
        void (*func)(rpg_t *, tiled_object_t *obj);
    } chests_t;

    typedef struct bullets_s {
        float speed;
        float angle;
        int status;
        sfVector2f pos;
        sfVector2f scale;
        sfIntRect rect;
        sfTexture *texture;
        sfSprite *sprite;
        struct bullets_s *next;
    } bullets_t;

    typedef struct zombies_s {
        sfVector2f pos;
        int type;
        int hp;
        int damage;
        float speed;
        float attack_speed;
        sfRectangleShape *hitbox;
        struct zombies_s *next;
        sfSprite *sprite;
        sfTexture *texture;
        sfIntRect rect;
        sfVector2f scale;
        sfClock *clock;
        sfClock *attack_clock;
        sfClock *clock_animation;
        int animation;
        int alive;
        int direction;
        int last_distance;
        int status_anim;
        sfRectangleShape *hp_bar;
    } zombies_t;

    #define RGWW rpg->glib->window->window
    #define RPA rpg->player->assets
    #define RGWW rpg->glib->window->window
    #define RGW rpg->glib->window
    #define RPK rpg->player->keys
    #define RPH rpg->player->hitbox
    #define RSG rpg->settings->game_language
    #define PA player->assets
    #define RSNI rpg->save->npc_interactions
    #define RPAQ rpg->player->assets->quest_icons
    #define RM rpg->menu_key
    #define RP rpg->player
    #define RSV rpg->settings->volume
    #define RPI rpg->player->inventory

    #define windoww rpg->glib->window->window
    #define ZOMBIE_0 "resources/assets/combat/zombie_0.png"
    #define ZOMBIE_1 "resources/assets/combat/zombie_1.png"
    #define ZOMBIE_2 "resources/assets/combat/zombie_2.png"
    #define ZOMBIE_3 "resources/assets/combat/zombie_3.png"
    #define ZOMBIE_4 "resources/assets/combat/zombie_4.png"
    #define ZOMBIE_5 "resources/assets/combat/zombie_5.png"
    #define ZOMBIE_6 "resources/assets/combat/zombie_6.png"
    #define ZOMBIE_7 "resources/assets/combat/zombie_7.png"
    #define ZOMBIE_ATK0 "resources/assets/combat/z_naked_melee_00.png"
    #define ZOMBIE_ATK1 "resources/assets/combat/z_naked_melee_01.png"
    #define ZOMBIE_ATK2 "resources/assets/combat/z_naked_melee_02.png"
    #define ZOMBIE_ATK3 "resources/assets/combat/z_naked_melee_03.png"
    #define ZOMBIE_ATK4 "resources/assets/combat/z_naked_melee_04.png"
    #define ZOMBIE_ATK5 "resources/assets/combat/z_naked_melee_05.png"
    #define ZOMBIE_ATK6 "resources/assets/combat/z_naked_melee_06.png"
    #define ZOMBIE_DEATH0 "resources/assets/combat/z_naked_death_00.png"
    #define ZOMBIE_DEATH1 "resources/assets/combat/z_naked_death_01.png"
    #define ZOMBIE_DEATH2 "resources/assets/combat/z_naked_death_02.png"
    #define ZOMBIE_DEATH3 "resources/assets/combat/z_naked_death_03.png"
    #define ZOMBIE_DEATH4 "resources/assets/combat/z_naked_death_04.png"
    #define ZOMBIE_DEATH5 "resources/assets/combat/z_naked_death_05.png"
    #define ZOMBIE_DEATH6 "resources/assets/combat/z_naked_death_06.png"
    #define ZOMBIE_DEATH7 "resources/assets/combat/z_naked_death_07.png"
    #define ZOMBIE_DEATH8 "resources/assets/combat/z_naked_death_08.png"
    void animation_zombie1(zombies_t *l);
    #define WITCH_0 "resources/assets/combat/z_witch_move2_01.png"
    #define WITCH_1 "resources/assets/combat/z_witch_move2_02.png"
    #define WITCH_2 "resources/assets/combat/z_witch_move2_03.png"
    #define WITCH_3 "resources/assets/combat/z_witch_move2_04.png"
    #define WITCH_4 "resources/assets/combat/z_witch_move2_05.png"
    #define WITCH_5 "resources/assets/combat/z_witch_move2_06.png"
    #define WITCH_6 "resources/assets/combat/z_witch_move2_07.png"
    #define WITCH_7 "resources/assets/combat/z_witch_move2_08.png"
    #define WITCH_ATK0 "resources/assets/combat/z_witch_melee_00.png"
    #define WITCH_ATK1 "resources/assets/combat/z_witch_melee_01.png"
    #define WITCH_ATK2 "resources/assets/combat/z_witch_melee_02.png"
    #define WITCH_ATK3 "resources/assets/combat/z_witch_melee_03.png"
    #define WITCH_ATK4 "resources/assets/combat/z_witch_melee_04.png"
    #define WITCH_ATK5 "resources/assets/combat/z_witch_melee_05.png"
    #define WITCH_ATK6 "resources/assets/combat/z_witch_melee_06.png"
    #define WITCH_DEATH0 "resources/assets/combat/z_witch_death_01.png"
    #define WITCH_DEATH1 "resources/assets/combat/z_witch_death_02.png"
    #define WITCH_DEATH2 "resources/assets/combat/z_witch_death_03.png"
    #define WITCH_DEATH3 "resources/assets/combat/z_witch_death_04.png"
    #define WITCH_DEATH4 "resources/assets/combat/z_witch_death_05.png"
    #define WITCH_DEATH5 "resources/assets/combat/z_witch_death_06.png"
    #define WITCH_DEATH6 "resources/assets/combat/z_witch_death_07.png"




    #define map_night "resources/assets/combat/map_night.jpg"
    #define guy "resources/assets/combat/guy.png"
    #define bullet "resources/assets/combat/bullet.png"
    #define atkplayer attack_player(rpg,tmp->attack_clock, \
    tmp->attack_speed,tmp->damage)
    #define condition_window sfRenderWindow_isOpen\
    (rpg->glib->window->window) && number_zombies(combat->zombies) > 0
    int number_zombies(zombies_t *zombies);
    #define sfp sfSprite_setPosition
    char **wave_zombie1(void);

    #define torch_resolution1 (sfShader_setVec2Uniform(rpg->shader->\
    shader_torch, "resolution", (sfVector2f) {1960 - 1920 * (\
    sfView_getCenter(rpg->player->view->view).x - rpg->player->\
    pos.x) / sfView_getCenter(rpg->player->view->view).x, 1150 +\
    1080 * (sfView_getCenter(rpg->player->view->view).y - rpg->player->\
    pos.y) / sfView_getCenter(rpg->player->view->view).y}))

    typedef struct combat_s {
        zombies_t *zombies;
        bullets_t *bullets;
        sfClock *clock_move;
        sfClock *clock_shoot;
    } combat_t;

    /* COMBAT */
    void init_combat_history(rpg_t *rpg);
    void init_guy(rpg_t *rpg);
    void init_background(rpg_t *rpg);
    int combat(rpg_t *rpg);
    combat_t *init_combat(void);
    void move_player(rpg_t *rpg, sfClock *clock);
    float shot_angle(sfVector2f pos, sfVector2i mouse);
    void gun_manager(rpg_t *rpg, combat_t *combat);
    void insert_zombies(rpg_t *rpg, zombies_t **list);
    void draw_zombies(zombies_t *list, rpg_t *rpg);
    int colision_with_rect(sfRectangleShape *rect, sfVector2f pos);
    int colision_bullet_zombies(zombies_t *list, bullets_t *bullets);
    void animation_zombie(zombies_t *list);
    void delete_bullet_outmap(bullets_t **list);
    void draw_bullets(bullets_t *bullets, rpg_t *rpg);
    void insert_bullet(bullets_t **list, rpg_t *rpg);
    void move_bullets(bullets_t *bullets, rpg_t *rpg);
    void delete_bullet_status(bullets_t **list);
    void move_zombies(zombies_t *list, rpg_t *rpg);
    void delete_zombie_status(zombies_t **list);
    #define sfc sfTexture_createFromFile
    #define sfs sfTime_asSeconds
    void cbt_draw_player(rpg_t *rpg);
    void cbt_change_player_rect(player_t *player);
    void wave(char **wave, zombies_t **zombies);
    void insert_zombies_coord_id(zombies_t **list, sfVector2f pos, int id);
    void animation_witch1(zombies_t *l);
    void swap_status_anim_cbt(zombies_t *l);
    void swap_status_anim_move(zombies_t *l);
    void swap_status_anim_dead(zombies_t *l);

    typedef struct sounds_arr_s {
        char *name;
        void (*func)(rpg_t *, sfVector2f pos);
    } sounds_arr_t;

    int my_strcmp(char const *s1, char const *s2);
    char *my_strcat(char *dest, char const *src);
    char *my_strcpy(char *dest, char const *src);
    char *my_strcat_malloc(char *dest, char const *src);
    int my_atoi(char const *str);
    char *my_strdup(char *str);
    int my_putstr(char const *str, int precision);
    int my_putchar(char c);
    int arr_len(char **arr);
    int my_strlen(char const *str);
    char *my_strndup(const char *str, int n);
    int get_mid_char(const char *str);
    char **add_item_to_arr(char **arr, char *item);
    int my_arr_contains(char **arr, char *str);
    int my_arrlen(char **arr);

    /* GAME */
    void game_loop(rpg_t *rpg);
    void game_start(rpg_t *rpg);
    void start_game(rpg_t *rpg, char *save_path);

    /* SPLASH SCREEN */
    void draw_splash_screen(rpg_t *rpg);
    void init_splash_screen(rpg_t *rpg);

    /* LANGUAGE */
    char *get_language(rpg_t *rpg, char *name, language_type_t language);

    /* SAVE */
    void save_save(rpg_t *rpg);
    void reset_a_save(rpg_t *rpg);
    int load_settings(rpg_t *rpg, parsed_data_t *data);
    int load_game(rpg_t *rpg, parsed_data_t *data);
    int load_save(rpg_t *rpg, char *path);
    int load_npc_interactions(save_t *save, parsed_data_t *data);
    int load_player(player_t *player, parsed_data_t *data);
    void save_settings(rpg_t *rpg);
    int load_quests_in_progress(rpg_t *rpg, parsed_data_t *data);
    void save_npc_interactions(rpg_t *rpg);
    void save_game(rpg_t *rpg);
    void save_quests_in_progress(rpg_t *rpg);
    void save_player(rpg_t *rpg);
    void save(rpg_t *rpg);
    int load_combats(rpg_t *rpg, parsed_data_t *data);
    void save_game_timeline(rpg_t *rpg);
    int load_game_timeline(rpg_t *rpg, parsed_data_t *data);
    int load_quests_completed(rpg_t *rpg, parsed_data_t *data);
    void save_quests_completed(rpg_t *rpg);
    int load_chests_opened(rpg_t *rpg, parsed_data_t *data);
    void save_combats(rpg_t *rpg);
    void save_chests_opened(rpg_t *rpg);

    /* QUESTS */
    void start_dialogue_default(npc_t *npc, rpg_t *rpg);
    void start_quest(rpg_t *rpg, char *id);
    quest_t *get_quest(rpg_t *rpg, char *id);
    void draw_quests(rpg_t *rpg);
    quests_func_t *get_quests_func_arr(void);
    quest_t *get_quest_by_id(rpg_t *rpg, char *id);
    void stop_quest(rpg_t *rpg, char *id);
    int quest_is_in_progress(rpg_t *rpg, char *quest_name);
    int quest_is_completed(rpg_t *rpg, char *quest_name);
    void draw_quests_ig(rpg_t *rpg);
    void draw_quests_inv(rpg_t *rpg);

    /* MAP */
    void load_maps(rpg_t *rpg);
    int create_map(rpg_t *rpg, char *json_path);
    sfTexture **load_tiles_textures(map_t *map);
    sfSprite **load_layer_sprites(layer_t *layer, map_t *map);
    int load_map_layers(map_t *map, parsed_data_t *data);
    void load_layer_objects(parsed_data_t *data, layer_t *layer);
    void load_tiles_colisions(map_t *map, parsed_data_t *data);
    void load_tilesets(parsed_data_t *data, map_t *map);
    int *load_layer_data_arr(parsed_data_t *data);
    void draw_map(map_t *map, char *json_path, rpg_t *rpg);
    void draw_layer(rpg_t *rpg, layer_t *layer);
    void draw_layer_by_class(map_t *map, rpg_t *rpg, char *class);
    void draw_layer_by_order(map_t *map, rpg_t *rpg, int order);
    void draw_inventory(rpg_t *rpg);
    void draw_items(rpg_t *rpg);
    map_t *get_map(rpg_t *rpg, char *map_path);

    /* VIEW */
    void set_view_on_player(rpg_t *rpg);
    void zoom_view(rpg_t *rpg, float value, float time);
    void reset_view(rpg_t *rpg);

    /* PLAYER */
    void check_game_lost(rpg_t *rpg);
    int get_key_id(sfKeyCode key, rpg_t *rpg);
    void draw_game_lost_screen(rpg_t *rpg);
    void *key_pressed(rpg_t *rpg);
    void draw_player(rpg_t *rpg);
    void draw_game_win_screen(rpg_t *rpg);
    void change_player_rect(player_t *player);
    void check_player_moovment(player_t *player, map_t *map, rpg_t *rpg);
    int check_colisions(
        map_t *map,
        sfVector2f pos,
        player_t *player,
        rpg_t *rpg
    );
    void check_interactions(player_t *player, map_t *map, rpg_t *rpg);
    void check_interactions_other_maps(rpg_t *rpg);
    keyboard_images_t *get_keyboard_array(void);
    void hunger_lost(rpg_t *rpg);

    /* INVENTORY*/
    int add_item_to_inventory(int id, rpg_t *rpg);
    int remove_item_to_inventory(rpg_t *rpg, int pos, int force);
    int add_item_to_inventory_pos(rpg_t *rpg, int pos, int id);
    void handle_inventory_system(rpg_t *rpg);
    item_func_t *get_items_functions_arr(void);
    void exec_item_func(rpg_t *rpg, int id);
    void handle_drop_use_button(rpg_t *rpg);
    char *get_item_name(int id);
    void draw_item_popup(rpg_t *rpg);
    int remove_itemid_inventory(rpg_t *rpg, int item_id, int force);
    int check_if_items_is_here(rpg_t *rpg, int id);

    /* CHEST */
    chests_t *get_chests_array(void);
    void check_chests(player_t *player, map_t *map, rpg_t *rpg);
    int chest_is_opened(rpg_t *rpg, char *chest_name);

    /* NPC */
    npc_t *get_npc(map_t *map, char *name);
    void draw_npc(rpg_t *rpg, npc_t *npc);
    void start_dialogue(rpg_t *rpg, npc_t *npc);
    void next_dialogue(rpg_t *rpg, int choice);
    void display_dialogue(rpg_t *rpg);
    dialog_func_t *get_npc_func_arr(void);
    void check_dialogue_function(rpg_t *rpg, dialog_t *dialogue);
    void change_dialogue(rpg_t *rpg, char *id);

    /* TEXT */
    void divide_a_sftext(sfText *text, sfVector2f pos, rpg_t *rpg);
    void divide_a_text(rpg_t *rpg, devide_text_t *devide_text);

    /* WINDOW */
    void change_window_mode(rpg_t *rpg, wmode_t mode);

    /* SOUNDS */
    void fade_sound(rpg_t *rpg, int id, float time);
    void start_sound(rpg_t *rpg, int id);
    void check_sounds(rpg_t *rpg);
    void s_house(rpg_t *rpg, sfVector2f pos);
    void s_nature(rpg_t *rpg, sfVector2f pos);
    void fade_all_sounds(rpg_t *rpg, float time);

    /* FREE */
    void my_free(rpg_t *rpg);

    /* CALL ACTIONS */
    void lampe(void *main);
    void jackfriend_give_weapon(void *main);
    void jackfriend_give_heal(void *main);
    void check_if_gaz_mask(void *);
    void talkie(void *main);
    void i_end(rpg_t *rpg, sfVector2f pos);
    void c_talki(rpg_t *rpg, tiled_object_t *obj);
    void remove_mask(void *main);
    void jack_friend(rpg_t *rpg, sfVector2f pos);
    void npc_give_nothing(void *main);
    void c_resource(rpg_t *rpg, tiled_object_t *obj);
    void c_trashg(rpg_t *rpg, tiled_object_t *obj);
    void i_lauch_combat(rpg_t *rpg, sfVector2f pos);
    void c_bchest(rpg_t *rpg, tiled_object_t *obj);
    void heal(void*);
    void note(void*);
    void food(void *);
    void c_gaz(rpg_t *rpg, tiled_object_t *obj);
    void annia_give_heal(void *main);
    void s_musician_exit(rpg_t *rpg, sfVector2f pos);
    void s_musician(rpg_t *rpg, sfVector2f pos);
    void jack(rpg_t *rpg, sfVector2f pos);
    void s_radiation(rpg_t *rpg, sfVector2f pos);
    void s_radiation_exit(rpg_t *rpg, sfVector2f pos);
    void s_grocery(rpg_t *rpg, sfVector2f pos);
    void s_grocery_exit(rpg_t *rpg, sfVector2f pos);
    void s_basement_exit(rpg_t *rpg, sfVector2f pos);
    void s_nature(rpg_t *rpg, sfVector2f pos);
    void s_nature_exit(rpg_t *rpg, sfVector2f pos);
    void c_fridge(rpg_t *rpg, tiled_object_t *obj);
    void i_soda(rpg_t *rpg, sfVector2f pos);
    void i_paper_grocery(rpg_t *rpg, sfVector2f pos);
    void go_to_annia(void *main);
    void jack_start_quest(void *main);
    void i_pass_fence(rpg_t *rpg, sfVector2f pos);
    void npc_give_food(void*);
    void s_basement(rpg_t *rpg, sfVector2f pos);
    void little_girl(rpg_t *rpg, sfVector2f pos);
    void i_house_basement(rpg_t *rpg, sfVector2f pos);
    void i_grocery_door(rpg_t *rpg, sfVector2f pos);
    void i_paper_resources(rpg_t *rpg, sfVector2f pos);
    void i_paper_music(rpg_t *rpg, sfVector2f pos);
    void i_house1_door(rpg_t *rpg, sfVector2f pos);
    void i_end_map_down(rpg_t *rpg, sfVector2f pos);
    void inte_test(rpg_t *rpg);
    void i_basement_paper(rpg_t *rpg, sfVector2f pos);
    void i_end_map_top(rpg_t *rpg, sfVector2f pos);
    void i_house_door(rpg_t *rpg, sfVector2f pos);
    void i_house_paper(rpg_t *rpg, sfVector2f pos);
    void i_chest(rpg_t *rpg);
    interactions_t *get_interactions_array(void);
    void draw_interaction_popup(
        rpg_t *rpg,
        sfVector2f pos,
        sfKeyCode key,
        char *str
    );

    /* MENU */
    void draw_menu(rpg_t *rpg);
    void init_main_menu(rpg_t *rpg);
    void init_settings_menu(rpg_t *rpg);
    void init_keybinds(rpg_t *rpg);
    void init_buttons_langage(rpg_t *rpg);
    void init_background(rpg_t *rpg);
    void init_keybinds_keys(rpg_t *rpg);
    void draw_menu_keys(rpg_t *rpg);
    void draw_other_keys(rpg_t *rpg);
    void init_saves_buttons(rpg_t *rpg);
    void draw_saves_menu(rpg_t *rpg);
    void init_saves_texts(rpg_t *rpg);
    void draw_settings(rpg_t *rpg);
    void draw_escape_menu(rpg_t *rpg);

    /* HUD */
    void draw_hud(rpg_t *rpg);


    void init_background(rpg_t *rpg);
    void init_all_language(rpg_t *rpg);

    /* LORE */
    void draw_popup_lore(rpg_t *rpg);
    void start_narative_popup(rpg_t *rpg);
    void check_narative_popup(rpg_t *rpg);

    /* POPUP */
    void remove_first_item_popup(rpg_t *rpg);
    void add_item_popup(
        rpg_t *rpg,
        int id,
        inv_popup_action_t action
    );


    /* EVENTS */
    void e_resume_btn(int id, void *main);
    void e_quit(int id, void *main);
    void e_langue_fr(int id, void *main);
    void e_save_btn(int id, void *main);
    void e_langue_en(int id, void *main);
    void e_start_game(int id, void *main);
    void e_key_released(window_t *window, void *main);
    void e_key_pressed(window_t *window, void *main);
    void e_open_inventory(window_t *window, void *main);
    void e_close(window_t *window, void *main);
    void e_dialogue(window_t *window, void *main);
    void e_seeting_game(int id, void *main);
    void e_seeting_keybinds_game(int id, void *main);
    void e_save1(int id, void *main);
    void e_save2(int id, void *main);
    void e_save3(int id, void *main);


    /* INIT */
    void init(rpg_t *rpg);
    void init_quests(rpg_t *rpg);
    void init_player(rpg_t *rpg);
    void init_popup_dialogue(rpg_t *rpg);
    void init_keybinds_otherkeys(rpg_t *rpg);
    void init_glib(rpg_t *rpg);
    void init_game_sounds(rpg_t *rpg);
    void init_npcs(map_t *map, char *path, rpg_t *rpg);
    void init_fonts(rpg_t *rpg);
    void init_backgroound(rpg_t *rpg);
    void init_player_textures(player_t *player);
    void init_window(rpg_t *rpg);
    void init_npc_dialogs(npc_t *npc, parsed_data_t *dialogs_arr, rpg_t *rpg);
    void init_settings(rpg_t *rpg);
    void init_sounds(GLib_t *glib);
    void init_language(rpg_t *rpg);
    void init_popup_lore(rpg_t *rpg);
    void init_hud(rpg_t *rpg);
    void init_slider(rpg_t *rpg);
    void init_escape_menu(rpg_t *rpg);
    void init_game_lost_screen(player_t *player, rpg_t *rpg);
    void init_save(rpg_t *rpg);
    void init_events(rpg_t *rpg);
    void init_inventory_popup(rpg_t *rpg);
    void init_player_assets(player_t *player);
    void init_rpg(rpg_t *rpg, int ac, char **av);
    void init_game_win_screen(player_t *player, rpg_t *rpg);
    void init_popup_interaction(rpg_t *rpg);
    void init_player_items_packs(player_t *player);
    void init_quest_assets(rpg_t *rpg);
    void init_inventory(rpg_t *rpg);
    void init_player_assets_dialogue(player_t *player);
    void check_shader(rpg_t *rpg);
    void check_torch(rpg_t *rpg);
    #define TOPK rpg->player->keys->up.state == 1
    #define BOTK rpg->player->keys->down.state == 1
    #define LEFTK rpg->player->keys->left.state == 1
    #define RIGHTK rpg->player->keys->right.state == 1
    #define TOPLEFTK (TOPK && LEFTK)
    #define TOPRIGHTK (TOPK && RIGHTK)
    #define BOTLEFTK (BOTK && LEFTK)
    #define BOTRIGHTK (BOTK && RIGHTK)
    #define torch_mouse(x, y) sfShader_setVec2Uniform(\
    rpg->shader->shader_torch, "mouse", (sfVector2f){x, y})
    #define tr 1960 - 1920 * (sfView_getCenter(rpg->player->view->view).x\
    - rpg->player->pos.x ) / sfView_getCenter(rpg->player->view->view).x
    #define lr 1150 + 1080 * (sfView_getCenter(rpg->player->view->view).y\
    - rpg->player->pos.y ) / sfView_getCenter(rpg->player->view->view).y
    #define br 1960 - 7.4 * 1920 * (sfView_getCenter(rpg->player->view->view)\
    .x - rpg->player->pos.x ) / sfView_getCenter(rpg->player->view->view).x
    #define rr 1150 + 9.2 * 1080 * (sfView_getCenter(rpg->player->view->view).y\
    - rpg->player->pos.y ) / sfView_getCenter(rpg->player->view->view).y;
    #define draw_shader_torch (sfRenderWindow_drawRectangleShape(rpg->glib->\
    window->window, rect, &rpg->shader->states_torch))
    #define v2f(x, y) ((sfVector2f) {x, y})
    int doc_function(int ac, char **av);
    #define global_sec (sfTime_asSeconds\
    (sfClock_getElapsedTime(rpg->global_clock)))

#endif
