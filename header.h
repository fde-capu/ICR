/* ******************************************* */
/*                                             */
/*                     ::|:||:||::|:|:|||:|||| */
/* header.h            :|:|::|::||:|:::|::::|| */
/*                     :::|||::||||||::::::|:| */
/*                                             */
/*                                             */
/* C20201111090720 |||::|                      */
/* U20201111143647 ::||::                      */
/*                                             */
/* ******************************************* */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <stdio.h>

typedef struct				s_yin_yang
{
	int						val;
	int 					flipped;
	int 					fixed;
	struct s_yin_yang		*nx;
	struct s_yin_yang		*pv;
}							t_yy;

typedef struct				s_iching_ring
{
	t_yy					*yy[64];
	t_yy					*bottom;
}							t_icr;

typedef struct				s_hexagram
{
	t_yy					yy[6];
}							t_hex;

t_yy						*reset_to_last_unflipped(t_yy *head);
t_yy						*head_back(t_yy *head, int amount);
t_icr						*icr_build(int ref[6]);
void						icr_destroy(t_icr *icr);
void						print_yy(t_yy *yy);
void						print_icr(t_icr *icr);
int							hex_distance(t_yy *top, t_yy *bottom);
int							hex_equal(t_yy *bottom, t_yy *compare, int size);
int							is_repeated(t_yy *bottom, t_yy *head);
void						flip(t_yy *head);
void						icr_solve(t_icr *icr, t_yy *head);
void						icr_solve_recursive_stack_overflow(t_icr *icr, t_yy *head);
int							main(void);
int							best_match(t_yy *ref, t_yy *head, int size);
void						print_title(void);
void						print_yy_group(t_yy *yy, int size);
t_yy						*head_forward(t_yy *head, int amount);
int							random_match(t_yy *ref, t_yy *head);

#endif
