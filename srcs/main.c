#include "../header.h"

int main(int argc, char const *argv[])
{
    (void) argc;
    (void) argv;

    /* SCOPE TESTS VICTOR */
    {
        t_scene     *scene;
        t_mlib      *mlib;
        t_sprites   *sprites;
        int         size_file;
        char const  *filename;
        char        **copy;

        filename = "map2.cub";
        printf("TEST\n");
        scene = malloc(sizeof(t_scene));
        if (scene == NULL)
            return (0);

        size_file = get_size_file(filename);
        copy = copy_file (filename, size_file);

        sprites = malloc(sizeof(t_sprites));

        t_sprite    *wall_north = malloc(sizeof(t_sprite));
        t_sprite    *wall_south = malloc(sizeof(t_sprite));
        t_sprite    *wall_east = malloc(sizeof(t_sprite));
        t_sprite    *wall_west = malloc(sizeof(t_sprite));


        sprites->wall_north = wall_north;
        sprites->wall_south = wall_south;
        sprites->wall_east = wall_east;
        sprites->wall_west = wall_west;

        int end_part_1 = parser(sprites, scene, copy);        
        map_parser(scene, copy, end_part_1);

        mlib = malloc(sizeof(t_mlib));
        if (mlib == NULL)
            return (0);

        
        parser(sprites, scene, copy);

        scene->player.coord_ini = get_player_coord(scene->map.matrix);

        scene->player.dir = get_player_orientation(scene->map.matrix, scene->player.coord_ini);
        
        scene->map.size_wall = get_size_wall(scene->map.width_map, scene->map.height_map);
        
        scene->player.pos = get_player_position(scene->player.coord_ini, scene->map.size_wall);

        scene->player.speed = scene->map.size_wall * 0.01f;

        //print_scene(scene);

        printf("------------------------------------\n");

        /*create_ray(scene, 0, 0);
        create_ray(scene, 1920, 0);
        create_ray(scene, 0, 1080);

        create_ray(scene, 1920, 1080);*/

        init_window(mlib, scene, sprites);

        ft_free_tabs(copy);
        ft_free_tabs(scene->map.matrix);
    }

    /*SCOPE FX*/
    {

    }


    return 0;
}

