##
## EPITECH PROJECT, 2019
## OOP_nanotekspice_2019
## File description:
## Makefile
##

NAME				=		nanotekspice
LIB_NAME			=		libmy.so
LIB_ST_NAME			=		libmy.a
TEST_NAME			=		tests/unit_tests
TEST_SH_NAME		=		tests/tests.sh

COV_DIR				=		obj
INCL_DIR			=		src
OBJ_DIR				=		obj
SRC_DIR				=		src
TEST_DIR			=		tests

AR					=		ar rcs
CC					=		g++
RM					=		rm -rf

MAIN_SRC			=		main.cpp

PROJ_SRC			=		cli/CLI.cpp				\
							cli/Error.cpp			\
							chipset/C4001.cpp		\
							chipset/C4011.cpp		\
							chipset/C4013.cpp		\
							chipset/C4030.cpp		\
							chipset/C4069.cpp		\
							chipset/C4071.cpp		\
							chipset/C4081.cpp		\
							container/DFlipFlop.cpp	\
							container/NAND.cpp		\
							container/NOR.cpp		\
							gate/AND.cpp			\
							gate/NOT.cpp			\
							gate/OR.cpp				\
							gate/XOR.cpp			\
							io/Clock.cpp			\
							io/False.cpp			\
							io/Input.cpp			\
							io/Output.cpp			\
							io/True.cpp				\
							nts/AComponent.cpp		\
							nts/Circuit.cpp			\
							nts/Container.cpp		\
							nts/Error.cpp			\
							nts/Factory.cpp			\
							nts/Link.cpp			\
							parser/Error.cpp		\
							parser/Parser.cpp		\
							util/string.cpp			\

TEST_SRC			=		chipset/test_C4001.cpp			\
							chipset/test_C4011.cpp			\
							chipset/test_C4030.cpp			\
							chipset/test_C4069.cpp			\
							chipset/test_C4071.cpp			\
							chipset/test_C4081.cpp			\
							container/test_DFlipFlop.cpp	\
							container/test_NAND.cpp			\
							container/test_NOR.cpp			\
							gate/test_AND.cpp				\
							gate/test_NOT.cpp				\
							gate/test_OR.cpp				\
							gate/test_XOR.cpp				\
							io/mock/Undefined.cpp			\
							io/test_Clock.cpp				\
							io/test_False.cpp				\
							io/test_Input.cpp				\
							io/test_Output.cpp				\
							io/test_True.cpp				\

CFLAGS				+=		-I $(INCL_DIR)
CFLAGS				+=		-W -Wall -Wextra -Werror

MAIN_OBJ			=		$(MAIN_SRC:%.cpp=$(OBJ_DIR)/%.o)

PROJ_OBJ			=		$(PROJ_SRC:%.cpp=$(OBJ_DIR)/%.o)

TEST_OBJ			=		$(TEST_SRC:%.cpp=$(OBJ_DIR)/%.o)

TEST_COV			=		$(PROJ_SRC:%.cpp=$(COV_DIR)/%.gcda)	\
							$(PROJ_SRC:%.cpp=$(COV_DIR)/%.gcno)	\
							$(TEST_SRC:%.cpp=$(COV_DIR)/%.gcda)	\
							$(TEST_SRC:%.cpp=$(COV_DIR)/%.gcno)	\

MAKEFLAGS			+=		--silent

