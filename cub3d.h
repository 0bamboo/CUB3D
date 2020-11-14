/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 16:34:56 by abdait-m          #+#    #+#             */
/*   Updated: 2020/11/14 11:19:32 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "./SRCs/get_next_line.h"
# include <stdlib.h>
# include <math.h>
# include "mlx.h"

# define K_L 0
# define K_R 2
# define K_B 1
# define K_F 13
# define R_R 124
# define R_L 123
# define ESC 53
# define M_S 0.09
# define R_S 0.04

typedef	struct				s_sv
{
	unsigned	char		*bmp;
	size_t					indx;
	size_t					size;
	int						save;
}							t_sv;

typedef	struct				s_tex
{
	void					*tex_n;
	void					*tex_s;
	void					*tex_e;
	void					*tex_w;
	void					*tex_sp;
	int						*n_data;
	int						*w_data;
	int						*s_data;
	int						*e_data;
	int						*sp_data;
	int						*buff_data;
	int						txh;
	int						txw;
	int						txx;
	int						txy;
	int						ppn;
	int						ppw;
	int						ppe;
	int						pps;
	int						ppsp;
	int						sln;
	int						slw;
	int						sle;
	int						sls;
	int						slsp;
	int						en;
	int						ew;
	int						ee;
	int						es;
	int						esp;
	int						rsl_nx;
	int						rsl_ny;
	int						rsl_sx;
	int						rsl_sy;
	int						rsl_wx;
	int						rsl_wy;
	int						rsl_ex;
	int						rsl_ey;
	int						rsl_spx;
	int						rsl_spy;
}							t_tex;

typedef	struct				s_pars
{
	int						flg_n;
	int						flg_e;
	int						flg_w;
	int						flg_s;
	int						flg_sp;
	int						flg_ceil;
	int						flg_floor;
	int						flg_resol;
	int						flr_r;
	int						flr_g;
	int						flr_b;
	int						ceil_r;
	int						ceil_g;
	int						ceil_b;
	char					*p_sp;
	char					*p_s;
	char					*p_n;
	char					*p_w;
	char					*p_e;
}							t_pars;

typedef	struct				s_pos
{
	int						drstartx;
	int						drendx;
	int						drstarty;
	int						drendy;
	int						line_h;
	int						hit;
	int						side;
	int						mapx;
	int						mapy;
	double					pwalldis;
	double					deltadis_x;
	double					deltadis_y;
	double					posx;
	double					posy;
	double					dirx;
	double					diry;
	double					wallx;
	double					siddisx;
	double					siddisy;
	double					planex;
	double					planey;
	double					cam_x;
	double					rdirx;
	double					rdiry;
	double					stepx;
	double					stepy;
	int						check;
}							t_pos;

typedef	struct				s_sprite
{
	double					z_buff[2560];
	double					sp_x[100];
	double					sp_y[100];
	int						nbr_sp;
	double					sp_dis[2560];
	int						sp_h;
	int						sp_w;
	double					spx;
	double					spy;
	int						spsx;
	int						sp_ord[100];
}							t_sp;

typedef	struct				s_cub
{
	t_sp					sp;
	t_sv					sv;
	t_tex					tx;
	t_pars					prs;
	t_pos					pos;
	int						x;
	int						y;
	int						z;
	void					*mlx_ptr;
	void					*win_ptr;
	void					*img_ptr;
	int						*data;
	int						ppx;
	int						s_line;
	int						endian;
	int						*sc;
	int						sh;
	int						sw;
	int						map_w;
	int						map_h;
	char					**map;
	char					tmp_c;
	int						k_f;
	int						k_b;
	int						k_l;
	int						k_r;
	int						r_r;
	int						r_l;
	int						d;
}							t_cub;

int							ft_store_the_img(t_cub *cub, char *name);
void						ft_rotation_the_player(t_cub *cub);
void						ft_bzero(void *s, size_t n);
char						*ft_substr(char const *s, unsigned int start,
size_t len);
char						*ft_strtrim(char const *s1, char const *set);
char						*ft_strrchr(const char *s, int c);
char						*ft_strnstr(const char *str, const char *to_find,
size_t len);
int							ft_strncmp(const char *s1,
const char *s2, size_t n);
size_t						ft_strlen(const char *s);
char						*ft_strjoin(char *s1, char *s2);
char						*ft_strdup(const char *s);
char						*ft_strchr(const char *s, int c);
char						**ft_split(char const *s, char c);
void						ft_putstr_fd(const char *str, int fd);
void						ft_putchar_fd(char c, int fd);
void						ft_put_sprite(t_cub *cub);
void						ft_calc_sprite_vars(t_cub *cub, double transfy);
void						ft_start_drawing_sp(t_cub *cub, double transfy);
void						ft_manage_order_sp(t_cub *cub);
void						ft_sort_sprite(t_cub *cub);
void						ft_swap_dis(int i, int j, t_cub *cub);
void						ft_swap_ord(int i, int j, t_cub *cub);
void						ft_go_left(t_cub *cub);
void						ft_go_right(t_cub *cub);
void						ft_go_forward(t_cub *cub);
void						ft_go_backward(t_cub *cub);
int							ft_north_tex(t_cub *cub);
int							ft_west_tex(t_cub *cub);
int							ft_east_tex(t_cub *cub);
int							ft_south_tex(t_cub *cub);
int							ft_sprite_tex(t_cub *cub);
char						*ft_put_char_1(int nbr);
int							ft_check_map_data(char c, int p, t_cub *cub);
int							ft_correct_map(t_cub *cub, int p);
int							ft_look_4_spaces(t_cub *cub, int x, int y);
int							ft_grab_colors_val(int fd, t_cub *cub);
int							ft_grab_colors(int fd, char buff[3], t_cub *cub);
int							ft_grab_rsl(int fd, t_cub *cub);
int							ft_check_rsl_flag(int fd, t_cub *cub);
int							ft_check_file(int fd, char buff[3], t_cub *cub);
int							ft_grab_flgs_data(int fd,
char tmp_c[3], t_cub *cub);
int							ft_start_end_ln(char *ln);
int							ft_check_map_again(t_cub *cub);
int							ft_check_ln_map(char *ln_map);
int							ft_map_struct(t_cub *cub,
char *m_buff);
int							ft_store_map(t_cub *cub, int fd,
char *m_buff, char *ln_map);
int							ft_start_parsing_the_map(int fd, t_cub *cub);
void						ft_init_vectors(char c, t_cub *cub);
int							ft_manage_key_press(int key, t_cub *cub);
int							ft_manage_key_release(int key, t_cub *cub);
void						ft_move_the_player(t_cub *cub);
int							ft_click_exit(void *cub);
int							ft_init_game(t_cub *cub);
int							ft_start_game(t_cub *cub);
void						ft_init_vars_to_draw(t_cub *cub, int x);
void						ft_start_dda(t_cub *cub);
int							ft_return_error(int er);
void						ft_set_p_direction(t_cub *cub);
void						ft_handle_sides(t_cub *cub, int side);
int							ft_return_biggest_nbr(int x, int y);
void						ft_tex_calc(t_cub *cub);
void						ft_handle_texs(t_cub *cub);
void						ft_start_drawing(int dr_s,
int dr_e, int x, t_cub *cub);
int							ft_start_parsing(int fd, t_cub *cub);
void						ft_init_vars(t_cub *cub);
int							ft_init_game(t_cub *cub);
int							ft_set_texs(t_cub *cub);
void						ft_rotate_right(double *old_dir_x,
double *old_plan_x, t_cub *cub);
void						ft_game_over(t_cub *cub);
void						ft_init_bmp(t_cub *cub);

#endif
