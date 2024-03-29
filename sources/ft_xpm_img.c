#include "so_long.h"

/*
** Just to store image pointer
** Function split just because of norminette
** Sprites:
**	Utils - Background (bg), Wall (wl), Exit (ext), Step Count background (sc)
**	Contact - Enemies (en), Collectables (clt)
**	PC - Player Character Sprites (pc) 
**
** --- Commented out codes are for the project sharing session ---
** To show how it looks like when:
** 	- Player Character only has a single image (no sprite movement)
**	- Images wasn't photoshopped to have a background
** 	- Images have borders to reflect their 1:1 aspect ratio
*/

static void	ft_pc_sprites_1(t_data *v)
{
	char	*pc_0;
	char	*pc_w1;
	char	*pc_w2;
	char	*pc_s1;
	char	*pc_s2;

	pc_0 = "images/yoshi_0_bg.xpm";
	pc_w1 = "images/yoshi_b1_bg.xpm";
	pc_w2 = "images/yoshi_b2_bg.xpm";
	pc_s1 = "images/yoshi_f1_bg.xpm";
	pc_s2 = "images/yoshi_f2_bg.xpm";
		
	// pc_w1 = pc_0;
	// pc_w2 = pc_0;
	// pc_s1 = pc_0;
	// pc_s2 = pc_0;
	v->pc_0.ptr = v->xpm_img(v->mlx, pc_0, &v->pc_0.wth, &v->pc_0.hgt);
	v->pc_w1.ptr = v->xpm_img(v->mlx, pc_w1, &v->pc_w1.wth, &v->pc_w1.hgt);
	v->pc_w2.ptr = v->xpm_img(v->mlx, pc_w2, &v->pc_w2.wth, &v->pc_w2.hgt);
	v->pc_s1.ptr = v->xpm_img(v->mlx, pc_s1, &v->pc_s1.wth, &v->pc_s1.hgt);
	v->pc_s2.ptr = v->xpm_img(v->mlx, pc_s2, &v->pc_s2.wth, &v->pc_s2.hgt);
}

static void	ft_pc_sprites_2(t_data *v)
{
	char	*pc_a1;
	char	*pc_a2;
	char	*pc_d1;
	char	*pc_d2;

	pc_a1 = "images/yoshi_l1_bg.xpm";
	pc_a2 = "images/yoshi_l2_bg.xpm";
	pc_d1 = "images/yoshi_r1_bg.xpm";
	pc_d2 = "images/yoshi_r2_bg.xpm";

	// pc_a1 = "images/nobg_yoshi_0.xpm";
	// pc_a2 = pc_a1;
	// pc_d1 = pc_a1;
	// pc_d2 = pc_a1;
	v->pc_a1.ptr = v->xpm_img(v->mlx, pc_a1, &v->pc_a1.wth, &v->pc_a1.hgt);
	v->pc_a2.ptr = v->xpm_img(v->mlx, pc_a2, &v->pc_a2.wth, &v->pc_a2.hgt);
	v->pc_d1.ptr = v->xpm_img(v->mlx, pc_d1, &v->pc_d1.wth, &v->pc_d1.hgt);
	v->pc_d2.ptr = v->xpm_img(v->mlx, pc_d2, &v->pc_d2.wth, &v->pc_d2.hgt);
}

static void	ft_contact_sprites(t_data *v)
{
	char	*clt_0;
	char	*clt_1;
	char	*clt_2;
	char	*en_0;
	char	*en_1;

	clt_0 = "images/egg_green.xpm";
	clt_1 = "images/egg_blue.xpm";
	clt_2 = "images/egg_pink.xpm";
	// clt_2 = "images/nobg_egg_pink.xpm";
	en_0 = "images/bomb1.xpm";
	// en_0 = "images/box_grass.xpm"; //temp usage for trail cover
	en_1 = "images/bomb2.xpm";
	v->clt_0.ptr = v->xpm_img(v->mlx, clt_0, &v->clt_0.wth, &v->clt_0.hgt);
	v->clt_1.ptr = v->xpm_img(v->mlx, clt_1, &v->clt_1.wth, &v->clt_1.hgt);
	v->clt_2.ptr = v->xpm_img(v->mlx, clt_2, &v->clt_2.wth, &v->clt_2.hgt);
	v->en_0.ptr = v->xpm_img(v->mlx, en_0, &v->en_0.wth, &v->en_0.hgt);
	v->en_1.ptr = v->xpm_img(v->mlx, en_1, &v->en_1.wth, &v->en_1.hgt);
}

static void	ft_utils_sprites(t_data *v)
{
	char	*bg;
	char	*wl;
	char	*ext0;
	char	*ext1;
	char	*sc;

	// bg = "images/box_ground_tile.xpm";
	// wl = "images/box_wall.xpm";
	// ext0 = "images/box_door_close.xpm";

	bg = "images/ground_tile.xpm";
	wl = "images/wall.xpm";
	ext0 = "images/door_close.xpm";
	ext1 = "images/door_open.xpm";
	sc = "images/steps_bg.xpm";
	v->bg.ptr = v->xpm_img(v->mlx, bg, &v->bg.wth, &v->bg.hgt);
	v->wl.ptr = v->xpm_img(v->mlx, wl, &v->wl.wth, &v->wl.hgt);
	v->ext0.ptr = v->xpm_img(v->mlx, ext0, &v->ext0.wth, &v->ext0.hgt);
	v->ext1.ptr = v->xpm_img(v->mlx, ext1, &v->ext1.wth, &v->ext1.hgt);
	v->sc.ptr = v->xpm_img(v->mlx, sc, &v->sc.wth, &v->sc.hgt);
}

void	ft_xpm_img(t_data *v)
{
	ft_utils_sprites(v);
	ft_contact_sprites(v);
	ft_pc_sprites_1(v);
	ft_pc_sprites_2(v);
}
