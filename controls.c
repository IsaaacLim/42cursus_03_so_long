#include "so_long.h"

int	ft_ternary(int yes, int i, int j)
{
	if (yes)
		return (i);
	else
		return (j);
}


void	ft_cover_trails(t_data *vars, struct s_img *chr)
{
	int mtx_x;
	int mtx_y;

	mlx_put_image_to_window(vars->mlx, vars->win, vars->bg.ptr, chr->mask_x1, chr->mask_y1); // Prev Top left
	mlx_put_image_to_window(vars->mlx, vars->win, vars->bg.ptr, chr->mask_x2, chr->mask_y1); // Prev Top right
	mlx_put_image_to_window(vars->mlx, vars->win, vars->bg.ptr, chr->mask_x1, chr->mask_y2); // Prev Bottom left
	if (chr->mask_bot_right)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->bg.ptr, chr->mask_x2, chr->mask_y2); // Prev Bottom right
	
	mtx_x = chr->x / chr->wth;
	mtx_y = chr->y / chr->hgt;
	chr->mask_bot_right = true;
	chr->mask_x1 = mtx_x * vars->bg.wth; // New x_coord rounded down (for right movement)
	/*
	** for left movement, if new x_coord rounded down + 1 != wall, cover up right side
	*/
	chr->mask_x2 = ft_ternary(vars->matrix[mtx_y][mtx_x + 1] != '1', (mtx_x + 1) * vars->bg.wth, chr->mask_x1);
	chr->mask_y1 = mtx_y * vars->bg.hgt; // New y_coord rounded down (for down movement)
	/*
	** for up movement, if new y_coord rounded down + 1 != wall, cover up bottom
	*/
	chr->mask_y2 = ft_ternary(vars->matrix[mtx_y + 1][mtx_x] != '1', (mtx_y + 1) * vars->bg.hgt, chr->mask_y1);
	if (vars->matrix[mtx_y + 1][mtx_x + 1] == '1') // for Bottom right masking
		chr->mask_bot_right = false;
}

void	ft_character(t_data *vars)
{
	ft_cover_trails(vars, &vars->pc);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->pc.ptr, vars->pc.x, vars->pc.y);
}


/*
** Hooking intercepts functions calls, messages ot events
** keycode follows ASCII [prtinf("%d", keycode) for more]
*/
int		ft_wasd(int keycode, t_data *vars)
{
	int x;
	int y;
	int x_rnd_up;
	int y_rnd_up;

	x = vars->pc.x / vars->pc.wth;
	x_rnd_up = ft_ternary((vars->pc.x % vars->pc.wth) == 0, x, x + 1);
	y = vars->pc.y / vars->pc.hgt;
	y_rnd_up = ft_ternary((vars->pc.y % vars->pc.hgt) == 0, y, y + 1);

	ft_printf("key_hook: %d", keycode);
	if (keycode == 65307)
		ft_close_window(vars);
	/*
	** 1. Check if prev y_coord is already at top wall //can remove this
	** 2. Check if new y_coord (ROUNDED DOWN) will hit a border with:
	**		PREV x_coord (rounded down) else PREV x_coord (rounded up)
	*/
	if (keycode == 119)//&& vars->pc.y > 0 + vars->wl.hgt) //w
	{
		vars->pc.y -= 8;
		if (vars->matrix[vars->pc.y / vars->pc.hgt][x] == '1')
			vars->pc.y += 8;
		else if (vars->matrix[vars->pc.y / vars->pc.hgt][x_rnd_up] == '1')
			vars->pc.y += 8;
		y = vars->pc.y / vars->pc.hgt; //just for logging
	}
	if (keycode == 97 && vars->pc.x > 0 + vars->wl.wth) //a
	{
		vars->pc.x -= 8;
		if (vars->matrix[y][vars->pc.x / vars->pc.wth] == '1')
			vars->pc.x += 8;
		else if (vars->matrix[y_rnd_up][vars->pc.x / vars->pc.wth] == '1')
			vars->pc.x += 8;
		x = vars->pc.x / vars->pc.wth; // just for logging
	}
	/*
	** 1. Check if prev y_coord is already at bottom wall //can remove this
	** 2. Check if new y_coord (ROUNDED UP) will hit a border with:
	**		prev x_coord (rounded down) else prev x_coord (rounded up)
	*/
	if (keycode == 115 && vars->pc.y < (vars->win_hgt - vars->wl.hgt - vars->pc.hgt)) //s
	{
		vars->pc.y += 8;
		y = vars->pc.y / vars->pc.hgt;
		y_rnd_up = ft_ternary((vars->pc.y % vars->pc.hgt) == 0, y, y + 1);
		if (vars->matrix[y_rnd_up][x] == '1')
			vars->pc.y -= 8;
		else if (vars->matrix[y_rnd_up][x_rnd_up] == '1')
			vars->pc.y -= 8;

	}
	if (keycode == 100 && vars->pc.x < (vars->win_wth - vars->wl.wth - vars->pc.wth)) //d
	{
		vars->pc.x += 8;
		x = vars->pc.x / vars->pc.wth;
		x_rnd_up = ft_ternary((vars->pc.x % vars->pc.wth) == 0, x, x + 1);
		if (vars->matrix[y][x_rnd_up] == '1')
			vars->pc.x -= 8;
		else if (vars->matrix[y_rnd_up][x_rnd_up] == '1')
			vars->pc.x -= 8;

	}
	ft_printf("\tkey: %c pc.x:%d pc.y:%d x:%d y:%d\n", keycode, vars->pc.x, vars->pc.y, x, y);
	ft_character(vars);
	return (0);
}

int		ft_mouse(int button, int x, int y, t_data *vars)
{
	// int x;
	// int y;
	mlx_mouse_get_pos(vars->mlx, vars->win, &x, &y);
	ft_printf("pos:%d %d %d \n", button, x, y);
	//if (button == 1 && (x >= 593 && x <= 640) && (y >= -30 && y <= 0)) // 'X' postition
	if (button == 1 && (x >= 593 && x <= 640) && (y >= 20 && y <= 40)) // one block below 'X'
		ft_close_window(vars); //won't leak
	return (0);
}

int		ft_redcross(int keycode, t_data *vars)
{
	ft_printf("\nButton Keycode: %d\n", keycode);
	//ft_close_window(vars); //seg fault with leaks
	//exit (0); // no seg fault but leaking
}

int		ft_control(t_data *vars)
{
	vars->pc.x *= vars->pc.wth;
	vars->pc.y *= vars->pc.hgt;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->pc.ptr, vars->pc.x , vars->pc.y);
	mlx_hook(vars->win, 2, 1L<<0, ft_wasd, vars); //similar to mlx_key_hook(vars->win, ft_wasd, vars) but now can hold;
	mlx_hook(vars->win, 17, 1L<<2, ft_redcross, vars);
	//mlx_mouse_hook(vars->win, ft_mouse, vars);
}