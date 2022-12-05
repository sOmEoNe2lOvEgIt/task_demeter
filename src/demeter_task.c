// ATOS PROJECT, 2022
// DEMETER
// File description:
// Wow, such plugin, much data!
//___________________________________________________________________________________________________________________________________________

#include <stdbool.h>
#include "src/common/log.h"
#include "src/slurmd/common/task_plugin.h"
#include "demeter_task.h"

const char plugin_name[]        = "task demeter plugin";
const char plugin_type[]        = "task/demeter :";
const uint32_t plugin_version   = SLURM_VERSION_NUMBER;
static job_id_info_t *task_info = NULL;
static cgroup_data_t *cgroup_data = NULL;
static demeter_conf_t *demeter_conf = NULL;

extern int init (void)
{
    demeter_conf = read_conf();
    if (demeter_conf == NULL)
        return SLURM_ERROR;
    info("%s loaded", plugin_name);
    return SLURM_SUCCESS;
}

extern int fini (void)
{
    free_cgroup(cgroup_data);
    free_job_id_info(task_info);
    free_conf(demeter_conf);
    return SLURM_SUCCESS;
}

extern int task_p_post_term (stepd_step_rec_t *job, stepd_step_task_info_t *task)
{
    if ( !demeter_conf || (demeter_conf && !demeter_conf->using_task_plugin)) {
        free_job_id_info(task_info);
        if (demeter_conf)
            write_log_to_file(demeter_conf,"task plugin not used", INFO, 0);
        return SLURM_SUCCESS;
    }
    write_log_to_file(demeter_conf,"task plugin used", INFO, 0);
    // sstat_pull(job->array_job_id,  job->step_id.step_id, demeter_conf);
    if (!(task_info = get_task_info(job)))
        return SLURM_ERROR;
    if (!(cgroup_data = gather_cgroup(task_info, demeter_conf)))
        return SLURM_ERROR;
    transfer_log_cgroup(cgroup_data, task_info, demeter_conf);
    free_cgroup(cgroup_data);
    free_job_id_info(task_info);
    return SLURM_SUCCESS;
}

// UNUSED
//___________________________________________________________________________________________________________________________________________

extern int task_p_slurmd_batch_request (batch_job_launch_msg_t *req)
{
    return SLURM_SUCCESS;
}

extern int task_p_slurmd_launch_request (launch_tasks_request_msg_t *req, uint32_t node_id)
{
    return SLURM_SUCCESS;
}

extern int task_p_slurmd_suspend_job (uint32_t job_id)
{
    return SLURM_SUCCESS;
}

extern int task_p_slurmd_resume_job (uint32_t job_id)
{
    return SLURM_SUCCESS;
}

extern int task_p_pre_setuid (stepd_step_rec_t *job)
{
    return SLURM_SUCCESS;
}

extern int task_p_pre_launch (stepd_step_rec_t *job)
{
    return SLURM_SUCCESS;
}

extern int task_p_pre_set_affinity(stepd_step_rec_t *job, uint32_t node_tid)
{
    return SLURM_SUCCESS;
}

extern int task_p_set_affinity(stepd_step_rec_t *job, uint32_t node_tid)
{
    return SLURM_SUCCESS;
}

extern int task_p_post_set_affinity(stepd_step_rec_t *job, uint32_t node_tid)
{
    return SLURM_SUCCESS;
}

extern int task_p_add_pid (pid_t pid)
{
    return SLURM_SUCCESS;
}

extern int task_p_post_step (stepd_step_rec_t *job)
{
    return SLURM_SUCCESS;
}