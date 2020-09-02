/* WEIRD RESULT ON THIS ITS HAPPY ON TETROS GOING OUTSIDE IF GRID?!
void	ft_recursive(t_tetro **tetro, int **grid, int grid_size)
{
//printf("(%c)", 'A' + (*tetro)->letter);
	ft_move_1(tetro, grid, grid_size);
	if (ft_validate_coordinate(*tetro, grid, grid_size))
	{
ft_putstr("flip current\n");
		ft_flip_grid(*tetro, grid);
		if ((*tetro)->next)
			ft_recursive(&(*tetro)->next, grid, grid_size);
	}
	else if (!(*tetro)->prev && *(*tetro)->y >= grid_size)
	{
		ft_move_coordinate(tetro, -1, 0, grid);
ft_putstr("flip prev\n");
		ft_flip_grid((*tetro)->prev, grid);
		ft_recursive(&(*tetro)->prev, grid, grid_size);
	}
	else
	{
		grid = ft_make_grid(grid, ++grid_size);
		ft_move_coordinate(tetro, -1, 0, grid);
		ft_recursive(tetro, grid, grid_size);
	}
}
*/

//*printf("(x,y):\n%d,%d\t%d,%d\t%d,%d\t%d,%d\n", tetro->x[0], tetro->y[0], tetro->x[1], tetro->y[1], tetro->x[2], tetro->y[2], tetro->x[3], tetro->y[3]);


/*

float start_time, end_time, time_elapsed;

start_time = (float)clock()/CLOCKS_PER_SEC;

//	work

end_time = (float)clock()/CLOCKS_PER_SEC;

time_elapsed = start_time - end_time;

printf("time elapsed = %.6f\n", time_elapsed);

*/

/*char **ft_fill_abc(t_tetro *tetro, int size, char **grid)
{
	int i;

	while (tetro)
	{
		while (i < 4)
		{
			grid[tetro->y[i]][tetro->x[i]] = 'A' + tetro->letter;
			i++;
		}
		tetro = tetro->next;
	}
	size = 0;
	while (grid[size])
	{
		i = 0;
		while (i < size)
		{
			if (!grid[size][i])
				grid[size][i] = '.';
			i++;
		}
		size++;
	}
	return (grid);
}
char **ft_abc_grid(t_tetro *tetro, int grid_size)
{
	int	size;
	char **grid;
	int	i;

	i = 0;
	size = grid_size;
	grid = ft_memalloc(sizeof(char *)* (size + 1));
	grid[size] = NULL;
	while (size)
	{
		size--;
		grid[size] = ft_strnew(grid_size);
	}
	return (ft_fill_abc(tetro, grid_size, grid));
}

void	ft_print_grid_abc(t_tetro *tetro, int grid_size)
{
	int		y;
	int		x;
	char	**grid_abc;

	y = 0;
	grid_abc = ft_abc_grid(tetro, grid_size);
	while (grid_abc[y])
	{
		x = 0;
		while (x < grid_size)
		{
			ft_putchar(grid_abc[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
*/
int	ft_move_1(t_tetro **tetro, int **grid, int size)
{
	while(*(*tetro)->y < size && !ft_validate_coordinate(*tetro, grid, size))
	{
		ft_move_coordinate(tetro, *(*tetro)->x + 1, *(*tetro)->y, grid);
// THIS IS SEGFAULTING \/\/\/\/\/\/\/
		if (*(*tetro)->y)
		{
ft_puterr(*(*tetro)->y);

			ft_move_coordinate(tetro, 0, *(*tetro)->y + 1, grid);
		}
	}
	return (0);
}
/*int	ft_move_1(t_tetro **tetro, int **grid, int size)
{
	while (*(*tetro)->y < size)
	{
		ft_move_coordinate(tetro, *(*tetro)->x + 1, *(*tetro)->y, grid);
		if (ft_validate_coordinate(*tetro, grid, size))
		{
			return (1);
		}
		if (*(*tetro)->x >= size)
		{
			ft_move_coordinate(tetro, 0, *(*tetro)->y + 1, grid);
			if (ft_validate_coordinate(*tetro, grid, size))
			{
				return (1);
			}
		}
	}
	return (0);
}
*/
t_tetro	*ft_reset_coordinates(t_tetro **tetro, int **grid)
{
	t_tetro *head;

	while ((*tetro)->prev)
	{
		(*tetro) = (*tetro)->prev;
	}
	head = *tetro;
	while((*tetro))
	{
		ft_move_coordinate(tetro,  -1, 0, grid);
		(*tetro) = (*tetro)->next;
	}
	return (head);
}
int		ft_in_range(t_tetro *tetro, int **grid, int grid_size)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (*(tetro->y + i) < 0 || *(tetro->x + i) < 0
			|| *(tetro->y + i) >= grid_size || *(tetro->x + i) >= grid_size)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
