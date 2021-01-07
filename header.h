/* ******************************************* */
/*                                             */
/*                     ::|:||:||::|:|:|||:|||| */
/* header.h            :::||:||:|::||::|:||::: */
/*                     :::|||::||||||::::::|:| */
/*                                             */
/*                                             */
/* C20201111090720 |||::|                      */
/* U20201112120332 ::::|:                      */
/*                                             */
/* ******************************************* */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_yin_yang
{
	int						val;
	int						flipped;
	int						fixed;
	struct s_yin_yang		*nx;
	struct s_yin_yang		*pv;
}							t_yy;

typedef struct s_iching_ring
{
	t_yy					*yy[64];
	t_yy					*bottom;
}							t_icr;

typedef struct s_hexagram
{
	t_yy					yy[6];
}							t_hex;

int							best_match(t_yy *ref, t_yy *head, int size);
void						flip(t_yy *head);
t_yy						*head_back(t_yy *head, int amount);
t_yy						*head_forward(t_yy *head, int amount);
int							hex_distance(t_yy *top, t_yy *bottom);
int							hex_equal(t_yy *bottom, t_yy *compare, int size);
t_icr						*icr_build(int ref[6]);
void						icr_destroy(t_icr *icr);
void						icr_solve(t_icr *icr, t_yy *head);
int							is_repeated(t_yy *bottom, t_yy *head);
void						print_help(void);
void						print_icr(t_icr *icr);
void						print_ruler(void);
void						print_title(void);
void						print_yy(t_yy *yy);
void						print_yy_group(t_yy *yy, int size);
int							random_match(t_yy *ref, t_yy *head);
int							*ref_argument(char *argv);
t_yy						*reset_to_last_unflipped(t_yy *head);

#endif
