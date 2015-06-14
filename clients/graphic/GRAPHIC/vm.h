/*
** vm.h for vm in /home/thibaud/rendu/Corewar/vm
** 
** Made by thibaud
** Login   <thibaud@epitech.net>
** 
** Started on  Thu Mar 20 17:43:52 2014 Thibaut Lopez
** Last update Thu Jun 11 11:49:57 2015 Thibaut Lopez
*/

#ifndef VM_H
#define VM_H

#include <sys/stat.h>
#include <SDL/SDL.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "SDL/SDL_ttf.h"
#include "op.h"

#define ER_COR	" is not a corewar executable.\n"
#define ER_SIZE	" take to much memory to be launched.\n"
#define ER_POS1	"Error : the position "
#define	ER_POS2	"  is already taken by the file "
#define ER_POS3	".\n"
#define	ER_FULL "Can't find place to another champ: places already taken.\n"
#define ER_VOID	"You haven't gave a single correct champion.\n"
#define MAIN_BG "graphic/BackGround.bmp"
#define MAIN_TF "graphic/varsity_regular.ttf"

typedef struct	s_sdl
{
  SDL_Surface	*screen;
  SDL_Surface	*arena;
  SDL_Surface	*bg;
  SDL_Surface	*name[4];
  SDL_Surface	*ctd[2];
  SDL_Rect	ctd_pos;
  SDL_Surface	*cycle[2];
  SDL_Rect	cycle_pos;
  SDL_Surface	*c_done[2];
  SDL_Rect	c_done_pos;
  SDL_Surface	*dump[2];
  TTF_Font	*font;
}		t_sdl;

typedef struct		s_champ
{
  header_t		*head;
  char			*path;
  int			fd;
  int			champ_nb;
  int			pc;
  int			reg[REG_NUMBER];
  int			carry;
  int			wait;
  char			*graphic_name;
  Uint32		color;
  struct s_champ	*next;
  struct s_champ	*prev;
}			t_champ;

typedef struct	s_cor
{
  t_champ	*champ;
  unsigned char	*mem;
  int		dump;
  int		live_done;
  int		cycle;
  int		cycle_to_die;
  int		endian;
  int		live[4];
  int		champs_nb[4];
  int		nb_chmps_alive;
  t_sdl		graphic;
}		t_cor;

typedef struct	s_struct
{
  char		mnemonique;
  void		(* ptr_fct)(t_champ *, t_cor *);
  int		wait;
}		t_struct;

t_struct	ptr_fct[23];

t_champ	*init_champ();
int	move_in_list(t_champ **champ, int nbr);
int	check_champ(t_champ **champ, char *path, int addr, int endian);
int	my_list_len(t_champ *champ);
void	init_adress(t_champ *champ);
int	fill_mem(unsigned char **mem, t_champ *champ);
int	get_nbr_action(unsigned char *mem, int pc, int len);
int	**get_encode(unsigned char *mem, int pc);
void	sfree(char **str);

int	someone_is_dead(t_champ *, t_cor *);
int	run_corewar(t_champ *, t_cor *);
t_champ *del_chmp(t_champ *, int);
int	get_wait(t_champ *, t_cor *);
int	champ_play(t_champ *, t_cor *);
int	find_in_tab(char);
int	end_game(t_champ *, t_cor *);

void	my_live(t_champ *champ, t_cor *cor);
void	my_ld(t_champ *champ, t_cor *cor);
void	my_st(t_champ *champ, t_cor *cor);
void	my_add(t_champ *champ, t_cor *cor);
void	my_sub(t_champ *champ, t_cor *cor);
void	my_and(t_champ *champ, t_cor *cor);
void	my_or(t_champ *champ, t_cor *cor);
void	my_xor(t_champ *champ, t_cor *cor);
void	my_zjmp(t_champ *champ, t_cor *cor);
void	my_ldi(t_champ *champ, t_cor *cor);
void	my_sti(t_champ *champ, t_cor *cor);
void	my_fork(t_champ *champ, t_cor *cor);
void	my_lld(t_champ *champ, t_cor *cor);
void	my_lldi(t_champ *champ, t_cor *cor);
void	my_lfork(t_champ *champ, t_cor *cor);
void	my_aff(t_champ *champ, t_cor *cor);
void	my_none(t_champ *champ, t_cor *cor);
int	get_all_type_arg(int *tab, t_champ *champ
			 , unsigned char *mem, int *err);
int	get_dir_ind_arg(int *tab, t_champ *champ, unsigned char *mem, int *err);
int	get_dir_reg_arg(int *tab, t_champ *champ, unsigned char *mem, int *err);
int	get_dir_ind_arg_noidx(int *tab, t_champ *champ,
			      unsigned char *mem, int *err);
int	get_all_type_arg_noidx(int *tab, t_champ *champ,
			       unsigned char *mem, int *err);

int	init_graphic(t_sdl *cor, t_champ *champ, int dump);
void	free_graphic(t_sdl *cor);
int	get_escape(t_cor *cor);
void	init_information(t_sdl *cor);
void	change_case_mem(int case_mem, Uint32 color, t_sdl *cor);
int	aff_mem(unsigned char *mem);
int	print_encode(int **tab);
int	check_reg(int);
void	print_on_mem(t_cor *cor, int to_add, int pc);
int	cycle_run(t_champ *champs, t_cor *map, int cycle_done);
int	someone_is_dead(t_champ *champs, t_cor *map);
int	end_game(t_champ *champ, t_cor *map);

void	rm_empty_champ(t_champ **tmp, t_champ **first, t_cor *cor);
void	epur_champ(t_cor *cor, t_champ **first);
t_champ	*del_chmp(t_champ *champs, int champ_del);
int	kill_champ(t_champ **champs, t_cor *map);
int	mod_mem(int nb);
void	cor_mem_set(unsigned char *mem, int len);
int	prog_size_error(char *path);
void    fmode(void);
void	refresh_ctd(t_cor *cor);
void	refresh_cycle(t_cor *cor, int cycle_done);
void	put_dump(t_sdl *cor, int dump);

#endif
