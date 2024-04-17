# include "so_long.h"

int get_xpm_to_img(t_data *data, char **s, char *texture, t_img *txt)
{
    txt->img = mlx_xpm_file_to_image(data->mlx_ptr, texture, &txt->width, &txt->height);
    if (!txt->img)
        return (ret_free_txt("Error\nmlx_xpm_to_image failed.", s, data));
    txt->addr = mlx_get_data_addr(txt->img, &txt->bpp,
                                   &txt->line, &txt->endian);
    if (!txt->addr)
        return (ret_free_txt("Error\nmlx_get_data_addr failed.", s, data));
    txt->status = 1;
    //mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, txt->img, 0, 0);

    return (SUCCESS);
}

int reduce_create_textures_wall(t_data *data, char *s)
{
    if (ft_strncmp(s, "0", 1) == 0)
    {
        if (get_xpm_to_img(data, &s, "./sprites/grass.xpm",
                           &data->floor_texture) == FAILURE)
            return (FAILURE);
    }
    if (ft_strncmp(s, "1", 1) == 0)
    {
        if (get_xpm_to_img(data, &s, "./sprites/wallhd.xpm",
                           &data->walls_texture) == FAILURE)
            return (FAILURE);
    }
    return (SUCCESS);
}

int create_textures_wall(t_data *data)
{
    int i;
    int j;

    i = -1;
    while (data->map->map[++i])
    {
        j = -1;
        while (data->map->map[i][++j])
        {
            if (ft_strncmp(&data->map->map[i][j], "0", 1) == 0)
                reduce_create_textures_wall(data, "0");
            if (ft_strncmp(&data->map->map[i][j], "1", 1) == 0)
                reduce_create_textures_wall(data, "1");
        }
    }
    return (SUCCESS);
}
