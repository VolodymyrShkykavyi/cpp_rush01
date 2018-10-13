NAME = ft_gkrellm
SRC = main.cpp Module.cpp CPU.cpp
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))
OBJ_DIR = objects
CC = clang++
FLAGS = -Wall -Werror -Wextra
INCLUDES = -lncurses

all: $(NAME)
$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(INCLUDES)
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
$(OBJ_DIR)/%.o: %.cpp
	$(CC) $(FLAGS) -o $@ -c $<
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
run: re
	./$(NAME)
