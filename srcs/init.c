#include "2048.h"
#include <ncurses.h>
#include <stdint.h>
#include <stdlib.h>

static uint16_t reverse_line(uint16_t line)
{
	return ((line >> 12) & 0x000F) | ((line >> 4) & 0x00F0)
		   | ((line << 4) & 0x0F00) | ((line << 12) & 0xF000);
}

void init_tables(t_board* board)
{
	uint16_t* lut_left = board->lut_left;

	for (uint32_t i = 0; i <= UINT16_MAX; i++)
	{
		uint16_t line[4];
		uint32_t score = 0;

		for (size_t j = 0; j < 4; j++)
		{
			line[j] = (i >> (j * 4)) & 0xF;
		}

		for (size_t j = 0; j < 3; j++)
		{
			int next;

			for (next = j + 1; next < 4; next++)
			{
				if (line[next] != 0)
				{
					break;
				}
			}

			if (next == 4)
			{
				break;
			}

			if (line[j] == 0)
			{
				line[j] = line[next];
				line[next] = 0;
				j--;
			}
			else if (line[j] == line[next] && line[j] < 0xF)
			{
				line[j]++;
				line[next] = 0;
				score += (1 << line[j]);
			}
		}

		lut_left[i] = (line[0] << 0) | (line[1] << 4) | (line[2] << 8)
					  | (line[3] << 12);
		board->lut_score[i] = score;
	}

	for (uint32_t i = 0; i <= UINT16_MAX; i++)
	{
		board->lut_right[i] = reverse_line(board->lut_left[reverse_line(i)]);
	}
}
