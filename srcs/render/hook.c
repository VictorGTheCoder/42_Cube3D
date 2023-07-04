#include "../../header.h"

int key_pression(int keycode, t_general *general)
{
    if (keycode == KEY_W)
        general->keys->w = 1;
    else if (keycode == KEY_A)
        general->keys->a = 1;
    else if (keycode == KEY_S)
        general->keys->s = 1;
    else if (keycode == KEY_D)
        general->keys->d = 1;
    else if (keycode == KEY_Q)
        general->keys->q = 1;
    else if (keycode == KEY_R)
        general->keys->r = 1;
    else if (keycode == KEY_ARR_R)
        general->keys->arrow_r = 1;
    else if (keycode == KEY_ARR_L)
        general->keys->arrow_l = 1;
    else if (keycode == KEY_M)
        general->scene->mini_map ^= 1; 

    
    return (1);
}

int key_release(int keycode, t_general *general)
{
    if (keycode == KEY_W)
        general->keys->w = 0;
    else if (keycode == KEY_A)
        general->keys->a = 0;
    else if (keycode == KEY_S)
        general->keys->s = 0;
    else if (keycode == KEY_D)
        general->keys->d = 0;
    else if (keycode == KEY_Q)
        general->keys->q = 0;
    else if (keycode == KEY_R)
        general->keys->r = 0;
    else if (keycode == KEY_ARR_R)
        general->keys->arrow_r = 0;
    else if (keycode == KEY_ARR_L)
        general->keys->arrow_l = 0;

    return (0);
}

// Fonction pour gérer les événements souris
int mouse_press(int button, int x, int y, t_mlib *mlib)
{
    (void) button;
    (void) x;
    (void) y;
    (void) mlib;
    return (0);
}

int close_window(t_mlib *mlib)
{
    mlx_destroy_window(mlib->utils.mlx, mlib->utils.win);
    exit(0);
}

int key_press_exit(int keycode, t_general *general)
{
    key_pression(keycode, general);
    //printf("keycode = %d\n", keycode);
    if (keycode == 53)
    {
        exit(EXIT_FAILURE);
    }
    return (0);
}

void move(t_general *general)
{
    float pos_x;
    float pos_y;

    if (general->keys->s == 1)
    {
        pos_x = general->scene->player.pos.x - general->scene->player.speed * general->scene->player.dir.x;
        pos_y = general->scene->player.pos.y - general->scene->player.speed * general->scene->player.dir.y;
        
        if (position_is_valid(general, pos_x, pos_y) == 1)
        {
            general->scene->player.pos.x = pos_x;
            general->scene->player.pos.y = pos_y;
        }
        //print_player(general->scene->player);
    }
    if (general->keys->w == 1)
    {
        pos_x = general->scene->player.pos.x + general->scene->player.speed * general->scene->player.dir.x;
        pos_y = general->scene->player.pos.y + general->scene->player.speed * general->scene->player.dir.y;

        if (position_is_valid(general,pos_x, pos_y) == 1)
        {
            general->scene->player.pos.x = pos_x;
            general->scene->player.pos.y = pos_y;
        }
        //print_player(general->scene->player);
    }
    if (general->keys->a == 1)
    {
        pos_x = general->scene->player.pos.x - general->scene->player.speed * general->scene->player.dir.y * -1;
        pos_y = general->scene->player.pos.y - general->scene->player.speed * general->scene->player.dir.x;


        if (position_is_valid(general,pos_x, pos_y) == 1)
        {
            general->scene->player.pos.x = pos_x;
            general->scene->player.pos.y = pos_y;
        }

        //print_player(general->scene->player);
    }
    if (general->keys->d == 1)
    {
        pos_y = general->scene->player.pos.y + general->scene->player.speed * general->scene->player.dir.x;
        pos_x = general->scene->player.pos.x + general->scene->player.speed * general->scene->player.dir.y * -1;

        if (position_is_valid(general, pos_x, pos_y) == 1)
        {
            general->scene->player.pos.x = pos_x;
            general->scene->player.pos.y = pos_y;
        }

        //print_player(general->scene->player);

    }

    //Changement de direction player
    if (general->keys->q == 1)
    {
        float angle = atan2f(general->scene->player.dir.y, general->scene->player.dir.x);
        angle -= ROTATION_SPEED;
        general->scene->player.dir.x = cosf(angle);
        general->scene->player.dir.y = sinf(angle);
        //print_player(general->scene->player);

    }
    if (general->keys->r == 1)
    {
        float angle = atan2f(general->scene->player.dir.y, general->scene->player.dir.x);
        angle += ROTATION_SPEED;
        general->scene->player.dir.x = cosf(angle);
        general->scene->player.dir.y = sinf(angle);
       // print_player(general->scene->player);

    }
    if (general->keys->arrow_l == 1)
    {
        float angle = atan2f(general->scene->player.dir.y, general->scene->player.dir.x);
        angle -= ROTATION_SPEED;
        general->scene->player.dir.x = cosf(angle);
        general->scene->player.dir.y = sinf(angle);
        //print_player(general->scene->player);

    }
    if (general->keys->arrow_r == 1)
    {
        float angle = atan2f(general->scene->player.dir.y, general->scene->player.dir.x);
        angle += ROTATION_SPEED;
        general->scene->player.dir.x = cosf(angle);
        general->scene->player.dir.y = sinf(angle);
        //print_player(general->scene->player);
    }
}