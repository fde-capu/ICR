/* ******************************************* */
/*                                             */
/*                     ::|:||:||::|:|:|||:|||| */
/* builds.c            :|:|::|::||:|:::|::::|| */
/*                     :::|||::||||||::::::|:| */
/*                                             */
/*                                             */
/* C20201111112800 ::::::                      */
/* U20201111135539 ::||::                      */
/*                                             */
/* ******************************************* */

#include "header.h"

t_icr						*icr_build(int ref[6])
{
	t_icr					*icr;
	int						i;
	int						p;

	icr = malloc(sizeof(t_icr));
	i = 0;
	while (i < 64)
	{
		icr->yy[i] = malloc(sizeof(t_yy));
		icr->yy[i]->val = i < 6 ? ref[i] : -1;
		icr->yy[i]->flipped = i < 6 ? 1 : 0;
		icr->yy[i]->fixed = i < 6 ? 1 : 0;
		i++;
	}
	i = 0;
	while (i < 64)
	{
		p = i - 1 == -1 ? 63 : i - 1;
		icr->yy[i]->pv = icr->yy[p];
		p = i + 1 == 64 ? 0 : i + 1;
		icr->yy[i]->nx = icr->yy[p];
		i++;
	}
	icr->bottom = icr->yy[0];
	return (icr);
}

void						icr_destroy(t_icr *icr)
{
	int						i;

	i = 0;
	while (i < 64)
	{
		free(icr->yy[i]);
		i++;
	}
	free(icr);
	return ;
}
