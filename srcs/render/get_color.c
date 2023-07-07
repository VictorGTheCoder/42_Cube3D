#include "../../header.h"

int get_color_wall_north(t_general *general, t_vec ray, int h_wall, int max_wall_h)
{
    //(void) vector;

    (void ) h_wall;
    t_sprites   *sprites;

    sprites = general->sprites;


    char *pixel;
    unsigned int color;

    int size_wall = general->scene->map.size_wall;

   // int y = (int) ray.y;
    int x = (int) ray.x;

    //printf("%d %d\n",((y % size_wall) * general->sprites->wall_north.sprite_h /size_wall), ((x % size_wall)*general->sprites->wall_north.sprite_w /size_wall));

    pixel = sprites->wall_north->data_spr.addr + ((h_wall * general->sprites->wall_north->sprite_h/ max_wall_h) * sprites->wall_north->data_spr.line_length + ((x % size_wall)*general->sprites->wall_north->sprite_w/size_wall) * (sprites->wall_north->data_spr.bits_per_pixel / 8));
    color = *(unsigned int *)pixel;

    // printf("Color %d\n", color2);

    return (color);
}

int get_color_wall_south(t_general *general, t_vec ray, int h_wall, int max_wall_h)
{
    t_sprites   *sprites;
    char *pixel;
    unsigned int color;
    int size_wall;
    int x;
    
    x = (int) ray.x;
    size_wall = general->scene->map.size_wall;
    sprites = general->sprites;
    pixel = sprites->wall_south->data_spr.addr + ((h_wall * general->sprites->wall_south->sprite_h/ max_wall_h) * sprites->wall_south->data_spr.line_length + ((x % size_wall)*general->sprites->wall_south->sprite_w/size_wall) * (sprites->wall_south->data_spr.bits_per_pixel / 8));
    color = *(unsigned int *)pixel;
    return (color);
}

int get_color_wall_east(t_general *general, t_vec ray, int h_wall, int max_wall_h)
{
    t_sprites   *sprites;
    char *pixel;
    unsigned int color;
    int size_wall;
    int y;
    
    y = (int) ray.y;
    size_wall = general->scene->map.size_wall;
    sprites = general->sprites;
    pixel = sprites->wall_east->data_spr.addr + (((y % size_wall)*general->sprites->wall_east->sprite_w/size_wall) * sprites->wall_east->data_spr.line_length + (h_wall * general->sprites->wall_east->sprite_h/ max_wall_h) * (sprites->wall_east->data_spr.bits_per_pixel / 8));
    color = *(unsigned int *)pixel;
    return (color);
}

int get_color_wall_west(t_general *general, t_vec ray, int h_wall, int max_wall_h)
{
    t_sprites   *sprites;
    char *pixel;
    unsigned int color;
    int size_wall;
    int y;
    
    y = (int) ray.y;
    size_wall = general->scene->map.size_wall;
    sprites = general->sprites;
    pixel = sprites->wall_west->data_spr.addr + (((y % size_wall)*general->sprites->wall_west->sprite_w/size_wall) * sprites->wall_west->data_spr.line_length + (h_wall * general->sprites->wall_west->sprite_h/ max_wall_h) * (sprites->wall_west->data_spr.bits_per_pixel / 8));
    color = *(unsigned int *)pixel;
    return (color);
    
}