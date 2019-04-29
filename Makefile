##
## EPITECH PROJECT, 2018
## CPE_dante_2018
## File description:
## Makefile
##

GEN_DIR	=	generator/
SOL_DIR	=	solver/


##normal Make
all:
	make -C $(GEN_DIR)
	make -C $(SOL_DIR)

clean:
	make clean -C $(GEN_DIR)
	make clean -C $(SOL_DIR)

##make fclean
fclean:	clean
	make fclean -C $(SOL_DIR)
	make fclean -C $(GEN_DIR)

re:	fclean all

.PHONY:	all clean fclean re
