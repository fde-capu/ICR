/* ******************************************* */
/*                                             */
/*                     ::|:||:||::|:|:|||:|||| */
/* prints.c            :::||:||:|::||::|:||::: */
/*                     :::|||::||||||::::::|:| */
/*                                             */
/*                                             */
/* C20201111112448 |:|::|                      */
/* U20201112121747 :::||:                      */
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
	return ;
}

void						print_icr(t_icr *icr)
{
	t_yy					*last;
	t_yy					*head;

	print_ruler();
	last = icr->bottom->pv;
	head = icr->bottom;
	while (1)
	{
		if (head->val != -1)
			printf("%d", head->val);
		else
			printf("_");
		if (head == last)
			break ;
		head = head->nx;
	}
	printf("\n");
	return ;
}

void						print_title(void)
{
	printf("\nI Ching Ring\nby fde-capu\n\n");
	return ;
}

void						print_ruler(void)
{
	printf("123456789_123456789_123456789_123456789_123456789_123456789");
	printf("_1234\n");
	return ;
}

void						print_help(void)
{
	printf("Usage: `./icr.a hexagram`; ");
	printf("where 'hexagram' is a six-digit binary notation ");
	printf("from `000000` to `111111`.\n");
	return ;
}
