// ATOS PROJECT, 2022
// DEMETER
// File description:
// Wow, such task, many info!
//___________________________________________________________________________________________________________________________________________

#include <stdlib.h>
#include <time.h>
#include "demeter_task.h"

job_id_info_t *get_task_info(stepd_step_rec_t *job)
{
    job_id_info_t *job_info = malloc(sizeof(job_id_info_t));

    if (job_info == NULL)
        return NULL;
    job_info->job_id = job->array_job_id;
    job_info->uid = job->uid;
    job_info->step_id = job->step_id.step_id;
    time(&job_info->start_time);
    return job_info;
}
