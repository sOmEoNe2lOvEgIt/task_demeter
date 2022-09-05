// ATOS PROJECT, 2022
// DEMETER
// File description:
// Wow, such include, many things!
//___________________________________________________________________________________________________________________________________________

#ifndef DEMETER_TASK_H_
#define DEMETER_TASK_H_

#include <stdbool.h>
#include "slurm/slurm.h"
#include "demeter.h"

char *get_conf_path(void);
bool is_writable_path(char *path);
job_id_info_t *get_task_info(stepd_step_rec_t *job);

#endif /* DEMETER_TASK_H_ */