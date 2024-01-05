/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:35:32 by llai              #+#    #+#             */
/*   Updated: 2024/01/05 20:49:51 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/libft.h"
#include <stdbool.h>

// Checking the boundaries
bool    is_safe(int i, int j, int rows, int cols)
{
    if (i >= 0 && i < rows && j >= 0 && j < cols)
        return (true);
    return (false);
}

// Returns true if there is a valid path.
bool    is_valid_path(char **map, int i, int j, bool **visited, int rows, int cols)
{
    if (is_safe(i, j, rows, cols) && map[i][j] != '1' && !visited[i][j])
    {
        visited[i][j] = true;

        if (map[i][j] == 'E')
            return (true);

        bool up = is_valid_path(map, i - 1, j, visited, rows, cols);

        if (up)
            return (true);

        bool left = is_valid_path(map, i, j - 1, visited, rows, cols);

        if (left)
            return (true);

        bool down = is_valid_path(map, i + 1, j, visited, rows, cols);

        if (down)
            return (true);

        bool right = is_valid_path(map, i, j + 1, visited, rows, cols);

        if (right)
            return (true);
    }
    return (false);
}

bool    check_path(t_game *game)
{
    int rows;
    int cols;
    int i;
    int j;
    int k;
    char    **map;

    i = 0;
    j = 0;
    k = 0;
    rows = game->height;
    cols = game->width;
    map = (char **)malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; ++i)
        map[i] = (char *)malloc(cols * sizeof(char));
    while (game->map[i] != '\0')
    {
        map[j][k] = game->map[i];
        i++;
        k++;
        if (k % game->width == 0)
        {
            j++;
            k = 0;
        }
    }
    bool    **visited = (bool **)malloc(rows * sizeof(bool *));
    for (int i = 0; i < rows; ++i)
    {
        visited[i] = (bool *)malloc(cols * sizeof(bool));
        ft_memset(visited[i], 0, sizeof(bool) * cols);
    }

    bool    flag = false;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (map[i][j] == 'P' && !visited[i][j])
            {
                if (is_valid_path(map, i, j, visited, rows, cols))
                {
                    flag = true;
                    break ;
                }
            }
        }
    }

    for (int i = 0; i < rows; ++i)
        free(visited[i]);
    free(visited);

    if (flag)
    {
        ft_printf("YES\n");
        return (true);
    }
    else
    {
        ft_printf("NO\n");
        return (false);
    }
}

// int main(void)
// {
//     int rows = 5;
//     int cols = 13;
//     char    *map[] = {"1111111111111","100100C0000C1","1000011111001","1P0011E0000C1","1111111111111"};
//     // char    **map = (char **)malloc(rows * sizeof(char *));
//     // for (int i = 0; i < rows; ++i)
//     //     map[i] = (char *)malloc(cols * sizeof(char));
//         // {"1111111111111","100100C0000C1","1000011111001","1P0011E0000C1","1111111111111"};
//
//     isPath(map, rows, cols);
//
//     return (0);
// }
//
