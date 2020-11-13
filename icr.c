/* ******************************************* */
/*                                             */
/*                     ::|:||:||::|:|:|||:|||| */
/* icr.c               :::||:||:|::||::|:||::: */
/*                     :::|||::||||||::::::|:| */
/*                                             */
/*                                             */
/* C20201111080317 |:::||                      */
/* U20201112122207 :|:|:|                      */
/*                                             */
/* ******************************************* */

#include "header.h"

int							best_match(t_yy *ref, t_yy *head, int size)
{
	int						i;
	t_yy					*ref_p;
	t_yy					*head_p;

	if (!size)
		return (ref->val);
	i = 0;
	while (i + size < 6)
	{
		ref_p = head_forward(ref, i);
		head_p = head_back(head, size);
		if (hex_equal(ref_p, head_p, size))
			return (size == 6 ? ref_p->val : head_forward(ref_p, size)->val);
		i++;
	}
	return (best_match(ref, head, --size));
}

void						icr_solve(t_icr *icr, t_yy *head)
{
	const int				size_minus_one = 6 - 1;

	while (1)
	{
		if (head->val == -1)
		{
			head->val = best_match(icr->bottom, head, size_minus_one);
			continue ;
		}
		if (is_repeated(icr->bottom, head_back(head, size_minus_one)))
		{
			head = reset_to_last_unflipped(head);
			flip(head);
			continue ;
		}
		else
		{
			if (head == head_forward(icr->bottom, size_minus_one))
				break ;
			head = head->nx;
			continue ;
		}
	}
	return ;
}

int							main(int argc, char **argv)
{
	t_icr					*icr;
	int						*ref;

	print_title();
	if (argc == 1)
	{
		print_help();
		return (1);
	}
	ref = ref_argument(argv[1]);
	icr = icr_build(ref);
	icr_solve(icr, head_forward(icr->bottom, 6));
	print_icr(icr);
	icr_destroy(icr);
	free(ref);
	return (0);
}
