#ifndef HEADER_H
# define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct	s_utils 
{
	void	*mlx;
	void	*win;
} t_utils;

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_data;

typedef struct	s_mlib 
{
	t_data	data;
	t_utils	utils;
} t_mlib;

typedef struct s_vec 
{
	float x;
	float y;
	float z;
} t_vec;

typedef struct s_player 
{
	t_vec	pos;
	t_vec	dir;
	float	speed;
} t_player;

typedef struct s_sprite 
{
	char const *north;
	char const *south;
	char const *east;
	char const *west;

	char const *bonus;
} t_sprite;

typedef struct s_scene 
{
	char	**map;
	int		sky_color;
	int		floor_color;

	t_sprite	sprite;
	t_player	player;
	
} t_scene;

#endif