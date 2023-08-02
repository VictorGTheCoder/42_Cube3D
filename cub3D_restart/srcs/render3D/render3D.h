#ifndef RENDER3D
# define RENDER3D

#include "../../header.h"

/* render3D/ray_caster.c */
t_vec	calculate_rays(t_general *general, int x0, int y0, int x1, int y1, int size_wall, int window_width, int window_height);
void	trace_ray(t_general *general);
int 	render_game(t_general *general);

/* render3D/3D_wall_render.c */
void	draw_3D_line_west(t_general *general, t_vec ray, int wall_height, int imageincre);
void	draw_3D_line_east(t_general *general, t_vec ray, int wall_height, int imageincre);
void	draw_3D_line_south(t_general *general, t_vec ray, int wall_height, int imageincre);
void	draw_3D_line_north(t_general *general, t_vec ray, int wall_height, int imageincre);
void 	draw_3D_line_color(t_general *general, t_vec ray, int wall_height, int imageincre, unsigned int color);


/* render3D/3D_wall_render_near.c */
void	draw_3D_line_south_near(t_general *general, t_vec ray, int imageincre, float dist);
void	draw_3D_line_north_near(t_general *general, t_vec ray, int imageincre, float dist);
void	draw_3D_line_west_near(t_general *general, t_vec ray, int imageincre, float dist);
void	draw_3D_line_east_near(t_general *general, t_vec ray, int imageincre, float dist);

/* render3D/get_color.c */
int		get_color_wall_south(t_general *general, float x, int h_wall, int max_wall_h);
int		get_color_wall_north(t_general *general, float x, int h_wall, int max_wall_h);
int		get_color_wall_west(t_general *general, float x, int h_wall, int max_wall_h);
int		get_color_wall_east(t_general *general, float x, int h_wall, int max_wall_h);

/* render3D/get_color_near.c */
int		get_color_wall_south_near(t_general *general, int x, int h_wall, float dist);
int		get_color_wall_north_near(t_general *general, int x, int h_wall, float dist);
int		get_color_wall_west_near(t_general *general, int x, int h_wall, float dist);
int		get_color_wall_east_near(t_general *general, int x, int h_wall, float dist);


#endif