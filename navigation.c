/* ******************************************* */
/*                                             */
/*                     ::|:||:||::|:|:|||:|||| */
/* navigation.c        :|:|::|::||:|:::|::::|| */
/*                     :::|||::||||||::::::|:| */
/*                                             */
/*                                             */
/* C20201111113229 :::|:|                      */
/* U20201111141524 ::||::                      */
/*                                             */
/* ******************************************* */

#include "header.h"

t_yy						*reset_to_last_unflipped(t_yy *head)
{
	if (head->fixed)
		return (reset_to_last_unflipped(head_back(head, 1)));
	if (!head->flipped)
		return (head);
	head->flipped = 0;
	head->val = -1;
	return (reset_to_last_unflipped(head_back(head, 1)));
}

t_yy						*head_back(t_yy *head, int amount)
{
	if (!amount)
		return (head);
	return (head_back(head->pv, --amount));
}

t_yy						*head_forward(t_yy *head, int amount)
{
	if (!amount)
		return (head);
	return (head_forward(head->nx, --amount));
}

int							hex_distance(t_yy *top, t_yy *bottom)
{
	int						i;

	i = 0;
	while (bottom != top)
	{
		i++;
		bottom = bottom->nx;
	}
	return (i);
}
