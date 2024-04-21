# include "so_long.h"

int	ft_count_items(char **tab)
{
	int	i;
	int	j;
	int	items;

	i = 0;
	j = 0;
	items = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'C')
				items += 1;
			j++;
		}
		i++;
	}
	return (items);
}

t_vector	ft_player_pos(char **tab)
{
	int			i;
	int			j;
	t_vector	player_pos;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'P')
			{
				player_pos.x = j;
				player_pos.y = i;
			}
			j++;
		}
		i++;
	}
	return (player_pos);
}