
#include "../header.h"

int read_rt_file(const char *filename, t_scene *scene)
{
    int fd;
    char *line = NULL;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return -1;
    while ((line = get_next_line(fd)) != NULL)
    {
        parse_line(scene, line);
    }
    close(fd);
    if (line)
        free(line);
    return 0;
}

/* Renvoie le nombre de ligne du fichier a parser */
int get_size_file(const char *filename)
{
    int     fd;
    char    *line = NULL;
    int     size_file;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return -1;
    size_file = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        size_file++;
        free(line);
    }
    close(fd);
    if (line)
        free(line);
    return (size_file);
}

/* Copie le fichier a parser dans un tableau 2D de char */
char **copy_file(const char *filename, int size_file)
{
    int     fd;
    char    *line = NULL;
    char    **copy;
    int     i;

    copy = (char **) malloc(sizeof(char *) * (size_file + 1));
    if (copy == NULL)
        return (NULL);

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (NULL);
    i = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        copy[i] = line;
        i++;
    }
    copy[i] = NULL;
    close(fd);
    if (line)
        free(line);
    return (copy);
}

int main(int argc, char const *argv[])
{
    (void) argc;
    (void) argv;

    /* SCOPE TESTS VICTOR */
    {
        char **copy;
        t_scene *scene;
        char const *filename;
        int end;

        filename = "map1.cub";
        int size_file;
        size_file = get_size_file(filename);       
        scene = malloc(sizeof(t_scene));
        copy = copy_file (filename, size_file);
        
        int i = 0;

        while (copy[i])
        {
            if (parse_line(scene, copy[i++]))
                end = i;  
        }
        
        printf("%s\n", scene->sprite.north);
        printf("%s\n", scene->sprite.south);
        printf("%s\n", scene->sprite.west);
        printf("%s\n", scene->sprite.east);
        printf("F %f,%f,%f\n", scene->floor_color.x, scene->floor_color.y, scene->floor_color.z);
        printf("C %f,%f,%f\n", scene->sky_color.x, scene->sky_color.y, scene->sky_color.z);
    }


    /* SCOPE TESTS FX */
    /*{
        char const *filename;
        filename = "map1.cub";

        int size_file;
        size_file = get_size_file(filename);
        printf("size_file : %d\n", size_file);

        char **copy;
        copy = copy_file (filename, size_file);

        print_tab(copy);

        int ind_map;
        ind_map = find_map(copy);
        printf("ind_map = %d\n", ind_map);

        ind_map = 10;

        int h_map;
        h_map = height_map(copy, ind_map);
        printf("Size of map : %d\n", h_map);

        char **map_uncompleted;
        map_uncompleted = map_creator(copy, h_map, ind_map);

        print_tab(map_uncompleted);

        int largest_line;
        largest_line = find_largest_line(map_uncompleted);
        printf("largest line = %d\n", largest_line);


        int caract_ok;
        caract_ok = check_caract_map(map_uncompleted);
        printf("caract_ok = %d\n", caract_ok);


        //line_matrix_creator(map_uncompleted[0], largest_line);




        

        
        printf("-----------------------------\n");


        (void) map_uncompleted;
        
        
        t_scene *scene;
        scene = malloc(sizeof(t_scene));
        scene->map.map = map_uncompleted;

        display_map(scene);

        printf("check first last one = %d\n", check_last_first_one(map_uncompleted));
        
        

    }*/

    return 0;
}

