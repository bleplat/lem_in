#include "li.h"

void			li_print_singleround_result(t_li_board *brd)
{
	int		i_mouse;

	i_mouse = 1;
	while (i_mouse <= brd->ants_count)
	{
		if (i_mouse != 1)
			ft_putchar(' ');
		ft_putstr("L");
		ft_putnbr(i_mouse);
		ft_putstr("-");
		ft_putstr(brd->rooms[1].name);
		i_mouse++;
	}
}
