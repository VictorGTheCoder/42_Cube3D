#include "render3D.h"


t_coord findv1(t_coord c0, t_coord c1, t_coord v2)
{
	t_coord result;
	int dx = c1.x - c0.x;
	int dy = c1.y - c0.y;

	if (abs(dx) >= abs(dy))
	{
		result.y = v2.y;
		if (dx > 0)
			result.x = v2.x + 1;
		else
			result.x = v2.x - 1;
	}
	else
	{
		result.x = v2.x;
		if (dy > 0)
			result.y = v2.y + 1;
		else
			result.y = v2.y - 1;

	}

	return result;
}
t_tab DDA_boosted( t_coord c0, t_coord c1)
{
	int		dx;
	int		dy;
	float	slope;
	t_tab	result;
	t_vec	pos;
	int adv_x;
	int adv_y;

	dx = c1.x - c0.x;
	dy = c1.y - c0.y;
	if (dx == 0)
		slope = 1;
	else
		slope = (float) (dy) / (dx);
	pos.x = c0.x;
	pos.y = c0.y;

	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
 
    // calculate increment in x & y for each steps
	if (steps == 0)
		printf("PROBELE EEMEFE\n");
    float Xinc = (float) dx / (float)steps;
    float Yinc = (float) dy / (float)steps;

    //printf("(%f, %f)\n", pos.x, pos.y);
    while(42)
	{
        usleep(50000);
		if (dx > 0)
        {
            if (pos.x > c1.x)
                break ;
			adv_x = SIZE_WALL - (int) pos.x % SIZE_WALL + pos.x - (int) pos.x ;
        }
		else
        {
            if (pos.x < c1.x)
                break ;
			adv_x = (int) - pos.x % SIZE_WALL - pos.x + (int) pos.x;
        }
		if (dy > 0)
        {
            if (pos.y > c1.y)
                break ;     
			adv_y = SIZE_WALL - (int) pos.y % SIZE_WALL;
        }
		else
        {
            if (pos.y < c1.y)
                break ;              
			adv_y = - (int) pos.y % SIZE_WALL;
        }
		if (adv_x == 0 && (int) pos.x % SIZE_WALL == 0)
        {
            if (dx > 0)
			    adv_x = SIZE_WALL;
            else
                adv_x = -SIZE_WALL;
        }
		if (adv_y == 0 && (int) pos.y % SIZE_WALL == 0)
        {
            if (dy > 0)
			    adv_y = SIZE_WALL;
            else
                adv_y = -SIZE_WALL;
        }

        printf("(%f, %f), adv (%d, %d) slope %f\n", pos.x, pos.y, adv_x, adv_y, slope);
		if (fabsf(adv_x * slope) < abs(adv_y))
		{
			pos.x = roundf(pos.x + adv_x);
			pos.y += (float) adv_x * slope;
		}
		else
		{
			pos.x += (float) adv_y / slope;
			pos.y = roundf(pos.y + adv_y);
		}

	}
        printf("(%f, %f), adv (%d, %d) slope %f\n", pos.x, pos.y, adv_x, adv_y, slope);

	result.v2.x = pos.x;
	result.v2.y = pos.y;
	result.v1 = findv1(c0, c1, result.v2);
	return (result);
}


int main(int argc, char const *argv[])
{
    t_general general;

    t_coord c0, c1;

    c0 = (t_coord) {0,0,0};
    c1 = (t_coord) {1000,200,0};
    
    printf("Front\n");
    DDA_boosted(c0, c1);
    printf("reverse\n");
    DDA_boosted(c1, c0);
    c0 = (t_coord) {0,500,0};
    c1 = (t_coord) {1000,200,0};

    printf("Front\n");
    DDA_boosted(c0, c1);
    printf("reverse\n");
    DDA_boosted(c1, c0);

    c0 = (t_coord) {1200,000,0};
    c1 = (t_coord) {1000,200,0};

    printf("Front\n");
    DDA_boosted(c0, c1);
    printf("reverse\n");
    DDA_boosted(c1, c0);

    return 0;
}