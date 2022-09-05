// ATOS PROJECT, 2022
// DEMETER
// File description:
// Wow, such plugin, much data!
//___________________________________________________________________________________________________________________________________________

#include <stdio.h>
#include <stdbool.h>

bool is_writable_path(char *path)
{
    FILE *file = NULL;

    if (path == NULL)
        return false;
    file = fopen(path, "w");
    if (file == NULL)
        return false;
    fclose(file);
    return true;
}