NO_COLOR			=		\e[0;0m
GREEN_COLOR			=		\e[0;32m
RED_COLOR			=		\e[0;31m
GREEN_B_COLOR		=		\e[1;32m
RED_B_COLOR			=		\e[1;31m
YELLOW_B_COLOR		=		\e[1;33m

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.cpp
					mkdir -p $(@D)
					$(CC) $(CFLAGS) -c $< -o $@ \
					&& echo "$< $(GREEN_COLOR)successfully compiled$(NO_COLOR)" \
					|| { echo "$< $(RED_COLOR)couldn't be compiled$(NO_COLOR)"; exit 1; }

$(OBJ_DIR)/%.o:		$(TEST_DIR)/%.cpp
					mkdir -p $(@D)
					$(CC) $(CFLAGS) -c $< -o $@ \
					&& echo "$< $(GREEN_COLOR)successfully compiled$(NO_COLOR)" \
					|| { echo "$< $(RED_COLOR)couldn't be compiled$(NO_COLOR)"; exit 1; }

$(NAME):			$(MAIN_OBJ) $(PROJ_OBJ)
					$(CC) $(MAIN_OBJ) $(PROJ_OBJ) -o $(NAME) $(LDFLAGS) $(LDLIBS) \
					&& echo "$(GREEN_B_COLOR)$(NAME) successfully created$(NO_COLOR)" \
					|| { echo "$(RED_B_COLOR)$(NAME) couldn't be created$(NO_COLOR)"; exit 1; }

all:				$(NAME)

clean:
					$(RM) $(MAIN_OBJ) $(PROJ_OBJ)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

sweet:				all clean

debug:				CFLAGS += -g3
debug:				all

debug_re:			CFLAGS += -g3
debug_re:			re

debug_sweet:		CFLAGS += -g3
debug_sweet:		sweet

$(LIB_NAME):		CFLAGS += -fPIC
$(LIB_NAME):		LDFLAGS += -shared
$(LIB_NAME):		$(PROJ_OBJ)
					$(CC) $(PROJ_OBJ) -o $(LIB_NAME) $(LDFLAGS) $(LDLIBS) \
					&& echo "$(GREEN_B_COLOR)$(LIB_NAME) successfully created$(NO_COLOR)" \
					|| { echo "$(RED_B_COLOR)$(LIB_NAME) couldn't be created$(NO_COLOR)"; exit 1; }

lib:				$(LIB_NAME)

lib_clean:
					$(RM) $(PROJ_OBJ)

lib_fclean:			lib_clean
					$(RM) $(LIB_NAME)

lib_re:				lib_fclean lib

lib_sweet:			lib lib_clean

$(LIB_ST_NAME):		$(PROJ_OBJ)
					$(AR) $(LIB_ST_NAME) $(PROJ_OBJ) \
					&& echo "$(GREEN_B_COLOR)$(LIB_ST_NAME) successfully created$(NO_COLOR)" \
					|| { echo "$(RED_B_COLOR)$(LIB_ST_NAME) couldn't be created$(NO_COLOR)"; exit 1; }

lib_st:				$(LIB_ST_NAME)

lib_st_clean:		lib_clean

lib_st_fclean:		lib_st_clean
					$(RM) $(LIB_ST_NAME)

lib_st_re:			lib_st_fclean lib_st

lib_st_sweet:		lib_st lib_st_clean

$(TEST_NAME):		CFLAGS += -fprofile-arcs -ftest-coverage
$(TEST_NAME):		LDLIBS += -lgcov -lcriterion
$(TEST_NAME):		$(PROJ_OBJ) $(TEST_OBJ)
					if [ -d $(TEST_DIR) ]; then \
						$(CC) $(PROJ_OBJ) $(TEST_OBJ) -o $(TEST_NAME) $(LDFLAGS) $(LDLIBS) \
						&& echo "$(GREEN_B_COLOR)$(TEST_NAME) successfully created$(NO_COLOR)" \
						|| { echo "$(RED_B_COLOR)$(TEST_NAME) couldn't be created$(NO_COLOR)"; exit 1; } \
					fi

tests_run:			$(TEST_NAME)
					if [ ! -d $(TEST_DIR) ] || [ ! -f $(TEST_NAME) ]; then \
						echo "$(YELLOW_B_COLOR)Unit tests not found$(NO_COLOR)"; \
					else \
						./$(TEST_NAME) \
						&& echo "$(GREEN_B_COLOR)Unit tests passed successfully$(NO_COLOR)" \
						|| { echo "$(RED_B_COLOR)Unit tests did not pass successfully$(NO_COLOR)"; exit 1; } \
					fi

tests_clean:		clean
					$(RM) $(TEST_OBJ)
					$(RM) $(TEST_COV)

tests_fclean:		tests_clean
					$(RM) $(TEST_NAME)

tests_re:			tests_fclean tests_run

tests_sweet:		tests_run tests_clean

tests_sh:			re
					if [ ! -d $(TEST_DIR) ] || [ ! -f $(TEST_SH_NAME) ]; then \
						echo "$(YELLOW_B_COLOR)Functional tests not found$(NO_COLOR)"; \
					else \
						sh $(TEST_SH_NAME) $(NAME) \
						&& echo "$(GREEN_B_COLOR)Functional tests passed successfully$(NO_COLOR)" \
						|| { echo "$(RED_B_COLOR)Functional tests did not pass successfully$(NO_COLOR)"; exit 1; } \
					fi

full:				all lib lib_st

full_clean:			clean lib_clean lib_st_clean tests_clean

full_fclean:		fclean lib_fclean lib_st_fclean tests_fclean

full_re:			re lib_re lib_st_re

full_sweet:			sweet lib_sweet lib_st_sweet

.PHONY:				all clean fclean re sweet											\
					debug debug_re debug_sweet											\
					lib lib_clean lib_fclean lib_re lib_sweet							\
					lib_st lib_st_clean lib_st_fclean lib_st_re lib_st_sweet			\
					tests_run tests_clean tests_fclean tests_re tests_sweet tests_sh	\
					full full_clean full_fclean full_re full_sweet						\
