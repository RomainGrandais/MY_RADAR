/*
** EPITECH PROJECT, 2022
** message.c
** File description:
** message for -h
*/

#include <my.h>
#include <structure.h>

void message(void)
{
    mini_printf("Air traffic simulation panel\n\n");
    mini_printf("Usage\n  ./my_radar [OPTIONS] path_to_script\n");
    mini_printf("  path_to_script The path to the script file.\n\n");
    mini_printf("OPTIONS\n  -h print the usage and quit.\n\n");
    mini_printf("USER INTERACTIONS\n");
    mini_printf("  L key enable/disable hitboxes and areas.\n");
    mini_printf("  S key enable/disable sprites.\n");
}