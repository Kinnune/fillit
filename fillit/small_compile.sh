gcc -Wall -Werror -Wextra -o testi.exe end_result.c move_coordinates.c shape_makers.c \
				struct_processing.c tetri_validator.c main.c grid.c \
				solver_shorteners.c ../libft/libft.a 


./testi.exe ../test_files/solve_tetri1.txt

#./testi.exe ../test_files/valid_tetri.txt