#include "../../header.h"

void draw_3D_line_west(t_general *general, t_vec ray, int wall_height, int imageincre)
{
    int             i;
    int             x_int;
    unsigned int    color;

    for (i = 0; i < wall_height; i++)
    {
        x_int = (int) roundf(ray.y);
        color = get_color_wall_west(general, x_int, i, wall_height);
        my_mlx_pixel_put(&general->mlib->data, imageincre, (HEIGHT - wall_height) / 2 + i, color);
    }
}

void draw_3D_line_east(t_general *general, t_vec ray, int wall_height, int imageincre)
{
    int             i;
    int             x_int;
    unsigned int    color;

    for (i = 0; i < wall_height; i++)
    {
        x_int = (int) roundf(ray.y);
        color = get_color_wall_east(general, x_int, i, wall_height);
        my_mlx_pixel_put(&general->mlib->data, imageincre, (HEIGHT - wall_height) / 2 + i, color);
    } 
}

void draw_3D_line_south(t_general *general, t_vec ray, int wall_height, int imageincre)
{

    int             i;
    int             x_int;
    unsigned int    color;

    for (i = 0; i < wall_height; i++)
    {
        x_int = (int) roundf(ray.x);
        color = get_color_wall_south(general, x_int, i, wall_height);
        my_mlx_pixel_put(&general->mlib->data, imageincre, (HEIGHT - wall_height) / 2 + i, color);
    } 
}

void draw_3D_line_north(t_general *general, t_vec ray, int wall_height, int imageincre)
{
    int i;
    int x_int;
    unsigned int color;

    for (i = 0; i < wall_height; i++)
    {
        x_int = (int) roundf(ray.x);
        color = get_color_wall_north(general, x_int, i, wall_height);
        my_mlx_pixel_put(&general->mlib->data, imageincre, (HEIGHT - wall_height) / 2 + i, color);
    }
}