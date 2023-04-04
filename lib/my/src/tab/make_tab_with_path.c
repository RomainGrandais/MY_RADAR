/*
** EPITECH PROJECT, 2022
** make_tab_with_path.c
** File description:
** make char ** with file .txt
*/

char *make_buffer(char *file);
char **my_str_to_word_array(char const *str);

char **make_tab_with_path(char *path)
{
    char *buffer = make_buffer(path);
    return (my_str_to_word_array(buffer));
}