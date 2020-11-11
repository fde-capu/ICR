/* ******************************************* */
/*                                             */
/*                     ::|:||:||::|:|:|||:|||| */
/* prints.c            :|:|::|::||:|:::|::::|| */
/*                     :::|||::||||||::::::|:| */
/*                                             */
/*                                             */
/* C20201111112448 |:|::|                      */
/* U20201111141047 |::|||                      */
/*                                             */
/* ******************************************* */

#include "header.h"

void						print_yy_group(t_yy *yy, int size)
{
	while (size--)
	{
		print_yy(yy);
		yy = yy->nx;
	}
	printf("\n");
	return ;
}

void						print_yy(t_yy *yy)
{
	printf("%d", yy->val);
	//printf("%02ld %p fix: %d\tflip: %d\tval: %d\n", 64 - (last - head), head, head->fixed, head->flipped, head->val);
	return ;
}

void						print_icr(t_icr *icr)
{
	t_yy					*last;
	t_yy					*head;

	last = icr->bottom->pv;
	head = icr->bottom;
	while (1)
	{
		if (head->val != -1)
			printf("%d", head->val);
		else
			printf("_");
		if (head == last)
			break;
		head = head->nx;
	}
	printf("\n");
	return ;
}

void						print_title(void)
{
	printf("I Ching Ring\n");
	return ;
}
