/* ******************************************* */
/*                                             */
/*                     ::|:||:||::|:|:|||:|||| */
/* icr.c               :|:|::|::||:|:::|::::|| */
/*                     :::|||::||||||::::::|:| */
/*                                             */
/*                                             */
/* C20201111080317 |:::||                      */
/* U20201111143910 :|:|:|                      */
/*                                             */
/* ******************************************* */

#include "header.h"

int							hex_equal(t_yy *bottom, t_yy *compare, int size)
{
	if ((!size) || (bottom == compare))
		return (1);
	if (bottom->val == -1)
		return (0);
	if (bottom->val == compare->val)
		return (hex_equal(bottom->nx, compare->nx, --size));
	else
		return (0);
}

int							is_repeated(t_yy *bottom, t_yy *head)
{
//	printf("repeated? %d\n", hex_distance(head, bottom));
//	print_yy_group(bottom, 6);
//	print_yy_group(head, 6);
	if (bottom == head)
		return (0);
	if (hex_equal(bottom, head, 6))
		return (1);
	return (is_repeated(bottom->nx, head));
}

void						flip(t_yy *head)
{
	head->flipped = 1;
	head->val = head->val == 0 ? 1 : 0;
}

int							best_match(t_yy *ref, t_yy *head, int size)
{
	int						i;
	t_yy					*ref_p;
	t_yy					*head_p;
	int						out;

	//printf("best size %d\n", size);
	if (!size)
		return (ref->val);
	i = 0;
	while (i + size < 6)
	{
		//printf("i = %d\n", i);
		ref_p = head_forward(ref, i);
		head_p = head_back(head, size);
		//print_yy_group(ref_p, 6 - i);
		//print_yy_group(head_p, size);
		if(hex_equal(ref_p, head_p, size))
		{
			out = size == 6 ? ref_p->val : head_forward(ref_p, size)->val;
			//printf(" > %d\n", out);
			return (out);
		}
		i++;
	}
	return (best_match(ref, head, --size));
}

int							random_match(t_yy *ref, t_yy *head)
{
	(void) ref;
	(void) head;
	return (rand() % 2);
}

int deb = 10;
void						icr_solve(t_icr *icr, t_yy *head)
{
	const int				size_minus_one = 6 - 1;

	while (1)
	{
		//if (!deb--) return;
		//print_icr(icr);
		if (head->val == -1)
		{
			head->val = best_match(icr->bottom, head, size_minus_one);
			continue ;
		}
		if (is_repeated(icr->bottom, head_back(head, size_minus_one)))
		{
			//printf("repeated!\n");
			head = reset_to_last_unflipped(head);
			flip(head);
			continue ;
		}
		else
		{
			//printf("continue\n");
			if (head == head_forward(icr->bottom, size_minus_one))
				break ;
			head = head->nx;
			continue ;
		}
	}
	return ;
}

void						icr_solve_recursive_stack_overflow(t_icr *icr, t_yy *head)
{
	const int				size_minus_one = 6 - 1;
	//print_icr(icr);
//	if (!deb--) return;
	if (head->val == -1)
	{
		head->val = best_match(icr->bottom, head, size_minus_one);
		return (icr_solve(icr, head));
	}
	if (is_repeated(icr->bottom, head_back(head, size_minus_one)))
	{
		//printf("repeated!\n");
		head = reset_to_last_unflipped(head);
		flip(head);
		return (icr_solve(icr, head));
	}
	else
	{
		//printf("continue\n");
		if (head == head_forward(icr->bottom, size_minus_one))
			return ;
		return (icr_solve(icr, head->nx));
	}
}

int							main(int argc, char *argv[])
{
	t_icr					*icr;
	int						ref[6] = {1, 0, 0, 0, 0, 1};

	icr = icr_build(ref);
	icr_solve(icr, head_forward(icr->bottom, 6));

	print_title();
	printf("123456789_123456789_123456789_123456789_123456789_123456789_1234\n");
	print_icr(icr);
	icr_destroy(icr);
	return (0);
}