int	**ft_reset_grid(int **grid, int grid_size)
{
	int x;
	int y;

	y = 0;
	while (y < grid_size)
	{
		x = 0;
		while (x < grid_size)
		{
			grid[y][x] = 0;
			x++;
		}
		y++;
	}
	return (grid);
}

int	ft_judge_grid(int **grid)
{
	int y;
	int x;
	int score;

	y = 0;
	x = 0;
	score = 0;
	while (y < GRID_SIZE)
	{
		x = 0;
		while (x < GRID_SIZE)
		{
			if (grid[y][x] == 0)
				score += y + x;
			x++;
		}
		y++;
	}
	return (score);
}


void	ft_print_grid(int **grid)
{
	int x, y = 0;
	while (y < GRID_SIZE)
	{
		x = 0;
		while (x < GRID_SIZE)
		{
			ft_putnbr(grid[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}


int	**ft_place_block(t_tetro *s_tetro, int **grid)
{
	int x = 0;
	int y = 0;
	int i = 0;
	t_tetro *head;

	head = s_tetro;
	while (s_tetro != NULL)
	{
		printf("loop#%d x = %d y = %d\n", i, x , y);
		if (ft_move_coordinate(&s_tetro, x, y, grid))
		{
			ft_flip_grid(s_tetro, grid);
			s_tetro = s_tetro->next;
			x = 0;
			y = 0;
		}
		else
		{
			x++;
		}
		if (x == GRID_SIZE)
		{
			x = 0;
			y++;
		}
		if (y == GRID_SIZE)
		{
			GRID_SIZE++;
			grid = ft_make_grid(grid);
			s_tetro = head;
			y = 0;
		}
		i++;
	}
	return (grid);
}


/*
t_tetro	*ft_change_coordinates(t_tetro **tetro, char **board, int x_max,int y_max)
{
	int i;
	int j;

	i = 0;
	j = 0;
//	im moving coordiantes to somewhere
	if (ft_validate_coordinate())
		return ();
	else
	{
		tetro->x[0] + 1;
		if (i > x_max)
		{
			x = 0;
			j++;
		}
		if (j > y_max)
			return (make grid bigger)
		ft_change_coordinates()

	}
}
*/

size_t	ft_tetro_count(t_tetro *struct_tetro)
{
	size_t count;

	count = 0;
	while (struct_tetro->prev)
	{
		struct_tetro = struct_tetro->prev;
	}
	while (struct_tetro)
	{
		struct_tetro = struct_tetro->next;
		count++;
	}
	return (count);
}
int	ft_get_biggest(t_tetro *head)
{
	int i;
	int biggest;

	biggest = 0;
	while (head)
	{
		i = 0;
		while (i < 4)
		{
			if (*(head->y + i) > biggest) 
			{
				biggest = *(head->y + i);
			}
			if (*(head->x + i) > biggest)
			{
				biggest = *(head->x + i);
			}
			i++;
		}
		head = head->next;
	}
	return (biggest + 1);
}
int	**ft_generate_answer(t_tetro *s_tetro, int **grid)
{
	int x = 0;
	int y = 0;
	int i = 0;
	t_tetro *head;

	head = s_tetro;
	while (s_tetro != NULL)
	{
//		printf("loop#%d x = %d y = %d\n", i, x , y);
		if (ft_move_coordinate(&s_tetro, x, y, grid))
		{
			ft_flip_grid(s_tetro, grid);
			s_tetro = s_tetro->next;
			x = 0;
			y = 0;
		}
		else
		{
			x++;
			if (x == GRID_SIZE)
			{
				x = 0;
				y++;
			}
			if (y == GRID_SIZE)
			{
				if (ft_move_1(&s_tetro, grid))
				{
					ft_generate_answer(s_tetro->next, grid);
				}
				else
				{
					GRID_SIZE++;
					grid = ft_make_grid(grid);
					s_tetro = head;
				}
			}
		}
		i++;
	}
	ft_generate_answer(head, grid);
	return (grid);
}
//		ft_putstr("moved\n");
//		ft_putstr("loop start\n");
//			ft_putstr("flip current\n");
//			ft_putstr("flipped\n");
//			ft_putstr("x++\n");
//			ft_putstr("x = 0; y++\n");
//			ft_putstr("BIGGER\n");
//			ft_putstr("tetro = prev\n");
//	ft_putstr("END\n");
//	struct_tetro = ft_reset_coordinates(&struct_tetro, grid);
//---------------------------------------
//	grid_size = ft_recursive(&struct_tetro, grid, grid_size);
//	ft_place_block(&struct_tetro, grid, grid_size);
//	ft_putnbr(ft_validate_coordinate(tetro, grid, grid_size));
/*	while(ft_move_1(&head, grid, grid_size))
	{
		printf("(x,y):\n%d,%d\t%d,%d\t%d,%d\t%d,%d\n", head->x[0], head->y[0], head->x[1], head->y[1], head->x[2], head->y[2], head->x[3], head->y[3]);
	}
		printf("(x,y):\n%d,%d\t%d,%d\t%d,%d\t%d,%d\n", head->x[0], head->y[0], head->x[1], head->y[1], head->x[2], head->y[2], head->x[3], head->y[3]);
*/

/*
/*

void	ft_recursive(t_tetro **tetro, int **grid)
{
printf("%c (%d)\n", 'A' + (*tetro)->letter, i++);
	while (!ft_validate_coordinate(*tetro, grid) && *(*tetro)->y < GRID_SIZE)
	{
		ft_move_1(tetro, grid);
	}
	if (!(*tetro)->prev && *(*tetro)->y >= GRID_SIZE)
	{
ft_print_grid(grid);
ft_putstr("bigger!\n");
		ft_move_coordinate(tetro, 0, 0, grid);
		grid = ft_make_grid(grid, ++GRID_SIZE);
		ft_recursive(tetro, grid);
	}
	else if (ft_validate_coordinate(*tetro, grid))
	{
//ft_putstr("forward\n");
		ft_flip_grid(*tetro, grid);
		if ((*tetro)->next)
			ft_recursive(&(*tetro)->next, grid);
	}
	else if ((*tetro)->prev)
	{
//ft_putstr("back\n");
		ft_move_coordinate(tetro, 0, 0, grid);
		tetro = &(*tetro)->prev;
		ft_flip_grid(*tetro, grid);
		if (ft_move_1(tetro, grid))
		{
			ft_flip_grid(*tetro, grid);

			ft_recursive(&(*tetro)->next, grid);
		}
		else
		{
			ft_flip_grid((*tetro)->prev, grid);
			ft_recursive(&(*tetro)->prev, grid);
		}
	}

}


void	ft_recursive(t_tetro **tetro, int **grid)
{
	if (ft_validate_coordinate(*tetro, grid))
	{
		ft_flip_grid(*tetro, grid);
		if ((*tetro)->next)
		{
			ft_recursive(&(*tetro)->next, grid);
			return ;
		}
	}
	else if (*(*tetro)->y < GRID_SIZE || (*tetro)->prev)
	{
		if (ft_move_1(tetro, grid))
		{
			ft_recursive(tetro, grid);
			return ;
		}
		else
		{
			ft_move_coordinate(tetro, 0, 0, grid);
			ft_flip_grid((*tetro)->prev, grid);
			ft_move_1(&(*tetro)->prev, grid);
			ft_recursive(&(*tetro)->prev, grid);
			return ;
		}
	}
	else 
	{
ft_putstr("bigger!\n");
		grid = ft_make_grid(grid, ++GRID_SIZE);
		ft_move_coordinate(tetro, 0, 0, grid);
		ft_recursive(tetro, grid);
		return ;
	}	

}
/*
int	**ft_place_block(t_tetro *s_tetro, int **grid, int grid_size)
{
	int x = 0;
	int y = 0;
	int i = 0;
	t_tetro *head;

	head = s_tetro;
	while (s_tetro != NULL)
	{
		printf("loop#%d x = %d y = %d grid_size = %d\n", i, x , y, grid_size);
ft_move_coordinate(&s_tetro, x, y, grid);
		if (ft_validate_coordinate(s_tetro, grid, grid_size))
		{
			ft_flip_grid(s_tetro, grid, grid_size);
			s_tetro = s_tetro->next;
			x = 0;
			y = 0;
		}
		else
		{
					ft_puterr(1);

			x++;
		}

		ft_puterr(2);
		if (x >= grid_size)
		{
		ft_puterr(6);

			x = 0;
			y++;
		}

		ft_puterr(3);
		if (y >= grid_size)
		{

		ft_puterr(4);
			grid_size++;
			grid = ft_make_grid(grid, grid_size);
			s_tetro = head;
			y = 0;
		}
	}
	return (grid);
}
*/
/*int		ft_safe_move(t_tetro **tetro, int x_max, int y_max, int x, int y);

int		ft_get_biggest(t_tetro *head);

int		ft_in_range(t_tetro *tetro, int **grid, int grid_size);

int		ft_side_len(t_tetro *tetro);



int		ft_judge_grid(int **grid);





int		**ft_generate_answer(t_tetro *s_tetro, int **grid);


int		ft_move_1(t_tetro **tetro, int **grid, int size);

t_tetro	*ft_reset_coordinates(t_tetro **tetro, int **grid);
*/

/*
int	**ft_place_block(t_tetro *s_tetro, int **grid, int grid_size)
{
	int x = 0;
	int y = 0;
	int i = 0;
	t_tetro *head;

	head = s_tetro;
	while (s_tetro != NULL)
	{
		printf("loop#%d x = %d y = %d grid_size = %d\n", i, x , y, grid_size);
		ft_move_coordinate(&s_tetro, x, y, grid);
		if (ft_validate_coordinate(s_tetro, grid, grid_size))
		{
			ft_flip_grid(s_tetro, grid, grid_size);
			s_tetro = s_tetro->next;
			x = 0;
			y = 0;
		}
		else
		{
					ft_puterr(1);

			x++;
		}

		ft_puterr(2);
		if (x >= grid_size)
		{
		ft_puterr(6);

			x = 0;
			y++;
		}

		ft_puterr(3);
		if (y >= grid_size)
		{

		ft_puterr(4);
			grid_size++;
			grid = ft_make_grid(grid, grid_size);
			s_tetro = head;
			y = 0;
		}

		ft_puterr(5);
		i++;
	}
	return (grid);
}


int		ft_recursive(t_tetro **tetro, int **grid, int grid_size)
{
	while (*tetro)
	{

		if (ft_move_1(tetro, grid, grid_size))
		{
			ft_flip_grid(*tetro, grid, grid_size);
			*tetro = (*tetro)->next;
		}
		else
		{
			if ((*tetro)->prev)
			{
				ft_move_coordinate(tetro, -1, 0, grid);
				ft_flip_grid((*tetro)->prev, grid, grid_size);
				*tetro = (*tetro)->prev;
			}
			else if ((*tetro)->letter == 0 && *(*tetro)->y >= grid_size)
			{
				ft_move_coordinate(tetro, -1, 0, grid);
				grid = ft_make_grid(grid, ++grid_size);

			}
		}
	}
	return (grid_size);
}



//ft_putstr("flip prev\n");
//ft_putstr("flip current\n");
//printf("(%c)", 'A' + (*tetro)->letter);
//printf("(%d)\n", i++);
//ft_print_grid_abc(*tetro, grid_size);
//ft_putchar('\n');
//ft_putnbr(grid_size);


void	ft_recursive(t_tetro **tetro, int **grid, int grid_size)
{
//printf("(%c)", 'A' + (*tetro)->letter);
	ft_move_1(tetro, grid, grid_size);
	if (ft_validate_coordinate(*tetro, grid, grid_size))
	{
ft_putstr("flip current\n");
		ft_flip_grid(*tetro, grid, grid_size);
		if ((*tetro)->next)
			ft_recursive(&(*tetro)->next, grid, grid_size);
	}
	else if (!(*tetro)->prev)
	{
		grid = ft_make_grid(grid, ++grid_size);
		ft_move_coordinate(tetro, -1, 0, grid);
		ft_recursive(tetro, grid, grid_size);
	}
	else
	{

		ft_move_coordinate(tetro, -1, 0, grid);
ft_putstr("flip prev\n");
		ft_flip_grid((*tetro)->prev, grid, grid_size);
		ft_recursive(&(*tetro)->prev, grid, grid_size);

	}
}
*/


//printf("(%c)", 'A' + (*tetro)->letter);


int	ft_recursive(t_tetro **s_tetro, int **grid)
{
	static int n = 0;
	static int	loop = 1;
	static int	palikka = 1;

	printf("\033[33mrundi %d ---------------------------------------------- \033[0m\n", loop++);
	n++;
	if (!ft_validate_coordinate(*s_tetro, grid) && *(*s_tetro)->y < GRID_SIZE)
	{
		printf("\033[01;36mpalikkaa %d liikutellaan gridin sisalla, kunnes validi\033[0m\n", palikka);
		ft_move_1(s_tetro, grid);
	}
	printf("GRID_SIZE on: %dx%d\n", GRID_SIZE, GRID_SIZE);
	if (*(*s_tetro)->y >= GRID_SIZE && !(*s_tetro)->prev)
	{
		GRID_SIZE++;
		printf("\033[01;35mgrid made bigger (now %dx%d)\033[0m\n", GRID_SIZE, GRID_SIZE);
		grid = ft_make_grid(grid, GRID_SIZE);
		*s_tetro = ft_reset_coordinates(s_tetro, grid);
		palikka = 1;
		ft_recursive(s_tetro, grid);
	}
	else if (*(*s_tetro)->y >= GRID_SIZE)
	{
		printf("\033[01;31mpalikka %d meni yli [%d,%d] [%d,%d] [%d,%d] [%d,%d]\033[0m\n", palikka, (*s_tetro)->x[0], (*s_tetro)->y[0], (*s_tetro)->x[1], (*s_tetro)->y[1], (*s_tetro)->x[2], (*s_tetro)->y[2], (*s_tetro)->x[3], (*s_tetro)->y[3]);
		ft_flip_grid((*s_tetro)->prev, grid);
		if (ft_move_1(&(*s_tetro)->prev, grid))
		{
			printf("\033[01;32mpalikan %d liikuttaminen onnistui [%d,%d] [%d,%d] [%d,%d] [%d,%d]\033[0m\n", palikka -1, (*s_tetro)->prev->x[0], (*s_tetro)->prev->y[0], (*s_tetro)->prev->x[1], (*s_tetro)->prev->y[1], (*s_tetro)->prev->x[2], (*s_tetro)->prev->y[2], (*s_tetro)->prev->x[3], (*s_tetro)->prev->y[3]);
			ft_flip_grid((*s_tetro)->prev, grid);
			ft_move_coordinate(s_tetro, 0, 0, grid);
			ft_recursive(s_tetro, grid);
		}
		else
		{
			printf("\033[01;31mpalikkaa %d ei voi liikuttaa... [%d,%d] [%d,%d] [%d,%d] [%d,%d]\033[0m\n", palikka -1, (*s_tetro)->x[0], (*s_tetro)->y[0], (*s_tetro)->x[1], (*s_tetro)->y[1], (*s_tetro)->x[2], (*s_tetro)->y[2], (*s_tetro)->x[3], (*s_tetro)->y[3]);
			ft_move_coordinate(s_tetro, 0, 0, grid);
			palikka--;
			ft_recursive(&(*s_tetro)->prev, grid);
		}
	}
	else if ((*s_tetro)->next)
	{
		printf("\033[01;32mpalikka %d osui kohdalleen [%d,%d] [%d,%d] [%d,%d] [%d,%d]\033[0m\n", palikka++, (*s_tetro)->x[0], (*s_tetro)->y[0], (*s_tetro)->x[1], (*s_tetro)->y[1], (*s_tetro)->x[2], (*s_tetro)->y[2], (*s_tetro)->x[3], (*s_tetro)->y[3]);
		if ((*s_tetro)->next)
		{
			printf("seuraava palikka on olemassa\n");
		}
		ft_flip_grid((*s_tetro), grid);
		ft_recursive(&(*s_tetro)->next, grid);
	}
	else
//	if (!(*s_tetro)->next)
//	{
//		ft_puterr(6);
//		printf("\033[01;32mvika palikka %d osui kohdalleen\033[0m\n", palikka);
//		printf("taa oli vika palikka\n");
//		return (n);
//	}
//	ft_puterr(8);
	printf("\033[01;32mvika palikka %d osui kohtaan [%d,%d] [%d,%d] [%d,%d] [%d,%d]\033[0m\n", palikka++, (*s_tetro)->x[0], (*s_tetro)->y[0], (*s_tetro)->x[1], (*s_tetro)->y[1], (*s_tetro)->x[2], (*s_tetro)->y[2], (*s_tetro)->x[3], (*s_tetro)->y[3]);
//	write(1, "ei mee mihkaan looppiin\n", 24);
//	exit (0);
	return (n);
}

void	ft_recursive(t_tetro **s_tetro, int **grid)
{
printf("Tetri nr.%d (x,y):\n%d,%d\t%d,%d\t%d,%d\t%d,%d\n", (*s_tetro)->letter, (*s_tetro)->x[0], (*s_tetro)->y[0], (*s_tetro)->x[1], (*s_tetro)->y[1], (*s_tetro)->x[2], (*s_tetro)->y[2], (*s_tetro)->x[3], (*s_tetro)->y[3]);
ft_print_grid(grid);
	if (*(*s_tetro)->y < GRID_SIZE)
	{
		if (ft_validate_coordinate(*s_tetro, grid))
		{
			ft_flip_grid(*s_tetro, grid);
			if (!(*s_tetro)->next)
				return ;
			ft_recursive(&(*s_tetro)->next, grid);
		}
		else
		{
			ft_move_1(s_tetro, grid);
			ft_recursive(s_tetro, grid);
		}
	}
	else
	{
		if ((*s_tetro)->letter != 0)
		{
			ft_flip_grid((*s_tetro)->prev, grid);
			ft_move_coordinate(s_tetro, 0, 0, grid);
			ft_recursive(&(*s_tetro)->prev, grid);
		}
		else
		{
			ft_reset_coordinates(s_tetro, grid);
			grid = ft_make_grid(grid, ++GRID_SIZE);
			ft_recursive(s_tetro, grid);
		}
	}
}

void	ft_recursive(t_tetro **s_tetro, int **grid)
{
printf("Tetri nr.%d (x,y):\n%d,%d\t%d,%d\t%d,%d\t%d,%d\n", (*s_tetro)->letter, (*s_tetro)->x[0], (*s_tetro)->y[0], (*s_tetro)->x[1], (*s_tetro)->y[1], (*s_tetro)->x[2], (*s_tetro)->y[2], (*s_tetro)->x[3], (*s_tetro)->y[3]);
ft_print_grid(grid);
	if (ft_validate_coordinate(*s_tetro, grid))
	{
		ft_flip_grid(*s_tetro, grid);
		if (!(*s_tetro)->next)
			return ;
		ft_recursive(&(*s_tetro)->next, grid);
	}
	else if (*(*s_tetro)->y < GRID_SIZE)
	{
		ft_move_1(s_tetro, grid);
		ft_recursive(s_tetro, grid);
	}
	else if ((*s_tetro)->prev)
	{
		ft_flip_grid((*s_tetro)->prev, grid);
		ft_move_coordinate(s_tetro, 0, 0, grid);
		ft_recursive(&(*s_tetro)->prev, grid);
	}
	else
	{
		ft_reset_coordinates(s_tetro, grid);
		grid = ft_make_grid(grid, ++GRID_SIZE);
		ft_recursive(s_tetro, grid);
	}
}


void	ft_recursive(t_tetro **s_tetro, int **grid)
{
	
//ft_putstr((*s_tetro)->raw);
	while (!ft_validate_coordinate(*s_tetro, grid) && *(*s_tetro)->y < GRID_SIZE)
	{
		ft_move_1(s_tetro, grid);
	}
	if (*(*s_tetro)->y >= GRID_SIZE)
	{
		if ((*s_tetro)->prev)
			ft_flip_grid((*s_tetro)->prev, grid);
		if((*s_tetro)->letter == 0)
		{
			grid = ft_make_grid(grid, ++ GRID_SIZE);
			ft_reset_coordinates(s_tetro, grid);
			ft_recursive(s_tetro, grid);
		}
		else if (ft_move_1(&(*s_tetro)->prev, grid))
		{
			ft_flip_grid((*s_tetro)->prev, grid);
			ft_move_coordinate(s_tetro, 0, 0, grid);
			ft_recursive(s_tetro, grid);
		}
		else
		{
			ft_move_coordinate(s_tetro, 0, 0, grid);
			ft_recursive(&(*s_tetro)->prev, grid);
		}
	}
	else if ((*s_tetro)->next)
	{
		ft_flip_grid((*s_tetro), grid);
		ft_recursive(&(*s_tetro)->next, grid);
	}

}

*/
void	ft_recursive(t_tetro **s_tetro, int **grid)
{
printf("Tetri nr.%d (x,y):\n%d,%d\t%d,%d\t%d,%d\t%d,%d\n", (*s_tetro)->letter, (*s_tetro)->x[0], (*s_tetro)->y[0], (*s_tetro)->x[1], (*s_tetro)->y[1], (*s_tetro)->x[2], (*s_tetro)->y[2], (*s_tetro)->x[3], (*s_tetro)->y[3]);
ft_print_grid(grid);
	if (*(*s_tetro)->y < GRID_SIZE)
	{
		if (ft_validate_coordinate(*s_tetro, grid))
		{
			ft_flip_grid(*s_tetro, grid);
			if (!(*s_tetro)->next)
				return ;
			ft_recursive(&(*s_tetro)->next, grid);
		}
		else
		{
			ft_move_1(s_tetro, grid);
			ft_recursive(s_tetro, grid);
		}
	}
	else
	{
		if ((*s_tetro)->letter != 0)
		{
			ft_flip_grid((*s_tetro)->prev, grid);
			ft_move_coordinate(s_tetro, 0, 0, grid);
			ft_recursive(&(*s_tetro)->prev, grid);
		}
		else
		{
			ft_reset_coordinates(s_tetro, grid);
			GRID_SIZE++;
			grid = ft_make_grid(grid);
			ft_recursive(s_tetro, grid);
		}
	}
}
void	ft_recursive(t_tetro **s_tetro, int **grid)
{
	if (!*s_tetro)
		return ;
	if (ft_validate_coordinate(*s_tetro, grid))
	{
		if ((*s_tetro)->next)
		{
			ft_flip_grid(*s_tetro, grid);
			ft_recursive(&(*s_tetro)->next, grid);
		}
	}
	else
	{
		ft_move_1(s_tetro, grid);
		ft_recursive(s_tetro, grid);
	}
	if (*(*s_tetro)->y > GRID_SIZE)
	{
		if ((*s_tetro)->letter != 0)
		{
			ft_move_coordinate(s_tetro, 0, 0, grid);
			ft_flip_grid((*s_tetro)->prev, grid);
			ft_recursive(&(*s_tetro)->prev, grid);
		}
		else
		{
			ft_reset_coordinates(s_tetro, grid);
			GRID_SIZE++;
			grid = ft_make_grid(grid);
			ft_recursive(s_tetro, grid);
		}
	}
}
////////////////////////////////////////////////////////////
int	ft_recursive(t_tetro **s_tetro, int **grid)
{
	int grid_save;
	static int n = 0;
	static int	loop = 1;
	static int	palikka = 1;

	printf("\033[33mrundi %d ---------------------------------------------- \033[0m\n", loop++);
	n++;
	grid_save = GRID_SIZE;
//ft_puterr(0);
	
//	if (!(*s_tetro)->next)
//	{
//		ft_puterr(6);
//		printf("\033[01;32mvika palikka %d osui kohdalleen\033[0m\n", palikka);
//		printf("taa oli vika palikka\n");
//		return (n);
//	}
	if (!ft_validate_coordinate(*s_tetro, grid) && *(*s_tetro)->y < GRID_SIZE)
	{
//	ft_puterr(1);
		printf("\033[01;36mpalikkaa %d liikutellaan gridin sisalla, kunnes validi\033[0m\n", palikka);
		ft_move_1(s_tetro, grid);
	}
//	printf("*(*s_tetro)->x on: %d\n", *(*s_tetro)->x);
//	printf("*(*s_tetro)->y on: %d\n", *(*s_tetro)->y);
//	printf("ulos whilesta koordinaateilla: [%d,%d] [%d,%d] [%d,%d] [%d,%d]\n", (*s_tetro)->x[0], (*s_tetro)->y[0], (*s_tetro)->x[1], (*s_tetro)->y[1], (*s_tetro)->x[2], (*s_tetro)->y[2], (*s_tetro)->x[3], (*s_tetro)->y[3]);
	printf("GRID_SIZE on: %dx%d\n", GRID_SIZE, GRID_SIZE);
	if (*(*s_tetro)->y >= GRID_SIZE && !(*s_tetro)->prev)
	{
//	ft_puterr(2);
		GRID_SIZE++;
		printf("\033[01;35mgrid made bigger (now %dx%d)\033[0m\n", GRID_SIZE, GRID_SIZE);
		grid = ft_make_grid(grid);
//		printf("%d", (*s_tetro)->letter);
		*s_tetro = ft_reset_coordinates(s_tetro, grid);
		palikka = 1;
		ft_recursive(s_tetro, grid);
	}
	else if (*(*s_tetro)->y >= GRID_SIZE)
	{
//	ft_puterr(3);
		printf("\033[01;31mpalikka %d meni yli [%d,%d] [%d,%d] [%d,%d] [%d,%d]\033[0m\n", palikka, (*s_tetro)->x[0], (*s_tetro)->y[0], (*s_tetro)->x[1], (*s_tetro)->y[1], (*s_tetro)->x[2], (*s_tetro)->y[2], (*s_tetro)->x[3], (*s_tetro)->y[3]);
		ft_flip_grid((*s_tetro)->prev, grid);
		if (ft_move_1(&(*s_tetro)->prev, grid))
		{
			printf("\033[01;32mpalikan %d liikuttaminen onnistui [%d,%d] [%d,%d] [%d,%d] [%d,%d]\033[0m\n", palikka -1, (*s_tetro)->prev->x[0], (*s_tetro)->prev->y[0], (*s_tetro)->prev->x[1], (*s_tetro)->prev->y[1], (*s_tetro)->prev->x[2], (*s_tetro)->prev->y[2], (*s_tetro)->prev->x[3], (*s_tetro)->prev->y[3]);
//			printf("%d\n", (*s_tetro)->y[0]);
			ft_flip_grid((*s_tetro)->prev, grid);
			ft_move_coordinate(s_tetro, 0, 0, grid);
			ft_recursive(s_tetro, grid);
		}
		else
		{
			printf("\033[01;31mpalikkaa %d ei voi liikuttaa... [%d,%d] [%d,%d] [%d,%d] [%d,%d]\033[0m\n", palikka -1, (*s_tetro)->x[0], (*s_tetro)->y[0], (*s_tetro)->x[1], (*s_tetro)->y[1], (*s_tetro)->x[2], (*s_tetro)->y[2], (*s_tetro)->x[3], (*s_tetro)->y[3]);
			ft_move_coordinate(s_tetro, 0, 0, grid);
			palikka--;
			ft_recursive(&(*s_tetro)->prev, grid);
		}
	}
	else if ((*s_tetro)->next)
	{
//		ft_puterr(4);
		printf("\033[01;32mpalikka %d osui kohdalleen [%d,%d] [%d,%d] [%d,%d] [%d,%d]\033[0m\n", palikka++, (*s_tetro)->x[0], (*s_tetro)->y[0], (*s_tetro)->x[1], (*s_tetro)->y[1], (*s_tetro)->x[2], (*s_tetro)->y[2], (*s_tetro)->x[3], (*s_tetro)->y[3]);
		if ((*s_tetro)->next)
		{
//			ft_puterr(5);
			printf("seuraava palikka on olemassa\n");
		}
//		printf("flipataan ykkoset ja mennaan back\n");
		ft_flip_grid((*s_tetro), grid);
		ft_recursive(&(*s_tetro)->next, grid);
	}
	else
//	if (!(*s_tetro)->next)
//	{
//		ft_puterr(6);
//		printf("\033[01;32mvika palikka %d osui kohdalleen\033[0m\n", palikka);
//		printf("taa oli vika palikka\n");
//		return (n);
//	}
//	ft_puterr(8);
	printf("\033[01;32mvika palikka %d osui kohtaan [%d,%d] [%d,%d] [%d,%d] [%d,%d]\033[0m\n", palikka++, (*s_tetro)->x[0], (*s_tetro)->y[0], (*s_tetro)->x[1], (*s_tetro)->y[1], (*s_tetro)->x[2], (*s_tetro)->y[2], (*s_tetro)->x[3], (*s_tetro)->y[3]);
//	write(1, "ei mee mihkaan looppiin\n", 24);
//	exit (0);
	return (n);
}
void	ft_recursive(t_tetro **s_tetro, int **grid)
{
	int grid_save;

	grid_save = GRID_SIZE;
//ft_puterr(0);
	while (!ft_validate_coordinate(*s_tetro, grid) && (*s_tetro)->y[0] < GRID_SIZE)
	{
//ft_puterr((*s_tetro)->y[0]);
		ft_move_1(s_tetro, grid);
	}
	if (*(*s_tetro)->y >= GRID_SIZE && !(*s_tetro)->prev)
	{
//ft_puterr(2);
		GRID_SIZE++;
		grid = ft_make_grid(grid);
printf("%d", (*s_tetro)->letter);
		*s_tetro = ft_reset_coordinates(s_tetro, grid);
		ft_recursive(s_tetro, grid);
	}
	else if (*(*s_tetro)->y >= GRID_SIZE)
	{
//ft_puterr(3);
		ft_flip_grid((*s_tetro)->prev, grid);
		if (ft_move_1(&(*s_tetro)->prev, grid))
		{
			ft_flip_grid((*s_tetro)->prev, grid);
			ft_move_coordinate(s_tetro, 0, 0, grid);
			ft_recursive(s_tetro, grid);
		}
		else
		{
			ft_move_coordinate(s_tetro, 0, 0, grid);

			ft_recursive(&(*s_tetro)->prev, grid);
		}
	}
	else if ((*s_tetro)->next)
	{
//ft_puterr(4);
		ft_flip_grid((*s_tetro), grid);
		ft_recursive(&(*s_tetro)->next, grid);
	}
printf("the end");
}
*/

