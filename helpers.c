/* ******************************************* */
/*                                             */
/*                     :|||:|||::||||:|:|||||| */
/* helpers.c           :::||:||:|::||::|:||::: */
/*                     :|:|:|:::|::|::::::|||: */
/*                                             */
/*                                             */
/* C20201112115152 ::::|:                      */
/* U20201112115222 ||::||                      */
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
