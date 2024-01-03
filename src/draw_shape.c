#include "../includes/so_long.h"

void draw_circle(t_data *data, int center_x, int center_y, int radius, int color)
{
    for (int y = -radius; y <= radius; y++)
    {
        for (int x = -radius; x <= radius; x++)
        {
            if (x * x + y * y <= radius * radius)
            {
                int pixel_x = center_x + x;
                int pixel_y = center_y + y;
                if (pixel_x >= 0  && pixel_y >= 0) 
                {
                    my_mlx_pixel_put(data, pixel_x, pixel_y, color);
                }
            }
        }
    }
}

void draw_square(t_data *data, int x, int y, int size, int color)
{
    // Square
    for (int i = y; i < y + size; i++)
    {
        for (int j = x; j < x + size; j++)
        {
            my_mlx_pixel_put(data, i, j, color);
        }
    }
}

void draw_grad_square(t_data *data, int x, int y, int size)
{
    // Square
    for (int i = y; i < y + size; i++)
    {
        for (int j = x; j < x + size; j++)
        {
            int red = 255 * (i - y) / size;
            int green = 255 * (j - x) / size;
            int blue = 255;
            int color = 0x00000000;
            color = (red << 16) | (green << 8) | blue;
            my_mlx_pixel_put(data, i, j, color);
        }
    }
}

void generate_checked_texture(t_data *data, int width, int height)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            // Example: Checkerboard pattern
            int color = ((x / 50) + (y / 50)) % 2 == 0 ? 0xFFFFFF : 0x000000;

            my_mlx_pixel_put(data, x, y, color);
        }
    }
}

